import threading
import math

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import rclpy.executors


import TstML
import TstML.Executor
from nav2_msgs.action import NavigateToPose
from nav2_msgs.msg import SpeedLimit 
import ament_index_python
from nav_msgs.msg import Odometry

from rclpy.callback_groups import ReentrantCallbackGroup


class SpeedLimitPublisher(Node):

    def __init__(self,max_speed):
        super().__init__('SpeedLimit_publisher')
        self.max_speed = int(max_speed)
        self.publisher_ = self.create_publisher(SpeedLimit, '/speed_limit', self.max_speed)
        msg = SpeedLimit()
        msg.speed_limit = float(self.max_speed)
        msg.percentage= False
        self.publisher_.publish(msg)

    


# Ugly hack to get a new name for each node
ros_name_counter = 0
def gen_name(name):
    global ros_name_counter
    ros_name_counter += 1
    return name + str(ros_name_counter)



class ExploreExecutor(TstML.Executor.AbstractNodeExecutor):

  def listener_callback(self, msg):
    if self.first:
        if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "radius"):
          self.radius = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "radius")
        if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "a"):
          self.a = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "a")
        if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "b"):
          self.b = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "b")

        self.current_x   = msg.pose.pose.position.x
        self.current_y   = msg.pose.pose.position.y
        self.goal_msg = NavigateToPose.Goal() # Explore goal?
        self.goal_msg.pose.header.frame_id = "map" #frame id was added, since it needs the reference

        self.r = self.a + self.b*self.theta 
        self.goal_msg.pose.pose.position.x = self.current_x + (self.r + math.cos(self.theta ))
        self.goal_msg.pose.pose.position.y = self.current_y + (self.r + math.sin(self.theta ))
        self.goal_msg.pose.pose.position.z = 1.0
    
        self._send_goal_future = self._action_client.send_goal_async(self.goal_msg, self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)   
        self.first = False


  def __init__(self, node, context):
    print("Init explore.py")
    super(TstML.Executor.AbstractNodeExecutor, self).__init__(node,context)
    self.first = True
    self.a = 0
    self.b = 0
    self.x = 0
    self.y = 0
    self.r = 0
    self.current_x = 0
    self.current_y = 0
    self.first_it = True
    self.time_spent = 0.0
    self.time_travelled = 0
    self.distance_travelled = 0.0

    # Next step
    heading = 0.7
    max_speed = 2.0
    self.theta = 0

    self.ros_node = Node(gen_name("explore"))
    # Here?
    self.subscription = self.ros_node.create_subscription(Odometry,'/odom',self.listener_callback, 10)
    self.subscription 
    
    self._action_client = ActionClient(self.ros_node, NavigateToPose, 'navigate_to_pose')
    self.executor = rclpy.executors.MultiThreadedExecutor()
    self.executor.add_node(self.ros_node)
    

    self.thread = threading.Thread(target=self.executor.spin)
    self.thread.start()

  def finalise(self):
    self.executor.shutdown()
  

  def start(self):
    print("Start explore.py")   
    self.speed_node = SpeedLimitPublisher(max_speed=10)
    self.executor.add_node(self.speed_node)
    
  
    
    # Calc arch spiral
    
    return TstML.Executor.ExecutionStatus.Started()

  def feedback_callback(self, feedback_msg):
    self.x = feedback_msg.feedback.current_pose.pose.position.x
    self.y = feedback_msg.feedback.current_pose.pose.position.y
    self.time = feedback_msg.feedback.current_pose.header.stamp.sec
    if(self.first_it):
        self.prev_time = self.time
        self.prev_x = self.x
        self.prev_y = self.y
        self.first_it = False

    elif self.prev_time < self.time:
        self.distance_travelled += math.sqrt(((abs(self.x-self.prev_x))**2) +((abs(self.y-self.prev_y))**2))
        self.prev_time = self.time
        self.prev_x = self.x
        self.prev_y = self.y
        if(self.distance_travelled < 6.0):
            self.time_travelled += 1
            if self.time_travelled > 30:
                print("The robot got STUCK")
                self.distance_travelled = 0.0
                self.time_travelled = 0
                self._goal_handle.cancel_goal_async()
        else:
            self.distance_travelled = 0.0
            self.time_travelled = 0

  def goal_response_callback(self, future):
    self._goal_handle = future.result()
    if not self._goal_handle.accepted:
      self.executionFinished(TstML.Executor.ExecutionStatus.Aborted())
      self.ros_node.get_logger().error('Goal rejected :(')
    else:
      self.ros_node.get_logger().error('Goal accepted :)')

      self._get_result_future = self._goal_handle.get_result_async()
      self._get_result_future.add_done_callback(self.handle_result_callback)


  def handle_result_callback(self, future):
    if self.r < 6: #self.radoi
      self.theta += math.pi/4
      # New goals not correct
      self.r = self.a + self.b*self.theta 
      self.goal_msg.pose.pose.position.x = self.current_x + (self.r * math.cos(self.theta ))
      self.goal_msg.pose.pose.position.y = self.current_y + (self.r * math.sin(self.theta ))
      self.goal_msg.pose.pose.position.z = 1.0 
      

      self._send_goal_future = self._action_client.send_goal_async(self.goal_msg, self.feedback_callback)
      self._send_goal_future.add_done_callback(self.goal_response_callback)

    else:
      self.executionFinished(TstML.Executor.ExecutionStatus.Finished())

  def pause(self):
    self.ros_node.get_logger().info('Pause is not possible.')
    return TstML.Executor.ExecutionStatus.Running()

  def resume(self):
    return TstML.Executor.ExecutionStatus.Running()

  def stop(self):
    self._goal_handle.cancel_goal()
    return TstML.Executor.ExecutionStatus.Finished()
    
  def abort(self):
    self._goal_handle.cancel_goal()
    return TstML.Executor.ExecutionStatus.Aborted()

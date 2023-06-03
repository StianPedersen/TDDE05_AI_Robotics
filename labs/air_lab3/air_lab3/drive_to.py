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

class DriveToExecutor(TstML.Executor.AbstractNodeExecutor):
  def __init__(self, node, context):
    super(TstML.Executor.AbstractNodeExecutor, self).__init__(node,context)

    self.ros_node = Node(gen_name("drive_to"))
    self._action_client = ActionClient(self.ros_node, NavigateToPose, 'navigate_to_pose')#Change 'drive_to' to 'navigate_to_pose' since we are calling the action.


    self.executor = rclpy.executors.MultiThreadedExecutor()
    self.executor.add_node(self.ros_node)
    self.thread = threading.Thread(target=self.executor.spin)
    self.thread.start()

  def finalise(self):
    self.executor.shutdown()
  

  def start(self):
    goal_msg = NavigateToPose.Goal()
    goal_msg.pose.header.frame_id = "map"#frame id was added, since it needs the reference
    heading = 0
    max_speed = 0

    if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "p"):
        p = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "p")
        print("In first p if: ", p["x"], p["y"], p["z"])
        
    # Only init code executed in SpeedLimitPublisher
    # Can do everything instead of instantiating a class ASK
    self.speed_node = SpeedLimitPublisher(max_speed=10)


    
    # When sending these the NavigateToPose goal msg is malformed ASK
    goal_msg.pose.pose.position.x = float(p["x"])
    goal_msg.pose.pose.position.y = float(p["y"])
    goal_msg.pose.pose.position.z = float(p["z"]) 
 
    self.first_it = True
    self.time_spent = 0.0
    self.time_travelled = 0
    self.distance_travelled = 0.0


    # When sedning error is recieved in rviz
    self._send_goal_future = self._action_client.send_goal_async(goal_msg, self.feedback_callback)
    self._send_goal_future.add_done_callback(self.goal_response_callback)
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
            if self.time_travelled > 50:
                self.distance_travelled = 0.0
                self.time_travelled = 0
                print("STUCK?")
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
    print("Finished!")
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

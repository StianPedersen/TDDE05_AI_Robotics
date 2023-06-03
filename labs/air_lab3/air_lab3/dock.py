import threading
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import rclpy.executors

import TstML
import TstML.Executor

from irobot_create_msgs.action import DockServo

import ament_index_python

# Ugly hack to get a new name for each node
ros_name_counter = 0
def gen_name(name):
    global ros_name_counter
    ros_name_counter += 1
    return name + str(ros_name_counter)

class DockExecutor(TstML.Executor.AbstractNodeExecutor):
  def __init__(self, node, context):
    super(TstML.Executor.AbstractNodeExecutor, self).__init__(node,context)
    self.ros_node = Node(gen_name("dock_node"))
    self._action_client = ActionClient(self.ros_node, DockServo, 'dock')
    self.executor = rclpy.executors.MultiThreadedExecutor()
    self.executor.add_node(self.ros_node)
    self.thread = threading.Thread(target=self.executor.spin)
    self.thread.start()

  def finalise(self):
    self.executor.shutdown()

  def start(self):
    goal_msg = DockServo.Goal()
    self._send_goal_future = self._action_client.send_goal_async(goal_msg, self.feedback_callback)
    self._send_goal_future.add_done_callback(self.goal_response_callback)
    return TstML.Executor.ExecutionStatus.Started()

  def feedback_callback(self, feedback_msg):

    print(feedback_msg.feedback)

  def goal_response_callback(self, future):
    print("in goal response thingy")
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

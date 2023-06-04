import rclpy
import math
from rclpy.action import ActionClient
from rclpy.node import Node
import random


from nav2_msgs.action import NavigateToPose

class RandomExploration(Node):

    def __init__(self):
        super().__init__('random_exploration')
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
 
    def send_goal(self, x, y, angle):
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = "map"
        goal_msg.pose.pose.position.x = x
        goal_msg.pose.pose.position.y = y
        goal_msg.pose.pose.orientation.w = math.cos(angle/2)
        goal_msg.pose.pose.orientation.z = math.sin(angle/2)
        
        self.first_it = True
        self.time_spent = 0.0
        self.time_travelled = 0
        self.distance_travelled = 0.0

        self._action_client.wait_for_server()
        print("Goal recieved:",x,y)
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        self._goal_handle = future.result()
        if not self._goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')
        self._get_result_future = self._goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        self.send_goal(float(random.randrange(-10,10)),float(random.randrange(-10,10)),0.0)


    def feedback_callback(self, feedback_msg):
        # print(feedback_msg.feedback)
        # self.get_logger().info('Received feedback: {0}'.format(feedback_msg.feedback.current_pose))
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
            if(self.distance_travelled < 1.0):
                self.time_travelled += 1
                if self.time_travelled > 9:
                    self.distance_travelled = 0.0
                    self.time_travelled = 0
                    print("STUCK")
                    self._goal_handle.cancel_goal_async()
            else:
                self.distance_travelled = 0.0
                self.time_travelled = 0


            
        

def main(args=None):
    rclpy.init(args=args)
    action_client = RandomExploration()
    action_client.send_goal(4.0, 0.0, 1.0)
    rclpy.spin(action_client)


if __name__ == '__main__':
    main()

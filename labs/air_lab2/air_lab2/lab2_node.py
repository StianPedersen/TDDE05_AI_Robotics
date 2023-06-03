import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

from math import sqrt


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('nodelab2')
        self.declare_parameter('linear', 0.0)
        self.declare_parameter('angular',0.0)
        self.declare_parameter('distance',0.0)
        self.distance_max = self.get_parameter('distance')

        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)        

        self.current_distance_traveled = 0
        self.prev_x = 0
        self.prev_y = 0
        self.init_first = True
        self.subscription = self.create_subscription(Odometry,'/odom',self.listener_callback, 10) 
        self.subscription  # prevent unused variable warning

    def timer_callback(self):
        msg_data = Twist() 
        msg_data.linear.x = self.get_parameter('linear').value
        msg_data.angular.z = self.get_parameter('angular').value
        self.publisher_.publish(msg_data)
        

    def listener_callback(self, msg):   
        if self.init_first:
            self.prev_x = msg.pose.pose.position.x
            self.prev_y = msg.pose.pose.position.y
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y

        dx = x - self.prev_x
        dy = y - self.prev_y

        distance_traveled = sqrt((dx*dx)+(dy*dy))
        self.current_distance_traveled += distance_traveled
        self.get_logger().info('Distance traveled: "%s"' % str(self.current_distance_traveled))

        if(self.current_distance_traveled >= self.distance_max.value):
            exit()

        self.prev_x = msg.pose.pose.position.x
        self.prev_y = msg.pose.pose.position.y
        self.init_first = False
        # From this we can exit
        
       

    


def main(args=None):
    rclpy.init(args=args)

    node_lab2 = MinimalPublisher()

    rclpy.spin(node_lab2)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)

    node_lab2.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


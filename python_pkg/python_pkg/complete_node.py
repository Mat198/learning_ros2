#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class PythonCompleteNode(Node):

    def __init__(self):
        super().__init__("py_node")
        self.get_logger().info("Hello ROS 2")
        self.counter = 0
        
        # Publisher
        self.publisher = self.create_publisher(
            String, "/string", 10
        )
        
        # Subscriber
        self.subscriber = self.create_subscription(
            String, "/string", self.subscriber_callback,10
        )
        
        # Timer
        self.create_timer(0.5, self.publish_string)
        self.create_timer(1.0, self.timer_callback)

        self.get_logger().info("Complete Python Node started!")
        
    def publish_string(self):
        msg = String()
        msg.data = "String message!"
        self.publisher.publish(msg)

    def subscriber_callback(self, message):
        self.get_logger().info("Received msg: " + str(message.data))


    def timer_callback(self):
        self.counter += 1
        self.get_logger().info("Hello: " + str(self.counter))



def main(args=None):
    rclpy.init(args=args)
    node = PythonCompleteNode()
    rclpy.spin(node)
    rclpy.shutdown()

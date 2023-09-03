#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class PythonNode(Node):

    def __init__(self):
        super().__init__("py_node")
        self.get_logger().info("Hello ROS 2")
        self.counter = 0
        self.create_timer(0.5, self.timer_callback)
    
    def timer_callback(self):
        self.counter += 1
        self.get_logger().info("Hello: " + str(self.counter))

def main(args=None):
    rclpy.init(args=args)
    node = PythonNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
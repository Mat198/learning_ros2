#include "rclcpp/rclcpp.hpp"

int main(int argc, char** argv){
    rclcpp::init(argc,argv);
    auto my_node = std::make_shared<rclcpp::Node>("ros2_node");
    rclcpp::spin(my_node);
    rclcpp::shutdown();
    return 0;    
}
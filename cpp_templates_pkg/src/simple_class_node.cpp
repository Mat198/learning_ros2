#include "rclcpp/rclcpp.hpp"

class SimpleClassNode: public rclcpp::Node {

private:
    
public:
    
    // Node constructor
    SimpleClassNode();

    // Destructor is not needed.
};

SimpleClassNode::SimpleClassNode() : Node("node_name")
{
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleClassNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
#include "rclcpp/rclcpp.hpp"

class CppNode:  public rclcpp::Node 
{
public:
    CppNode(): Node("class_cpp_node"){
        RCLCPP_INFO(this->get_logger(),"Hello C++ Node");
        timer = this->create_wall_timer(std::chrono::seconds(1),
            std::bind(&CppNode::timerCallback, this)
        );

    }
    ~CppNode(){};

private:

    void timerCallback(){
        counter++;
        RCLCPP_INFO_STREAM(this->get_logger(), "Hello: " << counter);
    }

    rclcpp::TimerBase::SharedPtr timer;
    int counter = 0;

};



int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CppNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
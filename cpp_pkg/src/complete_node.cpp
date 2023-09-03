#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class CompleteCppNode:  public rclcpp::Node 
{

    using StringMsg = example_interfaces::msg::String;

public:
    CompleteCppNode(): Node("class_cpp_node"){
        RCLCPP_INFO(this->get_logger(),"Hello C++ Node");
        
        timer = this->create_wall_timer(std::chrono::seconds(1),
            std::bind(&CompleteCppNode::timerCallback, this)
        );

        publishTimer = this->create_wall_timer(std::chrono::seconds(1),
            std::bind(&CompleteCppNode::publishString, this)
        );

        publisher = this->create_publisher<StringMsg>("/sendString",10);

        using namespace std::placeholders;
        subscriber = this->create_subscription<StringMsg>(
            "/receiveString",10, 
            std::bind(&CompleteCppNode::subscriberString, this, _1)
        );

    }
    ~CompleteCppNode(){};

private:

    void publishString(){
        auto msg = StringMsg();
        msg.data = "String message!";
        publisher->publish(msg);
    }

    void subscriberString(const StringMsg::SharedPtr msg){
        RCLCPP_INFO_STREAM(this->get_logger(),
            "Data received: " << msg->data
        );
    }

    void timerCallback(){
        counter++;
        RCLCPP_INFO_STREAM(this->get_logger(), "Hello: " << counter);
    }

    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::TimerBase::SharedPtr publishTimer;
    rclcpp::Publisher<StringMsg>::SharedPtr publisher;
    rclcpp::Subscription<StringMsg>::SharedPtr subscriber;
    int counter = 0;

};



int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CompleteCppNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
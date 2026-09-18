#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "my_robot_interfaces/srv/reset_counter.hpp"

using namespace std::placeholders;
//Since we will need to use the service interface quite often, adding this using line is a best practice to keep things simple.
using ResetCounter = my_robot_interfaces::srv::ResetCounter;

class NumberCounterNode : public rclcpp::Node
{
public:
    rclcpp::Service<ResetCounter>::SharedPtr reset_counter_service_;
    NumberCounterNode() : Node("number_counter"), counter_(0)
    {
        number_subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
                "number", 10, std::bind(&NumberCounterNode::callbackNumber, this, _1));
            
        RCLCPP_INFO(this->get_logger(), "Number Counter has been started.");
    }

private:
    void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        counter_ += msg->data;
        RCLCPP_INFO(this->get_logger(), "Counter: %d", counter_);
    }
    void callbackResetCounter(const ResetCounter::Request::SharedPtr request, const ResetCounter::Response::SharedPtr response)
    {
    if (request->reset_value < 0) {
        response->success = false;
               response->message = "Cannot reset counter to a negative value";
    }
    else if (request->reset_value > counter_) {
        response->success = false;
        response->message = "Reset value must be lower than current counter value";
    }
    else {
        counter_ = request->reset_value;
        RCLCPP_INFO(this->get_logger(), "Reset counter to %d", counter_);
        response->success = true;
        response->message = "Success";
        }
    }

    int counter_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr number_subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
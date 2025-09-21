#include "sample_ros2_pkg/simple_node.hpp"

SimpleNode::SimpleNode()
: Node("simple_node")
{

    // Initialization
    initializePublishers();
    initializeSubscribers();

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        [this]() {
            RCLCPP_DEBUG(this->get_logger(), "Hello from simple_node!");

            std_msgs::msg::String message;
            message.data = "Hello from simple_node!  Published by sample_pub_";
            sample_pub_->publish(message);
        });
}

void SimpleNode::initializePublishers()
{
    sample_pub_ = this->create_publisher<std_msgs::msg::String>("/sample_topic_1", 10);
}

void SimpleNode::initializeSubscribers()
{
    sample_sub_ = this->create_subscription<std_msgs::msg::String>(
        "/sample_topic_1", 10,
        [this](const std_msgs::msg::String::SharedPtr msg) {
            sample_topic_callback(msg);
        });
}

void SimpleNode::sample_topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received message: '%s'", msg->data.c_str());
}

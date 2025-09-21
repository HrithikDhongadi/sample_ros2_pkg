#ifndef SIMPLE_NODE_HPP
#define SIMPLE_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SimpleNode : public rclcpp::Node
{
public:
    SimpleNode();

private:

    /********************************************************************
     * ROS2 Subscribers with callback and message declaration
     *******************************************************************/
    /// @brief Initializes ROS2 Subscribers.
    ///
    /// @pre ROS node and nodehandle should be initialized
    /// @pre Declaration of rclcpp::Subscriber calls objects
    /// @pre Declaration of subscriber callback function
    ///
    /// @return Void
    ///
    void initializeSubscribers();

    /// @brief Sample Topic 1 Subscriber
    /// @param Topic "/sample_topic_1"
    ///
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sample_sub_;

    /// @brief Callback for Sample Topic 1 Subscriber
    /// @param msg std_msgs::msg::String
    ///
    void sample_topic_callback(const std_msgs::msg::String::SharedPtr msg);

    /*******************************************************************
     * ROS2 Publishers declaration
     ******************************************************************/
    
    void initializePublishers();

    /// @brief  Sample Topic 1 Publisher
    /// @param Topic "/sample_topic_1"
    ///
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr sample_pub_;


    /// Private Variables
    rclcpp::TimerBase::SharedPtr timer_;

};

#endif  // SAMPLE_ROS2_PKG__SIMPLE_NODE_HPP_

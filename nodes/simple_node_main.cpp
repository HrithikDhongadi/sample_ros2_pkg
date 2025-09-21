/**
 * @file   simple_ros2_node.cpp
 * @brief  ROS 2 Node Initialization
 * @author Your Name
 * @date   2025-08-08
 * *****************************************************************/

// Import SimpleNode class declaration header
#include "sample_ros2_pkg/simple_node.hpp"

/// @brief Initializes ROS 2 node and object of class SimpleNode.
///
/// @param argc Accept remapping arguments from command line
/// @param argv Accept remapping arguments from command line
/// @return 0 on termination of main function
///
/// @details
/// Initializes "simple_ros2_node", sets logger level, then creates
/// an rclcpp Node by instantiating the SimpleNode class. Spins
/// the node to process callbacks until shutdown.
///
int main(int argc, char * argv[])
{
    // Initialize ROS 2
    rclcpp::init(argc, argv);

    // Instantiate SimpleNode class object
    auto node = std::make_shared<SimpleNode>();

    // Set this node's logger level here ('debug', 'info', 'warn', 'error', 'fatal')
    node->get_logger().set_level(rclcpp::Logger::Level::Debug);

    RCLCPP_DEBUG(node->get_logger(), "Logger level set to DEBUG");

    // Spin node for callbacks
    rclcpp::spin(node);

    // Shutdown ROS 2
    rclcpp::shutdown();

    return 0;
}

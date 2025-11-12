#ifndef OPENNAV_DOCKING_CORE__WIGGLER_HPP_
#define OPENNAV_DOCKING_CORE__WIGGLER_HPP_

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_publisher.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "tf2_ros/buffer.h"

namespace opennav_docking_core
{

class Wiggler
{
public:
  virtual ~Wiggler() {}

  virtual void  configure(
    const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
    const std::string & name,
    std::shared_ptr<tf2_ros::Buffer> tf,
    rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::Twist>::SharedPtr vel_publisher) = 0;

  virtual void cleanup() = 0;

  virtual void activate() = 0;

  virtual void deactivate() = 0;

  virtual void wiggle() = 0;

};
} // namespace opennav_docking_core

#endif  // OPENNAV_DOCKING_CORE__WIGGLER_HPP_

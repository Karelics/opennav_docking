#ifndef OPENNAV_DOCKING__ROTATE_IN_PLACE_WIGGLER_HPP_
#define OPENNAV_DOCKING__ROTATE_IN_PLACE_WIGGLER_HPP_

#include <memory>

#include "opennav_docking_core/wiggler.hpp"

namespace opennav_docking
{

class RotateInPlaceWiggler : public opennav_docking_core::Wiggler
{
public:

  RotateInPlaceWiggler()
  : Wiggler()
  {}

  virtual void configure(
    const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
    const std::string & name,
    std::shared_ptr<tf2_ros::Buffer> tf,
    rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::Twist>::SharedPtr vel_publisher) override;

  virtual void cleanup() override {};

  virtual void activate() override {};

  virtual void deactivate() override {};

  virtual void wiggle() override;

private:
std::string name_;
rclcpp_lifecycle::LifecycleNode::SharedPtr node_;
std::shared_ptr<tf2_ros::Buffer> tf2_buffer_;
rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::Twist>::SharedPtr vel_publisher_;
};
}  // namespace opennav_docking

#endif  // OPENNAV_DOCKING__ROTATE_IN_PLACE_WIGGLER_HPP_
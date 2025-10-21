#include "nav2_util/node_utils.hpp"
#include "opennav_docking/rotate_in_place_wiggler.hpp"

namespace opennav_docking
{

void RotateInPlaceWiggler::configure(
  const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
  const std::string & name,
  std::shared_ptr<tf2_ros::Buffer> tf,
  rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::Twist>::SharedPtr vel_publisher)
{
  node_ = parent.lock();
  if (!node_) {
    throw std::runtime_error{"Failed to lock node"};
  }
  tf2_buffer_ = tf;
  vel_publisher_ = vel_publisher;
  name_ = name;

  nav2_util::declare_parameter_if_not_declared(
    node_, name + ".angular_velocity", rclcpp::ParameterValue(0.3));
}

void RotateInPlaceWiggler::wiggle()
{
  auto command = std::make_unique<geometry_msgs::msg::Twist>();
  double angular_velocity;
  node_->get_parameter(name_ + ".angular_velocity", angular_velocity);
  command->angular.z = angular_velocity;

  RCLCPP_INFO(node_->get_logger(), "Wiggling with angular velocity: %.2f", angular_velocity);
  vel_publisher_->publish(std::move(command));
}
}

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(opennav_docking::RotateInPlaceWiggler, opennav_docking_core::Wiggler)

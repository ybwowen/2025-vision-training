#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/divide_with_remainder.hpp"                                        // CHANGE

#include <memory>

/*
int32 dividend
int32 divisor
---
int32 quotient
int32 remainder
*/


void divide(const std::shared_ptr<tutorial_interfaces::srv::DivideWithRemainder::Request> request,     // CHANGE
          std::shared_ptr<tutorial_interfaces::srv::DivideWithRemainder::Response>       response)  // CHANGE
{
  response->quotient = request->dividend/request->divisor;
  response->remainder = request->dividend%request->divisor;;
                                       
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\ndividend: %d ""divisor: %d",  // CHANGE
                request->dividend, request->divisor);                                         // CHANGE
RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
            "sending back response: quotient [%ld], remainder [%ld]", 
            (long int)response->quotient, 
            (long int)response->remainder);}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("divide_with_remainder_server");   // CHANGE

  rclcpp::Service<tutorial_interfaces::srv::DivideWithRemainder>::SharedPtr service =               // CHANGE
    node->create_service<tutorial_interfaces::srv::DivideWithRemainder>("divide_with_remainder",  &divide);   // CHANGE

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to divide with remainder.");                     // CHANGE

  rclcpp::spin(node);
  rclcpp::shutdown();
}
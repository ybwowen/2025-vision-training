#include "division/srv/DivideInt.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>

using DivideInt = division::srv::Divideint;
using namespace std::chrono_literals;

class DivisionClient : public rclcpp::Node {
public:
  DivisionClient() : Node("division_client") {
    client_ = this->create_client<DivideInt>("divide_two_ints");
  }

  void send_request(int64_t a, int64_t b) {
    auto request = std::make_shared<DivideInt::Request>();
    request->a = a;
    request->b = b;

    auto result = client_->async_send_request(request);
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(),
                                           result) ==
        rclcpp::FutureReturnCode::SUCCESS) {
      auto response = result.get();
      RCLCPP_INFO(this->get_logger(), "Response: q=%ld, r=%ld", response->q,
                  response->r);
    } else {
      RCLCPP_ERROR(this->get_logger(), "Fail");
    }
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<DivisionClient>();

  int64_t a = std::stoll(argv[1]);
  int64_t b = std::stoll(argv[2]);

  node->send_request(a, b);
  rclcpp::shutdown();
  return 0;
}

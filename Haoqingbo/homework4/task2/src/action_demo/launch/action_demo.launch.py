from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_description():
    action_robot_node = Node(
        package="action_demo",
        executable="action_robot",
        parameters=["./src/action_demo/config/action_demo.yaml"]
    )
    action_control_node = Node(
        package="action_demo",
        executable="action_control",
        parameters=["./src/action_demo/config/action_demo.yaml"]
    )
    launch_description = LaunchDescription([action_robot_node,action_control_node])
    return launch_description
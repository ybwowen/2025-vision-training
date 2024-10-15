from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    node_svr = Node(
        package="div_service",
        executable="div_server"
    )
    node_clt = Node(
        package="div_service",
        executable="div_client",
        arguments=["514", "114"]
    )
    
    launch_description = LaunchDescription(
        [node_svr, node_clt])
    # 返回让ROS2根据launch描述执行节点
    return launch_description

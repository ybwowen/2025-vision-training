from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    move_service_dir = get_package_share_directory('move_service')
    param_file = os.path.join(move_service_dir, 'config', 'params.yaml')

    node_svr = Node(
        package="move_service",
        executable="move_server",
        parameters = [param_file]
    )
    node_clt = Node(
        package="move_service",
        executable="move_client",
        parameters = [param_file]
    )
    
    launch_description = LaunchDescription(
        [node_svr, node_clt])
    # 返回让ROS2根据launch描述执行节点
    return launch_description

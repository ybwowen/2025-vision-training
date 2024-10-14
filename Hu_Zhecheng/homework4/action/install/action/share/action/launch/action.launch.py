import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """launch内容描述函数，由ros2 launch 扫描调用"""
    config = os.path.join(
        get_package_share_directory('action'),
        'config',
        'param.yaml'
    )
    action_cli = Node(
        package="action",
        executable="action_cli",
        parameters=[config]
    )
    action_srv = Node(
        package="action",
        executable="action_srv",
        parameters=[config]
    )
    # 创建LaunchDescription对象launch_description,用于描述launch文件
    launch_description = LaunchDescription(
        [action_cli, action_srv])
    # 返回让ROS2根据launch描述执行节点
    return launch_description
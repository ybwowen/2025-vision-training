from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare 
import os

def generate_launch_description():
    package_name = 'robot_action'
    package_path = FindPackageShare(package_name).find(package_name)

    param_file = os.path.join(package_path, 'config', 'param.yaml')

    return LaunchDescription([
        Node(
            package=package_name,
            executable='server',
            parameters=[param_file]
        ),
        Node(
            package=package_name,
            executable='client',
            parameters=[param_file]
        )
    ])

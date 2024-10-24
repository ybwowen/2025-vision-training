import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='action_tutorial',
            executable='action_server',
            name='action_server',
            output='screen',
            parameters=['/path/to/config/params.yaml']
        ),
        Node(
            package='action_tutorial',
            executable='action_client',
            name='action_client',
            output='screen',
            parameters=['/path/to/config/params.yaml']
        ),
    ])

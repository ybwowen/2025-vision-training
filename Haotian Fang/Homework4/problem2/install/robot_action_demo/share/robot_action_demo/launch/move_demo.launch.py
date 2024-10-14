from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot_action_demo',
            executable='move_action_server',
            name='move_action_server',
            output='screen',
            parameters=[{'v': 1.0, 'time_limit': 10.0}]
        ),
        Node(
            package='robot_action_demo',
            executable='move_action_client',
            name='move_action_client',
            output='screen',
            parameters=[{'s': 10.0}]
        )
    ])
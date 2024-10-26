from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    params_file = os.path.join(
        os.path.dirname(__file__),
        'params',
        'params.yaml'
    )

    return LaunchDescription([
        Node(
            package='action_service',
            executable='action_server',
            name='action_server',
            parameters=[params_file]
        ),
        Node(
            package='action_service',
            executable='action_client',
            name='action_client'
        )
    ])
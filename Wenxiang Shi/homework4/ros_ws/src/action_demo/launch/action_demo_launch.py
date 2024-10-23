from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'param_file',
            default_value='src/action_demo/params.yaml',
            description='Path to the parameter file to use'
        ),
        Node(
            package='action_demo',
            executable='server',
            name='action_server',
            output='screen',
            parameters=[LaunchConfiguration('param_file')]
        ),
        Node(
            package='action_demo',
            executable='client',
            name='action_client',
            output='screen'
        ),
    ])

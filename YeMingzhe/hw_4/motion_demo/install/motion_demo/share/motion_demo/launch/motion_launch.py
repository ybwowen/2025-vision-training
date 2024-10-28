from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'params_file',
            default_value='config/params.yaml',
            description='Full path to the parameter file to load'
        ),
        Node(
            package='motion_demo',
            executable='motion_server',
            name='motion_server',
            parameters=[LaunchConfiguration('params_file')]
        ),
        Node(
            package='motion_demo',
            executable='motion_client',
            name='motion_client',
            parameters=[LaunchConfiguration('params_file')]
        ),
    ])

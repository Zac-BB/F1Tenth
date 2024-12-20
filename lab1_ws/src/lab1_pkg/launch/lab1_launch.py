from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='lab1_pkg_cpp',
            executable='talker',
            name='talkerNode'
        ),
        Node(
            package='lab1_pkg_cpp',
            executable='relay',
            name='relayNode'
        ),
        
    ])
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='lab1_pkg',
            executable='talker',
            name='talker',
            output='screen'
        ),
        # Node(
        #     package='lab3',
        #     executable='python_node.py',
        #     name='python_node',
        #     output='screen'
        # ),
    ])
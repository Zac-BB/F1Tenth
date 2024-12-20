from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='lab1_pkg',
            executable='talker',
            name='talkerNode',
            parameters=[
                {"v" : 3.0},
                {"d" : 5.0}
            ]
        ),
        Node(
            package='lab1_pkg',
            executable='relay',
            name='relayNode'
        ),
        
    ])
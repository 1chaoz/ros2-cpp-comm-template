from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='comm_demo',
            executable='comm_demo_node',
            name='publisher_node',
            arguments=['publisher'],
            output='screen',
        ),
        Node(
            package='comm_demo',
            executable='comm_demo_node',
            name='subscriber_node',
            arguments=['subscriber'],
            output='screen',
        ),
        Node(
            package='comm_demo',
            executable='comm_demo_node',
            name='service_server_node',
            arguments=['service_server'],
            output='screen',
        ),
    ])

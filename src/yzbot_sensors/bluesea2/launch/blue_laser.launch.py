#!/usr/bin/python3

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import LifecycleNode
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.actions import LogInfo

import lifecycle_msgs.msg
import os

print("启动blue_laser.launch.py")

def generate_launch_description():
    share_dir = get_package_share_directory('bluesea2')
    parameter_file = LaunchConfiguration('laser_params')

    params_declare = DeclareLaunchArgument('laser_params',
                                           default_value=os.path.join(
                                               share_dir, 'params', 'blue_laser.yaml'),
                                           description='FPath to the ROS2 parameters file to use.')

    try:
        driver_node = LifecycleNode( 
            name='bluesea_node', 
            namespace='/', 
            package='bluesea2', 
            executable='bluesea_node', 
            output='screen', 
            emulate_tty=True, 
            parameters=[parameter_file]
        )
    except:
        pass

    # 创建静态变换发布器节点
    static_tf_pub_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        # name='base_link_2_laser_link_ls',
        arguments=['0', '0', '0', '0', '0', '0', '0', 'base_link', 'laser_link']
    )

    return LaunchDescription([
        params_declare,
        driver_node,
        static_tf_pub_node
    ])

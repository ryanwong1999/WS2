import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


print("启动nav2_startup.launch.py")
    
def generate_launch_description():
    yzbot_nav2_dir = get_package_share_directory('yzbot_nav2')
    urdf_dir = get_package_share_directory('yzbot_description')
    stm32_dir = get_package_share_directory('yzbot_stm32connect')
    laser_dir = get_package_share_directory('bluesea2')

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    map_yaml_path = LaunchConfiguration('map',default=os.path.join(yzbot_nav2_dir,'maps','map.yaml'))
    # urdf_model_path = LaunchConfiguration('map',default=os.path.join(urdf_dir,'urdf','yzbot_gazebo.urdf'))
    nav2_param_path = LaunchConfiguration('params_file',default=os.path.join(yzbot_nav2_dir,'param','yzbot.yaml'))
    laser_param_path = LaunchConfiguration('laser_params',default=os.path.join(laser_dir,'params','blue_laser.yaml'))

    rviz_config_dir = os.path.join(yzbot_nav2_dir,'rviz','nav2.rviz')
    urdf_model_path = os.path.join(urdf_dir,'urdf','yzbot_base.urdf')

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time',default_value=use_sim_time,description='Use simulation (Gazebo) clock if true'),
        DeclareLaunchArgument('map',default_value=map_yaml_path,description='Full path to map file to load'),
        DeclareLaunchArgument('params_file',default_value=nav2_param_path,description='Full path to param file to load'),
        DeclareLaunchArgument('laser_params',default_value=laser_param_path,description='bluesea laser param file'),

        # urdf
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([urdf_dir,'/launch','/robot_description.launch.py']),
        ),
        # 蓝海雷达
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([laser_dir,'/launch','/blue_laser.launch.py']),
            launch_arguments={
                'laser_params': laser_param_path}.items(),
        ),
        # stm32通信
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([stm32_dir,'/launch','/stm32_connect.launch.py']),
        ),
        # 定位导航
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([yzbot_nav2_dir,'/launch','/bringup_launch.py']),
            launch_arguments={
                'map': map_yaml_path,
                'use_sim_time': use_sim_time,
                'params_file': nav2_param_path}.items(),
        ),
        # rviz
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config_dir],
            parameters=[{'use_sim_time': use_sim_time}],
            # output='screen'
        ),
    ])

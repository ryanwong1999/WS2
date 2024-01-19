cmake_minimum_required(VERSION 3.5)
project(yzbot_stm32connect)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(yzbot_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

set(serial_SRCS
    src/serial.cc
    include/serial/serial.h
    include/serial/v8stdint.h
)
list(APPEND serial_SRCS src/impl/unix.cc)
list(APPEND serial_SRCS src/impl/list_ports/list_ports_linux.cc)

add_library(serial 
    ${serial_SRCS} 
)

include_directories(include) # 添加项目中的include文件夹路径

add_executable(stm32_connect 
    src/stm32_connect.cpp
    src/robotserial.cpp
    src/plc.cpp
    src/pms.cpp
    src/psc.cpp
)

target_include_directories(stm32_connect PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_compile_features(stm32_connect PUBLIC c_std_99 cxx_std_17) 

ament_target_dependencies(stm32_connect 
    rclcpp
    yzbot_msgs
    geometry_msgs
    nav_msgs
    tf2_msgs
    tf2_ros
)

target_link_libraries(stm32_connect  
    ${catkin_LIBRARIES} 
    serial
)

install(TARGETS serial stm32_connect 
    DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

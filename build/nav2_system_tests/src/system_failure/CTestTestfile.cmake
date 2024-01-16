# CMake generated Testfile for 
# Source directory: /home/kgh/ws2/src/navigation2/nav2_system_tests/src/system_failure
# Build directory: /home/kgh/ws2/build/nav2_system_tests/src/system_failure
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_failure_navigator "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/kgh/ws2/build/nav2_system_tests/test_results/nav2_system_tests/test_failure_navigator.xml" "--package-name" "nav2_system_tests" "--generate-result-on-success" "--env" "TEST_DIR=/home/kgh/ws2/src/navigation2/nav2_system_tests/src/system_failure" "TEST_MAP=/home/kgh/ws2/src/navigation2/nav2_system_tests/maps/map_circular.yaml" "TEST_WORLD=/home/kgh/ws2/src/navigation2/nav2_system_tests/worlds/turtlebot3_ros2_demo.world" "GAZEBO_MODEL_PATH=/home/kgh/ws2/src/navigation2/nav2_system_tests/models" "BT_NAVIGATOR_XML=navigate_w_replanning_and_recovery.xml" "--command" "/home/kgh/ws2/src/navigation2/nav2_system_tests/src/system_failure/test_system_failure_launch.py")
set_tests_properties(test_failure_navigator PROPERTIES  TIMEOUT "180" WORKING_DIRECTORY "/home/kgh/ws2/build/nav2_system_tests/src/system_failure" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/home/kgh/ws2/src/navigation2/nav2_system_tests/src/system_failure/CMakeLists.txt;1;ament_add_test;/home/kgh/ws2/src/navigation2/nav2_system_tests/src/system_failure/CMakeLists.txt;0;")

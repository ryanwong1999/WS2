# CMake generated Testfile for 
# Source directory: /home/kgh/ws2/src/navigation2/nav2_regulated_pure_pursuit_controller/test
# Build directory: /home/kgh/ws2/build/nav2_regulated_pure_pursuit_controller/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_regulated_pp "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/kgh/ws2/build/nav2_regulated_pure_pursuit_controller/test_results/nav2_regulated_pure_pursuit_controller/test_regulated_pp.gtest.xml" "--package-name" "nav2_regulated_pure_pursuit_controller" "--output-file" "/home/kgh/ws2/build/nav2_regulated_pure_pursuit_controller/ament_cmake_gtest/test_regulated_pp.txt" "--command" "/home/kgh/ws2/build/nav2_regulated_pure_pursuit_controller/test/test_regulated_pp" "--gtest_output=xml:/home/kgh/ws2/build/nav2_regulated_pure_pursuit_controller/test_results/nav2_regulated_pure_pursuit_controller/test_regulated_pp.gtest.xml")
set_tests_properties(test_regulated_pp PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/kgh/ws2/build/nav2_regulated_pure_pursuit_controller/test/test_regulated_pp" TIMEOUT "60" WORKING_DIRECTORY "/home/kgh/ws2/build/nav2_regulated_pure_pursuit_controller/test" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/foxy/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/kgh/ws2/src/navigation2/nav2_regulated_pure_pursuit_controller/test/CMakeLists.txt;2;ament_add_gtest;/home/kgh/ws2/src/navigation2/nav2_regulated_pure_pursuit_controller/test/CMakeLists.txt;0;")
subdirs("../gtest")

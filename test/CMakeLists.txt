cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# 添加测试可执行文件
add_executable(Test tmain.cpp)
g++ test.cpp -o test -I C:/Program Files (x86)/googletest-distribution/include -lgtest -lgtest_main -pthread
# 链接gtest库
find_package(GTest REQUIRED)
target_link_libraries(test_add GTest::GTest GTest::Main)
# 添加测试
add_test(NAME MyTest COMMAND Test)
set_tests_properties(MyTest PROPERTIES WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test)




cmake_minimum_required (VERSION 3.24.2)

# 项目信息
project (lab2)

# 设置编译器路径
set(CMAKE_C_COMPILER "D:/Mingw-w64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Mingw-w64/mingw64/bin/g++.exe")

# 查找当前目录下的所有源文件和头文件，并将名称保存到 DIR_SRCS 变量  
file(GLOB_RECURSE DIR_SRCS src/*.cpp src/*.h)
#把test.cpp也加入DIR_SRCS 变量里
set(DIR_SRCS1
    ${DIR_SRCS}
    test.cpp
    main.cpp
)

set(DIR_SRCS2
    ${DIR_SRCS}
    test.cpp
)
# 添加可执行文件
add_executable(lab2 test.cpp ${DIR_SRCS1})
# 添加调试信息
set(CMAKE_BUILD_TYPE Debug)
# 将链接选项应用于 lab2 目标
target_link_options(lab2 PRIVATE "-mconsole")

# 查找所有头文件
set(HEADERS
    src\\CommandParser
    src\\ContentsCommand
    src\\FileCommand
    src\\ShowCommand
    src
    src\\tool
)

# 包含 CTest 模块
include(CTest)
add_subdirectory(third-party/gtest)
# 添加测试目标
add_executable(lab2tests
    tests/test1.cpp
    tests/test2.cpp
    ${DIR_SRCS2}
)

# 链接测试目标与你的库/源文件
target_link_libraries(lab2tests PRIVATE)

# 添加测试
add_test(NAME MyTest COMMAND lab2tests)

# 把头文件加入
target_include_directories(lab2 PUBLIC ${HEADERS})
target_include_directories(lab2tests PUBLIC ${HEADERS})

# 链接 gtest 库到 lab2tests
target_link_libraries(lab2tests PRIVATE gtest)
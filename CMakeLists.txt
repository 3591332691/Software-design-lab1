cmake_minimum_required (VERSION 3.24.2)

# 项目信息
project (lab2)

# 设置编译器路径
set(CMAKE_C_COMPILER "D:/Mingw-w64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Mingw-w64/mingw64/bin/g++.exe")

# 查找当前目录下的所有源文件和头文件，并将名称保存到 DIR_SRCS 变量  
file(GLOB_RECURSE DIR_SRCS src/*.cpp src/*.h)
#把test.cpp也加入DIR_SRCS 变量里
set(DIR_SRCS
    ${DIR_SRCS}
    test.cpp
)
# 添加可执行文件
add_executable(lab2 test.cpp ${DIR_SRCS})
#查找所有头文件
set(HEADERS
    src\\CommandParser
    src\\ContentsCommand
    src\\FileCommand
    src\\ShowCommand
    src
    src\\tool
)
#把头文件加入
target_include_directories(lab2 PUBLIC ${HEADERS})
# 添加调试信息
set(CMAKE_BUILD_TYPE Debug)
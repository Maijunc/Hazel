cmake_minimum_required(VERSION 3.24)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

#设置头文件路径
set(INC_DIR ./include)

#设置链接库路径
set(LINK_DIR ./lib)

#引入头文件
include_directories(${INC_DIR})

#引入库文件
link_directories(${LINK_DIR})

add_executable(Sandbox SandboxApp.cpp)

#将第三方库连接在一起
target_link_libraries(Sandbox libHazel.dylib)

cmake_minimum_required(VERSION 3.24)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directories
set(outputdir "${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")

# Add subdirectories for Hazel and Sandbox
add_subdirectory(Hazel)
add_subdirectory(Sandbox)

cmake_minimum_required(VERSION 3.24)
project(Hazel)

set(CMAKE_CXX_STANDARD 17)

add_library(Hazel SHARED Hazel/Application.cpp Hazel/Application.h Hazel.h Hazel/EntryPoint.h)
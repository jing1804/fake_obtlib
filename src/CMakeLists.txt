cmake_minimum_required(VERSION 3.5)
project(fake_obtlib)
add_compile_options(-std=c++11)
add_definitions("-Wall -g")
add_subdirectory(${PROJECT_SOURCE_DIR}/client)
add_subdirectory(${PROJECT_SOURCE_DIR}/server)
add_subdirectory(${PROJECT_SOURCE_DIR}/gtest)

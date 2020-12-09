cmake_minimum_required(VERSION 3.5)
project(client)
add_compile_options(-std=c++11)
add_definitions("-Wall -g")
add_subdirectory(${PROJECT_SOURCE_DIR}/obtlib)
add_executable(client
				main.cpp
)
message("${PROJECT_SOURCE_DIR}/obtlib")
target_include_directories(client
							PUBLIC
							obtlib
)
target_link_libraries(client
						PUBLIC
						RREService
						gtest
						pthread
)

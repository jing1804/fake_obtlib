cmake_minimum_required(VERSION 3.5)
project(obt_test)
add_compile_options(-std=c++11)
add_definitions("-Wall -g")
add_subdirectory(${PROJECT_SOURCE_DIR}/obtlib)
add_executable(obt_test
				main.cpp
)
message("${PROJECT_SOURCE_DIR}/obtlib")
target_include_directories(obt_test
							PUBLIC
							obtlib
)
target_link_libraries(obt_test
						PUBLIC
						RREService
)

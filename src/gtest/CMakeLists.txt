cmake_minimum_required(VERSION 3.1.0)
project(unittest)
add_compile_options(-std=c++11)
add_definitions("-Wall -g")
# Now simply link against gtest or gtest_main as needed. 
add_executable(utest test.cpp 
					${PROJECT_SOURCE_DIR}/../client/obtlib/RREService_api.cpp
					${PROJECT_SOURCE_DIR}/../server/handler.cpp
				#	${PROJECT_SOURCE_DIR}/../server/handler.cpp
				#	${PROJECT_SOURCE_DIR}/../server/udpserver.cpp
)
target_include_directories(utest PUBLIC 
							${PROJECT_SOURCE_DIR}/../client/obtlib/
							${PROJECT_SOURCE_DIR}/../server/
)
target_link_libraries(utest gtest pthread)
#target_link_libraries(utest gtest_main)
enable_testing()

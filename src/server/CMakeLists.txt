cmake_minimum_required(VERSION 3.5)
project(udpserver)


add_executable(udpserver
				main.cpp
				udpserver.cpp
				handler.cpp
)
target_include_directories(udpserver
							PUBLIC
							${PROJECT_SOURCE_DIR}
)

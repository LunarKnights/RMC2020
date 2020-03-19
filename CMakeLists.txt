# Project's name
PROJECT ( LunarKnights C CXX )

# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.1)

add_definitions(-std=c++11)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib) #CMAKE_BINARY_DIR
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package (Threads REQUIRED)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(${PROJECT_NAME} STATIC 
	${PROJECT_SOURCE_DIR}/src/Heartbeat.cpp
	${PROJECT_SOURCE_DIR}/src/comm/Log.cpp
	${PROJECT_SOURCE_DIR}/src/hardware/Motor.cpp
	${PROJECT_SOURCE_DIR}/src/subsystems/Base.cpp
	${PROJECT_SOURCE_DIR}/src/robot.cpp
)

target_link_libraries(LunarKnights ${CMAKE_SOURCE_DIR}/lib/libCTRE_Phoenix.a)
target_link_libraries(LunarKnights ${CMAKE_SOURCE_DIR}/lib/libCTRE_PhoenixCCI.a)
target_link_libraries(LunarKnights ${CMAKE_SOURCE_DIR}/lib/libCTRE_PhoenixPlatformLinuxSocketCan.a)
target_link_libraries(LunarKnights ${CMAKE_SOURCE_DIR}/lib/libCTRE_PhoenixCanutils.a)

target_link_libraries(LunarKnights Threads::Threads)

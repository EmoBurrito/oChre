cmake_minimum_required(VERSION 3.10)

message("PROJECT_VERSION=${PROJECT_VERSION}")
if( PROJECT_VERSION ) 
    message("PROJECT_VERSION evaluates to True")
endif()
project(Ochre VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(src/config.h.in src/config.h)
include_directories(${PROJECT_BINARY_BIN})

add_executable(ochre src/main.cpp src/creature.cpp src/party.cpp)

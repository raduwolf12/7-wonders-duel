cmake_minimum_required(VERSION 3.10)

project(Logging)

# Add the source files for the Logging project
add_library(Logging STATIC Logging.cpp)

target_include_directories(Logging PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

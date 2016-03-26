cmake_minimum_required(VERSION 3.2)
project(Leecodproject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Leecodproject ${SOURCE_FILES} NinetyEight.h NinetySix.h Nineteen.h "284. Peeking Iterator.h")
cmake_minimum_required(VERSION 2.8.4)
project(jhelper-example-project)

# jhelper
add_executable(output tasks/out.cpp)
add_executable(testrunner tasks/test.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "*.hpp" )
ADD_DEFINITIONS(-std=c++14)
add_executable(test ${TASKS} ${HEADERS})

# test
add_subdirectory(test)
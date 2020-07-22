cmake_minimum_required(VERSION 2.8.4)

find_package(GTest REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
add_executable(libtest
        libtest.cpp
        combination_test.hpp
        kruskal_test.hpp)
target_link_libraries(libtest
        PRIVATE
        GTest::GTest
        GTest::Main)
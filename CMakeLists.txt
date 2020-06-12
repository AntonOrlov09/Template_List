cmake_minimum_required(VERSION 3.15)
project(Template_List)

set(CMAKE_CXX_STANDARD 17)

add_executable(Template_List main.cpp include/Array_List.hpp include/Linked_List.hpp Tests/test_array_list.hpp Tests/test_linked_list.hpp)
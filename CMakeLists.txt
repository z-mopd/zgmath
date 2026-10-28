cmake_minimum_required(VERSION 3.14)

project(zgmath)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tests)

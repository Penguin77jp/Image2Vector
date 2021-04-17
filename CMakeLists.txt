cmake_minimum_required(VERSION 3.1)
# set(CMAKE_CXX_STANDARD 20)
project(Image2Vector CXX)
include_directories(Image2Vector 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/stb
)
file(GLOB srcfiles
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)
add_executable(Image ${srcfiles})
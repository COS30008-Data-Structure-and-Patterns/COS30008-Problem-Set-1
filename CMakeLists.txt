cmake_minimum_required(VERSION 3.20)

project(COS30008_Problem_Set_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(problem-set-1
    src/main.cpp
    src/Entity.cpp
    src/Iterator1D.cpp
    src/Iterator2D.cpp
)

target_include_directories(problem-set-1 PRIVATE include)

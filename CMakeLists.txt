cmake_minimum_required(VERSION 3.20)
project(QuantumSimCpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -O2)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "cli/*.cpp")
add_executable(qs ${SOURCES})

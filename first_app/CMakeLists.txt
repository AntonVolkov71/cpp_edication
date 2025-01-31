cmake_minimum_required(VERSION 3.30)
project(first_app)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Werror -Wall -Wextra)
add_executable(first_app main.cpp)

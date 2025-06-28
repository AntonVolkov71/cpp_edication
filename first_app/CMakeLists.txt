cmake_minimum_required(VERSION 3.30)
project(first_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-subsystem,console")

#add_compile_options(-Werror -Wall -Wextra)
add_executable(first_app main.cpp
        log_duration.h
        ini.cpp
        ini.h
        people.cpp
        people.h
)

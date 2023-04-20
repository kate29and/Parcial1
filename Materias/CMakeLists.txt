cmake_minimum_required(VERSION 3.5)

project(Materias LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Materias main.cpp)

install(TARGETS Materias
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

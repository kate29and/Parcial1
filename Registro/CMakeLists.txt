cmake_minimum_required(VERSION 3.5)

project(Registro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Registro main.cpp)

install(TARGETS Registro
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

cmake_minimum_required(VERSION 3.5)

project(Horario LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Horario main.cpp)

install(TARGETS Horario
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

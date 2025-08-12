cmake_minimum_required(VERSION 3.10)
project(Practica_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        main.cpp
        Nodo/Nodo.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
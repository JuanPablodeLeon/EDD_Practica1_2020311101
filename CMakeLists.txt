cmake_minimum_required(VERSION 3.10)
project(Practica_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        main.cpp
        Nodo/Nodo.cpp
        Cola/Cola.cpp
        Cola/Cola.h
        Nodo/NodoInterno.cpp
        Nodo/NodoInterno.h
        Nodo/NodoCabecera.cpp
        Nodo/NodoCabecera.h
        Nodo/ListaEncabezado.cpp
        Nodo/ListaEncabezado.h
)

add_executable(${PROJECT_NAME} ${SOURCES})
cmake_minimum_required(VERSION 3.10)
project(Practica_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        main.cpp
        Nodo/Nodo.cpp
        Cola/Cola.cpp
        Cola/Cola.h
        MatrizDispersa/NodoInterno.cpp
        MatrizDispersa/NodoInterno.h
        MatrizDispersa/NodoCabecera.cpp
        MatrizDispersa/NodoCabecera.h
        MatrizDispersa/ListaEncabezado.cpp
        MatrizDispersa/ListaEncabezado.h
        MatrizDispersa/MatrizDispersa.cpp
        MatrizDispersa/MatrizDispersa.h
        Pila/Pila.cpp
        Pila/Pila.h
        Jugabilidad/Menu.cpp
        Jugabilidad/Menu.h
)

add_executable(${PROJECT_NAME} ${SOURCES})
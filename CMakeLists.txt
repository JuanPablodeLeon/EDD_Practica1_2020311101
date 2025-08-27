cmake_minimum_required(VERSION 3.10)
project(Practica_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Solo .cpp en la lista
set(SOURCES
        main.cpp
        Nodo/Nodo.cpp
        Cola/Cola.cpp
        MatrizDispersa/NodoInterno.cpp
        MatrizDispersa/NodoCabecera.cpp
        MatrizDispersa/ListaEncabezado.cpp
        MatrizDispersa/MatrizDispersa.cpp
        Pila/Pila.cpp
        Jugador/Jugador.cpp
        Jugador/Jugador.h
        Configuraciones/ConfiguracionInicial.cpp
        Configuraciones/ConfiguracionInicial.h
        Cuadrado/Cuadrado.cpp
        Cuadrado/Cuadrado.h
        Juego/Juego.cpp
        Juego/Juego.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

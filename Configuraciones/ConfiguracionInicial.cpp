//
// Created by juanp on 27/08/2025.
//

#include "ConfiguracionInicial.h"

ConfiguracionInicial::ConfiguracionInicial()
{
    this->fila = 0;
    this->columna = 0;
    this->cantidadJugadores = 0;
}

void ConfiguracionInicial::inicio()
{
    std::cout << "----- Configuracion Inicial ------" << std::endl;

    configJugadores();
    configTablero();

    std::cout << "----- Configuracion Completada ------" << std::endl;
    std::cout << "El tamaño del tablero es de: " <<fila<<" x "<<columna<< std::endl;
    std::cout << "Cantidad de Jugadores: "<< cantidadJugadores<<std::endl;

    //cola->imprimir();
}

void ConfiguracionInicial::configTablero()
{
    std::cout << "\n\n----- Configuracion de Tablero ------\n\n" << std::endl;
    do
    {
        std::cout << "Cantidad Filas (minimo 3): " ;
        std::cin >> fila;
        if (fila < 3)
        {
            std::cout << "El valor debe ser minimo 3. " << std::endl;
            continue;
        }
        std::cout << "Cantidad Filas (maximo 3): " ;
        std::cin >> columna;
        if (columna < 3)
        {
            std::cout << "El valor debe ser maximo 3. " << std::endl;
            continue;
        }
    }
    while (fila <3 || columna < 3);
}

void ConfiguracionInicial::configJugadores()
{
    std::cout << "\n\n----- Configuracion de Jugadores ------\n\n" << std::endl;
    do
    {
        std::cout << "Cantidad Jugadores (minimo 2): " ;
        std::cin >> cantidadJugadores;
        if (cantidadJugadores < 2)
        {
            std::cout << "El valor debe ser minimo 2. Vuelva a agregar" << std::endl;
        }
    }
    while (cantidadJugadores < 2);

    std::cout << "-------- Aregar inicial a Jugadores -------- " <<std::endl;
    for (int i = 0; i < cantidadJugadores; ++i)
    {
        char letraJugador;

        std::cout << "\n Jugador No.  "<<(i+1)<< std::endl;
        std::cout << "Ingrese la letra ";
        std::cin >> letraJugador;

        Jugador nuevoJugador(letraJugador);
        cola->insertar(nuevoJugador);
    }
}

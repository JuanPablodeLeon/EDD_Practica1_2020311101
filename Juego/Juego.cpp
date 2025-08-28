//
// Created by juanp on 27/08/2025.
//

#include "Juego.h"

Juego::Juego()
{
    this->tableroCoordenadas = nullptr;
    config.inicio();
}

Juego::~Juego()
{
    delete tableroCoordenadas;
}

void Juego::iniciar()
{
    inicalizarTableros();
    juabilidad();
}

void Juego::inicalizarTableros()
{
    int filas = config.getFila();
    int columns = config.getColumna();

    tableroCoordenadas = new MatrizDispersa<int>;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            tableroCoordenadas->insertar(0,i,j);
        }
    }
}

void Juego::realizarTurnos(Jugador& jugador)
{
    std::cout << "Turno del jugador: " << jugador.getLetrar()<< std::endl;

}

void Juego::juabilidad()
{
    tableroCoordenadas->mostrar();
}


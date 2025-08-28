//
// Created by juanp on 26/08/2025.
//

#include "Jugador.h"

Jugador::Jugador()
{
    this->letra = letra;
    this->puntos = 0;
    this->cantidadInicialesColocadas = 0;
    this->puntosNuevasTierras = 0;
    this->puntosFilas = 0;
    this->puntosColumnas = 0;
   // this->powerUps = Pila<char>();*/
}
Jugador::Jugador(const Jugador &otro)
{
    this->letra = otro.letra;
    this->puntos = 0;
    this->cantidadInicialesColocadas = 0;
    this->puntosNuevasTierras = 0;
    this->puntosFilas = 0;
    this->puntosColumnas = 0;
    // this->powerUps = Pila<char>();*/
}
Jugador::Jugador(char letra)
{
    this->letra = letra;
    this->puntos = 0;
    this->cantidadInicialesColocadas = 0;
    this->puntosNuevasTierras = 0;
    this->puntosFilas = 0;
    this->puntosColumnas = 0;
    // this->powerUps = Pila<char>();
}

Jugador::~Jugador()
{
    //delete powerUps;
    std::cout <<"Eliminado"<<std::endl;
}


void Jugador::sumarPuntos(int opcion)
{
    switch (opcion)
    {
    case 1:
        puntos++;
        break;
    case 2:
        cantidadInicialesColocadas++;
        break;
    case 3:
        puntosNuevasTierras++;
        break;
    case 4:
        puntosFilas++;
        break;
    case 5:
        puntosColumnas++;
        break;
    case 6:
        cantidadInicialesColocadas--;
        break;
    default:
        std::cout << "Opcion incorrecto." << std::endl;
    }
}

void Jugador::mostrarInfo()
{
    std::cout << letra << std::endl;
    std::cout << "puntos: " << puntos << std::endl;
}
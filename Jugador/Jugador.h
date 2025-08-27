//
// Created by juanp on 26/08/2025.
//

#ifndef PRACTICA_1_JUGADOR_H
#define PRACTICA_1_JUGADOR_H
#include "../Pila/Pila.h"

class Jugador
{
    private:
        char letra;
        int puntos;
        int cantidadInicialesColocadas;
        int puntosNuevasTierras;
        int puntosFilas;
        int puntosColumnas;
        Pila<char> powerUps;

    public:
        Jugador();
        Jugador(char letra);
        void sumarPuntos(int opcion);
        void mostrarInfo();
};

Jugador::Jugador()
{

}
Jugador::Jugador(char letra)
{
    this->letra = letra;
    this->puntos = 0;
    this->cantidadInicialesColocadas = 0;
    this->puntosNuevasTierras = 0;
    this->puntosFilas = 0;
    this->puntosColumnas = 0;
    this->powerUps = Pila<char>();
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

#endif //PRACTICA_1_JUGADOR_H
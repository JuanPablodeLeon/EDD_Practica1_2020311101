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
        Jugador(const Jugador &otro);
        Jugador(char letra);
        ~Jugador();
        Jugador& operator=(Jugador const &otro);
        void sumarPuntos(int opcion);
        void mostrarInfo();

};



#endif //PRACTICA_1_JUGADOR_H
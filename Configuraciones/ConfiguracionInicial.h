//
// Created by juanp on 27/08/2025.
//

#ifndef PRACTICA_1_CONFIGURACIONINICIAL_H
#define PRACTICA_1_CONFIGURACIONINICIAL_H
#include "../Cola/Cola.h"
#include "../Jugador/Jugador.h"

class ConfiguracionInicial
{
    private:
        int fila;
        int columna;
        int cantidadJugadores;
       Cola<Jugador>* cola;
        void configJugadores();
        void configTablero();
    public:
         ConfiguracionInicial();
         ~ConfiguracionInicial();
        void inicio();
        int getFila();
        int getColumna();
        Cola<Jugador>* getCola();

};


#endif //PRACTICA_1_CONFIGURACIONINICIAL_H
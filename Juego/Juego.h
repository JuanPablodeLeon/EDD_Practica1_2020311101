//
// Created by juanp on 27/08/2025.
//

#ifndef PRACTICA_1_JUEGO_H
#define PRACTICA_1_JUEGO_H
#include "../Configuraciones/ConfiguracionInicial.h"
#include "../MatrizDispersa/MatrizDispersa.h"
#include "../Cola/Cola.h"
#include "../Jugador/Jugador.h"

class Juego
{
private:
    ConfiguracionInicial config;
    MatrizDispersa<int>* tableroCoordenadas;
    MatrizDispersa<int>* tableroCuadros;
    void inicalizarTableros();
    void juabilidad();
    void realizarTurnos(Jugador& jugador);
    void mostrarTableros();
    public:
    Juego();
    ~Juego();
};


#endif //PRACTICA_1_JUEGO_H
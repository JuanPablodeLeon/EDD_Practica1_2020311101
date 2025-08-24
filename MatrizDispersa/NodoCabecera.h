//
// Created by juanp on 22/08/2025.
//

#ifndef PRACTICA_1_NODOCABECERA_H
#define PRACTICA_1_NODOCABECERA_H
#include "NodoInterno.h"

//Funciona como guia y puntero de las columnas
template<typename T>class NodoCabecera
{
    public:
        int id;
        NodoCabecera<T>* siguiente;
        NodoCabecera<T>* anterior;
        /*
         * Forma de obtener las coordenadas
         */
        NodoInterno<T>* acceso;
        NodoCabecera(int id)
        {
            this->id = id;
            this->siguiente = nullptr;
            this->anterior = nullptr;
            this->acceso = nullptr;
        }
};



#endif //PRACTICA_1_NODOCABECERA_H
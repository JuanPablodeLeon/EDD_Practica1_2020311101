//
// Created by juanp on 22/08/2025.
//

#ifndef PRACTICA_1_NODOCABECERA_H
#define PRACTICA_1_NODOCABECERA_H


template<typename T>class NodoCabecera
{
    public:
        int id;
        NodoCabecera<T>* siguiente;
        NodoCabecera<T>* anterior;
        NodoCabecera<T>* acceso;
        NodoCabecera(int id)
        {
            this->id = id;
            this->siguiente = nullptr;
            this->anterior = nullptr;
            this->acceso = nullptr;
        }
};

#include "NodoCabecera.cpp"

#endif //PRACTICA_1_NODOCABECERA_H
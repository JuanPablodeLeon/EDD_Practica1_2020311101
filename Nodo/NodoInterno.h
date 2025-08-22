//
// Created by juanp on 22/08/2025.
//

#ifndef PRACTICA_1_NODOINTERNO_H
#define PRACTICA_1_NODOINTERNO_H


template <typename T> class NodoInterno
{
public:
    int x;
    int y;
    T valor;
    NodoInterno<T>* siguiente;
    NodoInterno<T>* anterior;
    NodoInterno<T>* arriba;
    NodoInterno<T>* abajo;

    NodoInterno(int x, int y, T valor)
    {
        this->x = x;
        this->y = y;
        this->valor = valor;

        this->siguiente = nullptr;
        this->anterior = nullptr;
        this->arriba = nullptr;
        this->abajo = nullptr;
    }
};


#endif //PRACTICA_1_NODOINTERNO_H
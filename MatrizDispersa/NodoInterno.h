//
// Created by juanp on 22/08/2025.
//

#ifndef PRACTICA_1_NODOINTERNO_H
#define PRACTICA_1_NODOINTERNO_H


template <typename T> class NodoInterno
{
public:
    //coordenadas
    int x;
    int y;
    //Objeto o variable con valor en especifico
    T valor;
    //Punteros
    //Punteros de forma horizontal
    NodoInterno<T>* siguiente;
    NodoInterno<T>* anterior;
    //Punteros de forma vertical
    NodoInterno<T>* arriba;
    NodoInterno<T>* abajo;

    //Constructor para inicializar la clase
    NodoInterno(int x, int y, T valor)
    {
        this->x = x;
        this->y = y;
        this->valor = valor;

        //Nulos por defecto
        this->siguiente = nullptr;
        this->anterior = nullptr;
        this->arriba = nullptr;
        this->abajo = nullptr;
    }
};


#endif //PRACTICA_1_NODOINTERNO_H
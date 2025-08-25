//
// Created by juanp on 12/08/2025.
//

#ifndef EDD_PRACTICA1_2020311101_NODO_H
#define EDD_PRACTICA1_2020311101_NODO_H


template <typename T>
class Nodo
{

    public:
    T valor;
    Nodo<T>* siguiente;
     Nodo(T valor)
     {
         this->valor = valor;
         this->siguiente = nullptr;
     }
};


#endif //EDD_PRACTICA1_2020311101_NODO_H
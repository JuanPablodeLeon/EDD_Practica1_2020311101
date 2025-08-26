//
// Created by juanp on 26/08/2025.
//

#ifndef PRACTICA_1_PILA_H
#define PRACTICA_1_PILA_H
#include <iostream>
#include "../Nodo/Nodo.h"


template <typename T> class Pila
{
    private:
        Nodo<T>* primero;
        int size;
    public:
        Pila();
        void insertar(T dato);
        T extraer();
        T ver_cima();
        bool estaVacia();
        void imprimir();
        int obtener_size();

        ~Pila()
        {
            while (!estaVacia())
            {
                extraer();
            }
        }
};

template <typename T>
Pila<T>::Pila()
{
    primero = nullptr;
    size = 0;
}

template <typename T>
void Pila<T>::insertar(T dato)
{
    Nodo<T>* nuevo = new Nodo<T>(dato);
    nuevo->siguiente = primero;
    primero = nuevo;
    size +=1;
}

template <typename T>
T Pila<T>::extraer()
{
    if (primero == nullptr)
    {
        return T();
    }

    Nodo<T>* temp = primero;
    T valor_extraido = temp->valor;
    primero = primero->siguiente;
    delete temp;
    size -=1;
    return valor_extraido;

}

template <typename T>
T Pila<T>::ver_cima()
{
    if (primero == nullptr)
    {
        return T();
    }

    return primero->valor;
}

template <typename T>
bool Pila<T>::estaVacia()
{
    return primero == nullptr;
}

template <typename T>
int Pila<T>::obtener_size()
{
    return size;
}

template <typename T>
void Pila<T>::imprimir()
{
    Nodo<T>* temp = primero;
    while (temp != nullptr)
    {
        std::cout << temp->valor << std::endl;
        temp = temp->siguiente;
    }
}

#endif //PRACTICA_1_PILA_H
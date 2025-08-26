//
// Created by juanp on 19/08/2025.
//

#ifndef PRACTICA_1_COLA_H
#define PRACTICA_1_COLA_H
#include <iostream>
#include "../Nodo/Nodo.h"


 template <typename T>
class Cola
{
     private:
     Nodo<T>* primero;
     Nodo<T>* ultimo;
     int size;
 public:


    Cola();
     void insertar(T dato);
     T extraer();
     void imprimir();
     bool estaVacia();
     T verPrimero();
     int obtenerSize();

    ~Cola()
    {
        while (!estaVacia())
        {
            extraer();
        }
    }

};

template <typename T>
Cola<T>::Cola()
{
    this->primero= nullptr;
    this->ultimo = nullptr;
    this->size = 0;
}

//Agregar nuevo dato a la cosa
template <typename T>
void Cola<T>::insertar(T dato)
{
    Nodo<T>* nuevo = new Nodo<T>(dato);

    if (ultimo == nullptr) //Si la cabeza esta vacia y la cola son los mismo
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else //Se van agregando datos despues del primero
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    size ++; //Aumenta el tamaño de la cola
}

//Sacar el primer elemento de la cola
template <typename T>
T Cola<T>::extraer()
{
    if (primero == nullptr)
    {
       return T();
    }
    Nodo<T>* temp = primero; //Se usa temp en la cabeza para no perder la referencia
    T valor_extraido = temp->valor;
    primero = primero->siguiente;

    if (primero == nullptr)
    {
        ultimo = nullptr;
    }

    delete temp;
    size--;
    return valor_extraido;
}

//Mostrar los elementos de la cola
template <typename T>
void ::Cola<T>::imprimir()
{
    Nodo<T>* temp = primero;
    while (temp != nullptr)
    {
        std::cout << temp->valor <<std::endl;
        temp = temp->siguiente;
    }
}

template <typename T>
bool Cola<T>::estaVacia()
{
    return primero == nullptr;
}

template <typename T>
T Cola<T>::verPrimero()
{
    if (primero == nullptr)
    {
        return T();
    }
    return primero->valor;
}

template <typename T>
int Cola<T>::obtenerSize()
{
    return size;
}


#endif //PRACTICA_1_COLA_H
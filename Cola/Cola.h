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

 public:
     Nodo<T>* primero;
     Nodo<T>* ultimo;
     int size;

    Cola();
     void insertar(T dato);
     T extraer();
     void imprimir() const;
     bool estaVacia() const;
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
        primero = nuevo;
    }
    size += 1; //Aumenta el tamaño de la cola
}
//Sacar el primer elemento de la cola
template <typename T>
T Cola<T>::extraer()
{
    if (this->primero == nullptr)
    {
       throw std::out_of_range("La cola esta vacia");
    }
    Nodo<T>* temp = this->primero; //Se usa temp en la cabeza para no perder la referencia
    this->primero = this->primero->siguiente;
    if (this->primero == nullptr) //Se verifica si el nuevo primero tiene algun valor
    {
        this->ultimo = nullptr;
    }
    this->size -= 1; //se disminuye el tamaño de la lista
    return temp->valor; //Devuelve el valor de la cabeza para poder sacarlo

    /*if (primero == nullptr) {
        throw std::out_of_range("La cola está vacía");
    }

    Nodo<T>* temp = primero;
    T valor = primero->valor;
    primero = primero->siguiente;

    if (primero == nullptr) {
        ultimo = nullptr;
    }

    delete temp;
    size--;
    return valor;*/
}

template <typename T>
void ::Cola<T>::imprimir() const
{
    Nodo<T>* temp = this->primero;
    while (temp != nullptr)
    {
        std::cout << temp->valor << " "<<std::endl;
        temp = temp->siguiente;
    }
}

template <typename T>
bool Cola<T>::estaVacia() const
{
    return primero == nullptr;
}

#endif //PRACTICA_1_COLA_H
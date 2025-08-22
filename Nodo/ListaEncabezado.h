//
// Created by juanp on 22/08/2025.
//

#ifndef PRACTICA_1_LISTAENCABEZADO_H
#define PRACTICA_1_LISTAENCABEZADO_H
#include <iostream>
#include "NodoCabecera.h"
#include "NodoInterno.h"


template<typename T> class ListaEncabezado
{
    private:
        std::string tipo;
        int size;
    public:
        NodoCabecera<T>* primero;
        NodoCabecera<T>* ultimo;

        ListaEncabezado(std::string tipo)
        {
            this->tipo = tipo;
            this->size = 0;
            this->primero = nullptr;
            this->ultimo = nullptr;
        }

        void insertarNodoCabecera(NodoCabecera<T>* nuevo);
        NodoCabecera<T>* getEncabezado(int id)
        {
            NodoCabecera<T>* actual = primero;
            while (actual != nullptr)
            {
                if (actual->id == id)
                {
                    return actual;
                }
                actual = actual->siguiente;
            }
            return nullptr;
        }

        int getSize() const
        {
            return size;
        }
};

template <typename T>
void ListaEncabezado<T>::insertarNodoCabecera(NodoCabecera<T>* nuevo)
{
    if (primero == nullptr)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        //Se ordenan a base del ID
        if (nuevo ->id < ultimo->id)
        {
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;
        }
        //Si el nuevo nodo agregado es mayor al ultimo
        else if (nuevo->id > ultimo->id)
        {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
        }
        else
        {
            //Se va a recorrer hasta encontrar la posicion correcta
            NodoInterno<T>* actual = primero;
            while (actual != nullptr)
            {
                if (nuevo->id < actual->id)
                {
                    nuevo->siguiente = actual;
                    nuevo->anterior = actual->anterior;
                    actual->anterior->siguiente = nuevo;
                    actual->anterior = nuevo;
                    break;
                }
                else if (nuevo->id > actual->id)
                {
                    actual = actual->siguiente;
                }
                else
                {
                    return; //en caos de que el ID ya exista no lo duplica
                }
            }
        }
    }
    size++;
}


#endif //PRACTICA_1_LISTAENCABEZADO_H
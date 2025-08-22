//
// Created by juanp on 22/08/2025.
//

#ifndef PRACTICA_1_MATRIZDISPERSA_H
#define PRACTICA_1_MATRIZDISPERSA_H
#import "ListaEncabezado.h"

template <typename T>
class MatrizDispersa
{
    private:
        int capa;
        ListaEncabezado<T> filas;
        ListaEncabezado<T> columnas;
        void revisarCabereras(int fila, int columna, NodoCabecera<T>*& nodoFila, NodoCabecera<T>*& nodoColumnas);
    public:
        MatrizDispersa(): capa(0), filas("fila"), columnas("columna") {}

        void insertar(T valor, int fila, int columna);
};

template <typename T>
void MatrizDispersa<T>::revisarCabereras(int fila, int columna, NodoCabecera<T>*& nodoFila, NodoCabecera<T>*& nodoColumnas)
{
    //Revisa si existen ya los encabezados
    nodoFila = filas.getEncabezado(fila);
    nodoColumnas = columnas.getEncabezado(columnas);

    if (nodoFila == nullptr)
    {
        nodoFila = new NodoCabecera<T>(fila);
        filas.insertarNodoCabecera(nodoFila);
    }

    if (nodoColumnas == nullptr)
    {
        nodoColumnas = new NodoCabecera<T>(columnas);
        columnas.insertarNodoCabecera(nodoColumnas);
    }
}

template <typename T>
void MatrizDispersa<T>::insertar(T valor, int fila, int columna)
{
    NodoInterno<T>* nuevo = new NodoInterno<T>(fila, columna, valor);

    NodoCabecera<T>* nodoFila = nullptr;
    NodoCabecera<T>* nodoColumna = nullptr;

    revisarCabereras(fila, columna,nodoFila, nodoColumna);

    if (nodoFila->acceso == nullptr)
    {
        nodoFila->acceso = nuevo;
    }
    else
    {
        if (nuevo->y < nodoFila->acceso->y)
        {
            nuevo->siguiente = nodoFila->acceso;
            nodoFila->acceso->anterior = nuevo;
            nodoFila->acceso = nuevo;
        }
        else
        {
            NodoInterno<T>* actual = nodoFila->acceso;
            while (actual != nullptr)
            {
                if (nuevo->y < actual->y)
                {
                    nuevo->siguiente = actual;
                    nuevo->anterior = actual->siguiente;
                    actual->anterior->siguiente = nuevo;
                    actual->anterior = nuevo;
                    break;
                }
                else if (nuevo->x == actual->x && nuevo->y == actual->y)
                {
                    delete nuevo;
                    return;
                }
                else
                {
                    if (actual->siguiente != nullptr)
                    {
                        actual->siguiente= nuevo;
                        nuevo->anterior = actual;
                        break;
                    }
                    else
                    {
                        actual = actual->siguiente;
                    }
                }
            }
        }

        if (nodoColumna->acceso == nullptr)
        {
            nodoColumna->acceso = nuevo;
        }
        else
        {
            if (nuevo->x < nodoColumna->acceso->x)
            {
                nuevo->abajo = nodoColumna->acceso;
                nodoColumna->acceso->arriba = nuevo;
                nodoColumna->acceso = nuevo;
            }
        }
    }
}

#endif //PRACTICA_1_MATRIZDISPERSA_H
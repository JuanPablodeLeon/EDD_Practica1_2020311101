//
// Created by juanp on 22/08/2025.
//

#ifndef PRACTICA_1_MATRIZDISPERSA_H
#define PRACTICA_1_MATRIZDISPERSA_H
#include  <utility>
#include  "ListaEncabezado.h"
#include "NodoCabecera.h"
#include "NodoInterno.h"

template <typename T>
class MatrizDispersa
{
    private:
        int capa;
        ListaEncabezado<T> filas;
        ListaEncabezado<T> columnas;

        std::pair<NodoCabecera<T>*, NodoCabecera<T>*> revisarCabeceras(int fila, int columna)
        {
            NodoCabecera<T>* nodoFila = filas.getEncabezado(fila);
            NodoCabecera<T>* nodoColumna = columnas.getEncabezado(columna);

            if (nodoFila == nullptr)
            {
                nodoFila = new NodoCabecera<T>(fila);
                filas.insertarNodoCabecera(nodoFila);
            }
            if (nodoColumna == nullptr)
            {
                nodoColumna = new NodoCabecera<T>(columna);
                columnas.insertarNodoCabecera(nodoColumna);
            }
            return std::make_pair(nodoFila, nodoColumna);
        }
    public:
        MatrizDispersa(): capa(0), filas("fila"), columnas("columna") {}

        void insertar(T valor, int fila, int columna);

        void mostrar();
        bool eliminar(int fila, int columna);

        ~MatrizDispersa();
};


template <typename T>
void MatrizDispersa<T>::insertar(T valor, int fila, int columna)
{
     NodoInterno<T>* nuevo = new NodoInterno<T>(fila, columna, valor);
        auto [nodoFila, nodoColumna] = revisarCabeceras(fila, columna);

        // Insertar nodo Interno en la fila Correspondiente:
        if (nodoFila->acceso == nullptr) {
            nodoFila->acceso = nuevo;
        } else { // Si ya está apuntando a un nodo, debemos insertarlo ORDENADAMENTE
            // Si el nuevo nodo es menor que el acceso actual.
            if (nuevo->y < nodoFila->acceso->y) {
                nuevo->siguiente = nodoFila->acceso;
                nodoFila->acceso->anterior = nuevo;
                nodoFila->acceso = nuevo;
            } else { // Si no se cumple, se busca en dónde se inserta:
                NodoInterno<T>* actual = nodoFila->acceso;
                while (actual != nullptr) {
                    if (nuevo->y < actual->y) {
                        nuevo->siguiente = actual;
                        nuevo->anterior = actual->anterior;
                        actual->anterior->siguiente = nuevo;
                        actual->anterior = nuevo;
                        break;
                    } else if (nuevo->x == actual->x && nuevo->y == actual->y) {
                        // Nodo ya existe, no insertamos
                        delete nuevo;
                        return;
                    } else {
                        if (actual->siguiente == nullptr) {
                            actual->siguiente = nuevo;
                            nuevo->anterior = actual;
                            break;
                        } else {
                            actual = actual->siguiente;
                        }
                    }
                }
            }
        }

        // Insertamos el nodo en la columna correspondiente:
        if (nodoColumna->acceso == nullptr) {
            nodoColumna->acceso = nuevo;
        } else { // Si ya está apuntando a un nodo, debemos insertarlo ordenadamente.
            // Si el nuevo nodo es menor que el acceso actual:
            if (nuevo->x < nodoColumna->acceso->x) {
                nuevo->abajo = nodoColumna->acceso;
                nodoColumna->acceso->arriba = nuevo;
                nodoColumna->acceso = nuevo;
            } else { // Si no se cumple, se busca para buscar dónde insertarlo.
                NodoInterno<T>* actual = nodoColumna->acceso;
                while (actual != nullptr) {
                    if (nuevo->x < actual->x) {
                        nuevo->abajo = actual;
                        nuevo->arriba = actual->arriba;
                        actual->arriba->abajo = nuevo;
                        actual->arriba = nuevo;
                        break;
                    } else if (nuevo->x == actual->x && nuevo->y == actual->y) {
                        // Nodo ya existe, no insertamos
                        return;
                    } else {
                        if (actual->abajo == nullptr) {
                            actual->abajo = nuevo;
                            nuevo->arriba = actual;
                            break;
                        } else {
                            actual = actual->abajo;
                        }
                    }
                }
            }
        }
}

template <typename T>
void MatrizDispersa<T>::mostrar()
{
    // Encontrar los límites de la matriz
    int minFila = INT_MAX, maxFila = INT_MIN;
    int minColumna = INT_MAX, maxColumna = INT_MIN;

    // Encontrar los límites
    NodoCabecera<T>* filaActual = filas.primero;
    while (filaActual != nullptr) {
        minFila = std::min(minFila, filaActual->id);
        maxFila = std::max(maxFila, filaActual->id);

        NodoInterno<T>* nodo = filaActual->acceso;
        while (nodo != nullptr) {
            minColumna = std::min(minColumna, nodo->y);
            maxColumna = std::max(maxColumna, nodo->y);
            nodo = nodo->siguiente;
        }
        filaActual = filaActual->siguiente;
    }

    if (minFila == INT_MAX) {
        std::cout << "Matriz vacía" << std::endl;
        return;
    }

    // Imprimir la matriz
    for (int i = minFila; i <= maxFila; i++) {
        // Línea de coordenadas
        for (int j = minColumna; j <= maxColumna; j++) {
            // Verificar si existe la coordenada
            bool existe = false;
            NodoCabecera<T>* fila = filas.getEncabezado(i);

            if (fila != nullptr) {
                NodoInterno<T>* actual = fila->acceso;
                while (actual != nullptr) {
                    if (actual->y == j) {
                        existe = true;
                        break;
                    }
                    actual = actual->siguiente;
                }
            }

            if (existe) {
                std::cout << "(" << i << "," << j << ")";
            } else {
                std::cout << "   .   ";  // Punto para celda vacía
            }

            // Conexión horizontal
            if (j < maxColumna) {
                std::cout << " - ";
            }
        }
        std::cout << std::endl;

        // Línea de conexiones verticales (excepto última fila)
        if (i < maxFila) {
            for (int j = minColumna; j <= maxColumna; j++) {
                // Verificar si existe la coordenada
                bool existe = false;
                NodoCabecera<T>* fila = filas.getEncabezado(i);

                if (fila != nullptr) {
                    NodoInterno<T>* actual = fila->acceso;
                    while (actual != nullptr) {
                        if (actual->y == j) {
                            existe = true;
                            break;
                        }
                        actual = actual->siguiente;
                    }
                }

                if (existe) {
                    std::cout << "   |   ";
                } else {
                    std::cout << "       ";  // Espacio vacío
                }

                if (j < maxColumna) {
                    std::cout << "     ";  // Espacio entre conexiones
                }
            }
            std::cout << std::endl;
        }
    }
}
template <typename T>
MatrizDispersa<T>::~MatrizDispersa()
{

    NodoCabecera<T>*columnaActual = columnas.primero;
    while (columnaActual != nullptr)
    {
        NodoInterno<T>* nodoActual = columnaActual->acceso;
        while (nodoActual != nullptr)
        {
          //  std::cout << "Elminando Nodo: " << nodoActual->x <<","<<nodoActual->y<< std::endl;
            NodoInterno<T>* temp = nodoActual;
            std::cout << "Elminando Nodo: " << temp->x <<","<<temp->y<< std::endl;
            nodoActual = nodoActual->anterior;
            delete temp;
        }
        NodoCabecera<T>* tempColumna = columnaActual;
        columnaActual = columnaActual->siguiente;
        delete tempColumna;
    }

    NodoCabecera<T>* filaActual = filas.primero;
    while (filaActual != nullptr)
    {
        NodoCabecera<T>* temp = filaActual;
        filaActual = filaActual->siguiente;
        delete temp;
    }
}


template <typename T>
bool MatrizDispersa<T>::eliminar(int fila, int columna)
{
    NodoCabecera<T>* nodoFila = filas.getEncabezado(fila);
    NodoCabecera<T>* nodoColumna = columnas.getEncabezado(columna);

    if (nodoFila == nullptr || nodoColumna == nullptr) {
        return false;  // No existe la fila o columna
    }

    // Buscar el nodo en la fila
    NodoInterno<T>* actual = nodoFila->acceso;
    NodoInterno<T>* anterior = nullptr;

    while (actual != nullptr && actual->y != columna) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        return false;  // Nodo no encontrado
    }

    // Reenlazar en la fila
    if (anterior == nullptr) {
        nodoFila->acceso = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    if (actual->siguiente != nullptr) {
        actual->siguiente->anterior = anterior;
    }

    // Buscar el nodo en la columna
    actual = nodoColumna->acceso;
    anterior = nullptr;

    while (actual != nullptr && actual->x != fila) {
        anterior = actual;
        actual = actual->abajo;
    }

    // Reenlazar en la columna
    if (anterior == nullptr) {
        nodoColumna->acceso = actual->abajo;
    } else {
        anterior->abajo = actual->abajo;
    }
    if (actual->abajo != nullptr) {
        actual->abajo->arriba = anterior;
    }

    delete actual;  // Liberar memoria del nodo
    return true;
}

#endif //PRACTICA_1_MATRIZDISPERSA_H
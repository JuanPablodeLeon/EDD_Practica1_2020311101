#include <iostream>
#include <string>
#include "MatrizDispersa/MatrizDispersa.h"
#include "Cola/Cola.h"
using namespace std;

int main(){

/*
    MatrizDispersa<int> matrizEnteros;

    matrizEnteros.insertar(1,2);
    matrizEnteros.insertar(3, 4);
    matrizEnteros.insertar(1, 5);
    matrizEnteros.insertar(2, 3);

    // Mostrar la matriz
    matrizEnteros.mostrar();

    std::cout << "Matriz Eliminada"<<std::endl;
*/

    Cola<int> colaEnteros;

    colaEnteros.insertar(1);
    colaEnteros.insertar(2);
    colaEnteros.insertar(3);
    colaEnteros.insertar(4);

    Nodo<int>* actual = colaEnteros.primero; // Necesitarías hacer primero público o usar amigo
    while (actual != nullptr) {
        cout << actual->valor << endl;
        actual = actual->siguiente;
    }



return 0;
}
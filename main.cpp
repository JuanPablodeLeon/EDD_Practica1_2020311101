#include <iostream>
#include <string>
#include "MatrizDispersa/MatrizDispersa.h"
using namespace std;

int main(){
    std::cout << "Hello World";

    //std::string lista[5];
    MatrizDispersa<int> matrizEnteros;

    matrizEnteros.insertar(10,1,2);
    matrizEnteros.insertar(20, 3, 4);
    matrizEnteros.insertar(30, 1, 5);
    matrizEnteros.insertar(40, 2, 3);

    // Mostrar la matriz
    matrizEnteros.mostrar();



return 0;
}
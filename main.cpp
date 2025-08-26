#include <iostream>
#include "MatrizDispersa/MatrizDispersa.h"
//#include "Jugabilidad/Menu.h"
#include "Jugador/Jugador.h"

int main(){
    Jugador* jugador = new Jugador('A');
    jugador->mostrarInfo();
    jugador->sumarPuntos(1);
    jugador->mostrarInfo();
    delete jugador;


return 0;
}
//
// Created by juanp on 26/08/2025.
//

// Jugabilidad/Menu.cpp
#include "Menu.h"  // O "Jugabilidad/Menu.h" si es necesario
#include <iostream>

void Menu::holamundo()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << i+1 << std::endl;
    }
}

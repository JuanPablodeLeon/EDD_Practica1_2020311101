@echo off
echo ========================================
echo    COMPILADOR AUTOMATICO - PRACTICA 1
echo ========================================
echo.

echo Limpiando compilaciones anteriores...
del *.o 2>nul
del mi_programa.exe 2>nul

echo.
echo Compilando archivos fuente...

:: Compilar cada archivo .cpp
g++ -c main.cpp -std=c++17 -o main.o
g++ -c Nodo/Nodo.cpp -std=c++17 -o Nodo.o
g++ -c Cola/Cola.cpp -std=c++17 -o Cola.o
g++ -c MatrizDispersa/NodoInterno.cpp -std=c++17 -o NodoInterno.o
g++ -c MatrizDispersa/NodoCabecera.cpp -std=c++17 -o NodoCabecera.o
g++ -c MatrizDispersa/ListaEncabezado.cpp -std=c++17 -o ListaEncabezado.o
g++ -c MatrizDispersa/MatrizDispersa.cpp -std=c++17 -o MatrizDispersa.o
g++ -c Pila/Pila.cpp -std=c++17 -o Pila.o
g++ -c Jugabilidad/Menu.cpp -std=c++17 -o Menu.o

echo.
echo Enlazando objetos...
:: Enlazar todos los objetos
g++ main.o Nodo.o Cola.o NodoInterno.o NodoCabecera.o ListaEncabezado.o MatrizDispersa.o Pila.o Menu.o -o mi_programa.exe

echo.
if exist mi_programa.exe (
    echo ¡Compilacion exitosa!
    echo Ejecutando programa...
    echo ========================================
    echo.
    mi_programa.exe
) else (
    echo ERROR: La compilacion fallo
    pause
    exit /b 1
)

echo.
echo ========================================
echo Programa ejecutado completado
pause
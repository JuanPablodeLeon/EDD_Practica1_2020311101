    @echo off
    echo ========================================
    echo    COMPILADOR AUTOMATICO - PRACTICA 1
    echo ========================================
    echo.

    echo Limpiando compilaciones anteriores...
    if exist build rmdir /s /q build
    if exist mi_programa.exe del mi_programa.exe

    echo Creando carpeta build...
    mkdir build

    echo.
    echo Compilando archivos fuente...

    :: Compilar cada archivo .cpp en build
    g++ -c main.cpp -std=c++17 -o build\main.o
    g++ -c Nodo\Nodo.cpp -std=c++17 -o build\Nodo.o
    g++ -c Cola\Cola.cpp -std=c++17 -o build\Cola.o
    g++ -c MatrizDispersa\NodoInterno.cpp -std=c++17 -o build\NodoInterno.o
    g++ -c MatrizDispersa\NodoCabecera.cpp -std=c++17 -o build\NodoCabecera.o
    g++ -c MatrizDispersa\ListaEncabezado.cpp -std=c++17 -o build\ListaEncabezado.o
    g++ -c MatrizDispersa\MatrizDispersa.cpp -std=c++17 -o build\MatrizDispersa.o
    g++ -c Pila\Pila.cpp -std=c++17 -o build\Pila.o
    g++ -c Jugador/Jugador.cpp -std=c++17 -o build\Jugador.o
    g++ -c Configuraciones/ConfiguracionInicial.cpp -std=c++17 -o build\ConfiguracionInicial.o


    echo.
    echo Enlazando objetos...
    g++ build\main.o build\Nodo.o build\Cola.o build\NodoInterno.o build\NodoCabecera.o build\ListaEncabezado.o build\MatrizDispersa.o build\Pila.o build\Jugador.o build\ConfiguracionInicial.o -o mi_programa.exe

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
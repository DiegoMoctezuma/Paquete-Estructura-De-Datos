#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//**** LISTAS SIMPLES,CIRCULARES - PILAS ****
struct Nodo{
    int Info;
    struct Nodo *Liga;
};

//**** LISTAS DOBLES - ARBOLES BINARIOS ****
struct NodoDoble{
    int Info;
    struct NodoDoble *LigaIzq, *LigaDer;
};

struct NodoDobleChar{
    char Info;
    struct NodoDobleChar *LigaIzq, *LigaDer;
};

//**** COLAS ****
struct NodoPrioridad{
    int Info, Prioridad;
    struct NodoPrioridad *Liga;
};
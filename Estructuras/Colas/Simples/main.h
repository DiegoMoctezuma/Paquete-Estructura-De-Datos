#include "../../Registros/main.h"

//Algoritmo 1
void PushCS(struct Nodo **P){
    int num;
    system("cls");
    if(*P == NULL){ //No hay elementos 
        printf("Ingrese la cantidad de elementos a agregar: ");
        scanf("%i",&num);
        
        //Primer elemento
        *P = (struct Nodo*)malloc(sizeof(struct Nodo));
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
        (*P)->Liga = NULL;

        num--;
        struct Nodo *Q = *P;
        for(int i = 0; i < num; i++){
            Q->Liga = (struct Nodo*)malloc(sizeof(struct Nodo));
            Q = Q->Liga;
            printf("Ingresa la informacion del nodo (entero): ");
            scanf("%i", &Q->Info);
            Q->Liga = NULL;
        }
    }else{  //Hay elementos
        struct Nodo *Q = *P;
        while(Q->Liga != NULL){ //Busca el ultimo nodo
            Q = Q->Liga;
        }
        printf("Ingrese la cantidad de elementos a agregar: ");
        scanf("%i",&num);

        for(int i = 0; i < num; i++){
            Q->Liga = (struct Nodo*)malloc(sizeof(struct Nodo));
            Q = Q->Liga;
            printf("Ingrese la informacion del nodo (entero): ");
            scanf("%i",&Q->Info);
            Q->Liga = NULL;
        }
    }
    system("cls");
}

//Algoritmo 2
void POPCS(struct Nodo **P){
    int num;
    if(*P == NULL){ //No hay elementos
        system("cls");
        printf("\nNo hay elementos en la lista.\n");
    }else if((*P)->Liga == NULL){//Solo hay un elemento
        free(*P);
        *P = NULL;
        system("cls");
    }else{ //Más de un elemento
        system("cls");
        printf("Ingrese la cantidad de elementos a eliminar: ");
        scanf("%i",&num);
        struct Nodo *Q = NULL;
        for(int i = 0; i < num; i++){
            Q = *P;
            *P = (*P)->Liga;
            free(Q);
        }
        system("cls");
    }
}

//Algoritmo 2
void imprimirCola(struct Nodo *P){
    system("cls");
    if(P == NULL){
        system("cls");
        printf("\nNo hay elementos.\n");
    }else {
        struct Nodo *Q = P;
        printf("\nElementos: ");
        while(Q != NULL){
            printf("%i, ",Q->Info);
            Q = Q->Liga;
        }
        printf("\n");
    }
}

void switchColasSimples(){
    struct Nodo *P = NULL;
    int algoritmo;
    system("cls");
    do{
        printf("\n(1) PUSH\n");
        printf("(2) POP\n");
        printf("(3) Imprimir elementos de la pila\n");
        printf("(4) Salir\n");
        printf("Selccione: ");
        scanf("%i",&algoritmo);
        switch(algoritmo){
            case 1:
                PushCS(&P);
            break;
            case 2:
                POPCS(&P);
            break;
            case 3:
                imprimirCola(P);
            break;
            case 4:
                system("cls");
            break;
            default:
            printf("Opcion no valida.\n");
        }
    }while(algoritmo != 4);

    if(P != NULL){
        if(P->Liga == NULL){
            free(P);
        }else{
            struct Nodo *Q = P;
            while(P->Liga != NULL){
                P = P->Liga;
                free(Q);
                Q = P;
            }
            free(P);
        }
    }
}
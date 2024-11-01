#include "../Registros/main.h"

//Algoritmo 1
void PUSH(struct Nodo **P){
    if(*P == NULL){ //No hay elementos
        *P = (struct Nodo*)malloc(sizeof(struct Nodo));
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
        (*P)->Liga = NULL;
    }else{  //Hay elementos
        struct Nodo *Q = *P;
        while(Q->Liga != NULL){ //Busca el ultimo nodo
            Q = Q->Liga;
        }
        Q->Liga = (struct Nodo*)malloc(sizeof(struct Nodo));
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&Q->Liga->Info);
        Q->Liga->Liga = NULL;
    }
    system("cls");
}

//Algoritmo 2
void POP(struct Nodo **P){
    struct Nodo *Q = NULL, *S = NULL;
    if(*P == NULL){
        system("cls");
        printf("\nNo hay elementos que eliminar\n");
    }else{
        if((*P)->Liga == NULL){ //Solo hay un elemento
            free(*P);
            *P = NULL;
        }else{ // Hay más de un elemento en la lista
            Q = *P;
            //Recorre la lista hasta la ultima posicion
            while(Q->Liga != NULL){
            S = Q;
            Q = Q->Liga;
            }
            //Elimina el ultimo y actualiza el penultimo
            free(Q); 
            S->Liga = NULL;
        }
        system("cls");
    }
}

//Algoritmo 3
void imprimirPila(struct Nodo *P){
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

void switchPilas(){
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
                PUSH(&P);
            break;
            case 2:
                POP(&P);
            break;
            case 3:
                imprimirPila(P);
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
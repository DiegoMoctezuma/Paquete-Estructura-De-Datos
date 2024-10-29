#include"../../Registros/main.h"

//Algoritmo 1
void PushColaPrioridad(struct NodoPrioridad **P){
    int num;
    system("clear");
    if(*P == NULL){ //No hay elementos 
        printf("Ingrese la cantidad de elementos a agregar: ");
        scanf("%i",&num);
        
        //Primer elemento
        *P = (struct NodoPrioridad*)malloc(sizeof(struct NodoPrioridad));
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
        printf("Ingrese la prioridad del elemento (1-5): ");
        scanf("%i",&(*P)->Prioridad);
        (*P)->Liga = NULL;

        num--;
        struct NodoPrioridad *Q = *P;
        for(int i = 0; i < num; i++){
            Q->Liga = (struct NodoPrioridad*)malloc(sizeof(struct NodoPrioridad));
            Q = Q->Liga;
            printf("Ingresa la informacion del nodo (entero): ");
            scanf("%i", &Q->Info);
            printf("Ingrese la prioridad del elemento (1-5): ");
            scanf("%i", &Q->Prioridad);
            Q->Liga = NULL;
        }
    }else{  //Hay elementos
        struct NodoPrioridad *Q = *P;
        while(Q->Liga != NULL){ //Busca el ultimo nodo
            Q = Q->Liga;
        }
        printf("Ingrese la cantidad de elementos a agregar: ");
        scanf("%i",&num);

        for(int i = 0; i < num; i++){
            Q->Liga = (struct NodoPrioridad*)malloc(sizeof(struct NodoPrioridad));
            Q = Q->Liga;
            printf("Ingrese la informacion del nodo (entero): ");
            scanf("%i",&Q->Info);
            printf("Ingrese la prioridad del elemento (1-5): ");
            scanf("%i",&Q->Prioridad);
            Q->Liga = NULL;
        }
    }
    system("clear");
}

//Algoritmo -
/* void eliminarElemento(struct NodoPrioridad **P, struct NodoPrioridad *D){
    struct NodoPrioridad *Q = NULL, *S = NULL;
    
    //Busca el elemento en la lista
    Q = *P;
    while (Q != D){
        S = Q;
        Q = Q->Liga;
    }

    if (Q == *P){ //Es el primer elemento
        if(Q->Liga == NULL){ //Es el unico elemento
            free(Q);
            *P = NULL;
        } else {
            *P = Q->Liga;
            free(Q);
        }
    } else if (Q->Liga == NULL){ //Es el ultimo elemento
        S->Liga = NULL;
        free(Q);
    } else { //Cualquier otro elemento
        S->Liga = Q->Liga;
        free(Q);
    }
} */

//Algoritmo 2
void imprimirColaPrioridad(struct NodoPrioridad **P){
    system("clear");
    if(*P == NULL){
        system("clear");
        printf("\nNo hay elementos.\n");
    }else {
        struct NodoPrioridad *Q;
        printf("\nElementos: ");
        for(int i = 1; i <=5; i++){
            Q = *P;
            while(Q != NULL){
                if(Q->Prioridad == i){
                    printf("%i, ",Q->Info);
                }
                Q = Q->Liga;
            }
        }
        printf("\n");
    }

    struct NodoPrioridad *Q;
    while (*P != NULL) {
        Q = *P;
        *P = (*P)->Liga;
        free(Q);
    }
    *P = NULL;
}

void switchColasPrioridad(){
    struct NodoPrioridad *P = NULL;
    int subEstructura;
    system("clear");
    do{
        printf("\n(1) Agregar elementos \n(2) Imprimir elementos \n(3) Salir \nSeleccione: ");
        scanf("%i",&subEstructura);
        switch(subEstructura){
            case 1:
                PushColaPrioridad(&P);
            break;
            case 2:
                imprimirColaPrioridad(&P);
            break;
            case 3:
                system("clear");
            break;
            default:
                system("clear");
                printf("Opcion no valida.\n");
        }
    }while(subEstructura != 3);
}
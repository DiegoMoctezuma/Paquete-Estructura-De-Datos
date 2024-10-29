#include "../../Registros/main.h"

//Algoritmo 1
void PushFinal(struct Nodo **P){
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
    system("clear");
}

//Algoritmo 2
void PushPrincipal(struct Nodo **P){
    struct Nodo *Q = NULL;
    if(*P == NULL){ //No hay elementos
        *P = (struct Nodo*)malloc(sizeof(struct Nodo));
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
        (*P)->Liga = NULL;
    }else{ //Hay elementos
        Q = (struct Nodo*)malloc(sizeof(struct Nodo));
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&Q->Info);
        Q->Liga = *P;
        *P = Q;
    }
    system("clear");
}

//Algoritmo 3
void PopPrincipio(struct Nodo **P){
    if(*P == NULL){ //No hay elementos
        system("clear");
        printf("\nNo hay elementos en la lista.\n");
    }else if((*P)->Liga == NULL){//Solo hay un elemento
        free(*P);
        *P = NULL;
        system("clear");
    }else{ //Más de un elemento
        struct Nodo *Q = *P;
        *P = Q->Liga;
        free(Q);
        system("clear");
    }
}

//Algoritmo 4
void PopFinal(struct Nodo **P){
    struct Nodo *Q = NULL, *S = NULL;
    if(*P == NULL){
        system("clear");
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
        system("clear");
    }
}

//Algoritmo 5
void imprimirBicola(struct Nodo *P){
    system("clear");
    if(P == NULL){
        system("clear");
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


void switchBicolas(){
    struct Nodo *P = NULL;
    int bicola,algoritmo,res;
    system("clear");
    do{
        printf("\n(1) Bicola entrada restringida\n");
        printf("(2) Bicola salida restringida\n");
        printf("(3) Salir\n");
        printf("Selccione: ");
        scanf("%i",&bicola);
        switch(bicola){
            //Bicola entrada restringida
            case 1:
                system("clear");
                do{
                    printf("\n(1) Push\n");
                    printf("(2) POP\n");
                    printf("(3) Imprimir\n");
                    printf("(4) Salir\n");
                    printf("Selccione: ");
                    scanf("%i",&algoritmo);
                    switch(algoritmo){
                        case 1:
                            PushFinal(&P);
                        break;
                        case 2:
                            system("clear");
                            printf("(1) Pop por el principio\n(2) Pop por el final");
                            printf("\nSeleccione: ");
                            scanf("%i",&res);
                            switch(res){
                                case 1:
                                    PopPrincipio(&P);
                                break;
                                case 2:
                                    PopFinal(&P);
                                break;
                                default:
                                    system("clear");
                                    printf("\nOpcion no valida.");
                            }
                        break;
                        case 3:
                            imprimirBicola(P);
                        break;
                        case 4:
                            system("clear");
                        break;
                        default:
                            printf("\nOpcion no valida.");
                    }
                }while(algoritmo != 4);
            break;
            //Bicola salida restringida
            case 2:
                system("clear");
                do{
                    printf("\n(1) Push\n");
                    printf("(2) POP\n");
                    printf("(3) Imprimir\n");
                    printf("(4) Salir\n");
                    printf("Selccione: ");
                    scanf("%i",&algoritmo);
                    switch(algoritmo){
                        case 1:
                            system("clear");
                            printf("(1) Push por el principio\n(2) Push por el final");
                            printf("\nSeleccione: ");
                            scanf("%i",&res);
                            switch(res){
                                case 1:
                                    PushPrincipal(&P);
                                break;
                                case 2:
                                    PushFinal(&P);
                                break;
                                default:
                                    system("clear");
                                    printf("\nOpcion no valida.");
                            }
                        break;
                        case 2:
                            PopPrincipio(&P);
                        break;
                        case 3:
                            imprimirBicola(P);
                        break;
                        case 4:
                            system("clear");
                        break;
                        default:
                            printf("\nOpcion no valida.");
                    }
                }while(algoritmo != 4);
            break;
            case 3:
                system("clear");
            break;
            default:
            printf("Opcion no valida.\n");
        }
    }while(bicola != 3);

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
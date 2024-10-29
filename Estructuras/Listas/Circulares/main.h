#include "../../Registros/main.h"

//Algoritmo 1
void creacionListaAgregarFinal(struct Nodo **P){
    struct Nodo *Q = NULL;
    char resp;

    *P = (struct Nodo*)malloc(sizeof(struct Nodo));
    system("clear");
    printf("Ingrese la informacion del nodo (entero): ");
    scanf("%i",&(*P)->Info);
    (*P)->Liga = *P;
    Q = *P;

    printf("¿Ingresar otro numero? (S/N): ");
    scanf(" %c",&resp);

    while(resp != 'n' && resp != 'N'){
        Q->Liga = (struct Nodo*)malloc(sizeof(struct Nodo));
        Q = Q->Liga;
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&Q->Info);
        Q->Liga = *P;
        printf("¿Ingresar otro numero? (S/N): ");
        scanf(" %c",&resp);
    }
    system("clear");
}

//Algoritmo 2
void imprimirNodosCirculares(struct Nodo *P){
    system("clear");
    if(P == NULL){
        system("clear");
        printf("\nNo hay elementos.\n");
    }else {
        struct Nodo *Q = P;
        printf("\nElementos: ");
        while(Q->Liga != P){
            printf("%i, ",Q->Info);
            Q = Q->Liga;
        }
        printf("%i",Q->Info);
        printf("\n");
    }
}

//Algoritmo 3
void eliminarNodoPrincipioCirc(struct Nodo **P){
    struct Nodo *Q = NULL;
    system("clear");
    if(P == NULL){
        system("clear");
        printf("\nNo hay elementos.\n");
    }else if((*P)->Liga == *P){
        free(*P);
        *P = NULL;
    }else{
        Q = *P;
        while(Q->Liga != *P){
            Q = Q->Liga;
        }
        Q->Liga = (*P)->Liga;
        free(*P);
        *P = Q->Liga;
    }
}

//Algoritmo 4
void buscaElementoImprimirDirecciones(struct Nodo *P){
    struct Nodo *Q = NULL, *R = NULL;
    int x;
    if(P == NULL){
        system("clear");
        printf("\nNo hay elementos en la lista.\n");
    }else if(P->Liga == P){
        system("clear");
        imprimirNodosCirculares(P);
        printf("\nSolo hay un elemento en la lista.\n");
    }else{
        system("clear");
        printf("Ingresa el elemento a buscar: ");
        scanf("%i",&x);
        Q = P;

        while(Q->Info != x && Q->Liga != P){
            R = Q;
            Q = Q->Liga;
        }

        if(Q == P){
            R = Q;
            while(R->Liga != P){
                R = R->Liga;
            }
            printf("\nEl elemento '%i' esta en la lista\n",x);
            printf("Direccion del nodo antecedente: %p\n",R->Liga);
            printf("Direccion del nodo consecuente: %p\n",Q->Liga->Liga);
        }else if(Q->Info == x){
            printf("\nEl elemento '%i' esta en la lista\n",x);
            printf("Direccion del nodo antecedente: %p\n",R->Liga);
            printf("Direccion del nodo consecuente: %p\n",Q->Liga->Liga);
        }else{
            printf("\nEl elemento '%i' no esta en la lista\n",x);
        }
    }
}

//Algoritmo 5
void insertarNodoAntesDeOtroCir(struct Nodo **P){
    struct Nodo *Q = NULL, *S = NULL, *T = NULL;
    int x;
    system("clear");
    printf("Inserta un nodo antes de un nodo especifico.\n");

    if (*P == NULL){ //No hay elementos en la lista -  agrega un nuevo elemento
        *P = (struct Nodo*)malloc(sizeof(struct Nodo));
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
        (*P)->Liga = *P;
    } else{ //Hay más de un elemento
        printf("Ingresa el elemento a buscar: ");
        scanf("%i",&x);
        Q = *P;
        //Busca el elemento
        while (Q->Info != x && Q->Liga!=(*P)){
            S = Q;
            Q = Q->Liga; 
        }

        if (Q->Info != x){ //No existe el elemento
            system("clear");
            printf("\nEl nodo con informacion '%i' no existe.\n",x);
        } else if (Q == *P){ //Es el primer elemento
            if(Q->Liga != *P){
                T = Q;
                while (T->Liga != *P){
                    T = T->Liga; 
                }
                T->Liga = (struct Nodo*)malloc(sizeof(struct Nodo));
                T = T->Liga;
                printf("Ingrese la informacion del nodo (entero): ");
                scanf("%i",&T->Info);
                T->Liga = *P;
                system("clear");
            }else{
                T = (struct Nodo*)malloc(sizeof(struct Nodo));
                printf("Ingrese la informacion del nodo (entero): ");
                scanf("%i",&T->Info);
                (*P)->Liga = T;
                T->Liga = *P;
                *P = T;
                system("clear");
            }
        } else { //Cualquier otro elemento
            T = (struct Nodo*)malloc(sizeof(struct Nodo));
            printf("Ingrese la informacion del nodo (entero): ");
            scanf("%i",&T->Info);
            S->Liga = T;
            T->Liga = Q;
            system("clear");
        }
    }
}

//Algoritmo 6
void insertaNodoAlPrincipio(struct Nodo **P){
    struct Nodo *Q = NULL, *S = NULL;
    if(*P == NULL){
        system("clear");
        *P = (struct Nodo*)malloc(sizeof(struct Nodo));
        
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
        (*P)->Liga = *P;
        system("clear");
    } else {
        system("clear");
        Q = (struct Nodo*)malloc(sizeof(struct Nodo));

        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&Q->Info);
        Q->Liga = *P;
        
        S = *P;
        //BUSCA ULTIMO ELEMENTO
        while (S->Liga != *P){
            S = S->Liga;
        }
        S->Liga = Q;
        *P = Q;
        system("clear");
    }
}

//Algoritmo 7
void eliminaUltimoNodoCir(struct Nodo **P){
    struct Nodo *Q = NULL, *R = NULL;
    if(*P == NULL){
        system("clear");
        printf("\nNo hay elementos en la lista.\n");
    }else if((*P)->Liga == *P){
        free(*P);
        *P = NULL;
        system("clear");
    }else{
        Q = *P;
        while(Q->Liga != *P){
            R = Q;
            Q = Q->Liga;
        }
        R->Liga = *P;
        free(Q);
        system("clear");
    }
}

//Algoritmo 8
void eliminaUnoDespuesEspecifico(struct Nodo **P){
    struct Nodo *Q = NULL, *T = NULL;
    int x;

    if(*P == NULL){
        system("clear");
        printf("\nNo hay elementos en la lista.\n");
    }else{
        printf("Ingresa el elemento a buscar: ");
        scanf("%i",&x);
        if((*P)->Liga == *P && x == (*P)->Info){
            free(*P);
            *P = NULL;
            system("clear");
        }else{
            Q = *P;
            while(Q->Info != x && Q->Liga != *P){
                Q = Q->Liga;
            }
            if(Q->Info != x){
                system("clear");
                printf("\nEl nodo con informacion '%i' no existe.\n",x);
            }else{
                if(Q->Liga == *P){
                    Q->Liga = (*P)->Liga;
                    free(*P);
                    *P = Q->Liga;
                }else{
                    T = Q->Liga;
                    Q->Liga = T->Liga;
                    free(T);
                }
                system("clear");
            }
        }
    }
}


void switchListasCirculares(){
    struct Nodo *P = NULL;
    int algoritmo;

    system("clear");
    do{
        printf("\n(1) Algoritmo que crea una lista circular por el final\n");
        printf("(2) Algoritmo que imprime el contenido de una lista circular\n");
        printf("(3) Algoritmo que elimina el primer elemento de una lista circular\n");
        printf("(4) Algoritmo que busca un elemento con información dada por el usuario e imprime la dirección del elemento antecedente y consecuente\n");
        printf("(5) Algoritmo que inserta un nodo antes de uno especifico\n");
        printf("(6) Algoritmo que inserta un elemento al principio de la lista\n");
        printf("(7) Algoritmo que elimina el ultimo nodo de la lista\n");
        printf("(8) Algoritmo que elimina un nodo despues de uno especifico\n");
        printf("(9) Salir\n");
        printf("Selccione: ");
        scanf("%i",&algoritmo);
        switch(algoritmo){
            case 1:
                creacionListaAgregarFinal(&P);
            break;
            case 2:
                imprimirNodosCirculares(P);
            break;
            case 3:
                eliminarNodoPrincipioCirc(&P);
            break;
            case 4:
                buscaElementoImprimirDirecciones(P);
            break;
            case 5:
                insertarNodoAntesDeOtroCir(&P);
            break;
            case 6:
                insertaNodoAlPrincipio(&P);
            break;
            case 7:
                eliminaUltimoNodoCir(&P);
            break;
            case 8:
                eliminaUnoDespuesEspecifico(&P);
            break;
            case 9:
                system("clear");
            break;
            default:
                system("clear");
                printf("Opcion no valida.\n");
        }
    }while(algoritmo!=9);
}
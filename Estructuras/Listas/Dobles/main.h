#include "../../Registros/main.h"

//Algoritmo 1
void crearListaInsertaFinal(struct NodoDoble **P, struct NodoDoble **F){
    char resp;
    system("cls");
    (*P) = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
    *F = *P;
    (*P)->LigaIzq = NULL;
    (*P)->LigaDer = NULL;
    printf("Ingrese la informacion del nodo (entero): ");
    scanf("%i",&(*P)->Info);
    printf("¿Insertar más datos? (S/N): ");
    scanf(" %c",&resp);
    while(resp == 's' || resp == 'S'){
        system("cls");
        (*F)->LigaDer = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
        (*F)->LigaDer->LigaIzq = *F;
        *F = (*F)->LigaDer;
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*F)->Info);
        (*F)->LigaDer = NULL;
        printf("¿Insertar más datos? (S/N): ");
        scanf(" %c",&resp);
    }
    system("cls");
}

//Algoritmo 2
void imprimirNodosPrincipioFinal(struct NodoDoble *P, struct NodoDoble *F, int defecto){
    struct NodoDoble *Q = NULL;
    int resp;
    system("cls");
    if(P == NULL){
        printf("\nNo hay elementos.\n");
    }else if(P->LigaDer == NULL){
        printf("\nElementos: %i\n",P->Info);
    }else {
        if(defecto == 0){
            printf("¿Imprimir la lista por la (1)izquierda o (2)derecha: ");
            scanf("%i",&resp);
        }else{
            resp = 1;
        }
        if(resp == 1){
            Q = P;
            printf("\nElementos: ");
            while(Q != NULL){
                printf("%i, ",Q->Info);
                Q = Q->LigaDer;
            }
            printf("\n");
        }else{
            Q = F;
            printf("\nElementos: ");
            while(Q != NULL){
                printf("%i, ",Q->Info);
                Q = Q->LigaIzq;
            }
            printf("\n");
        }
    }
}

//Algoritmo 3
void eliminarUltimoElementoListaDoble(struct NodoDoble **P,struct NodoDoble **F){
    if(P == NULL){
        system("cls");
        printf("\nNo hay elementos.\n");
    }else if((*P)->LigaDer == NULL){
        free(*P);
        *P = NULL;
        system("cls");
    }else{
        *F = (*F)->LigaIzq;
        free((*F)->LigaDer);
        (*F)->LigaDer = NULL;
        system("cls");
    }
}

//Algoritmo 4
void eliminarNodoEspecificoDoble(struct NodoDoble **P,struct NodoDoble **F){
    struct NodoDoble *Q = NULL;
    int x = 0;

    if(*P == NULL){
        system("cls");
        printf("\nNo hay elementos.\n");
    }else{
        system("cls");
        Q = *P;
        imprimirNodosPrincipioFinal(*P,*F,1);
        printf("Inserta el elemento a buscar: ");
        scanf("%i",&x);
        //Busca el elemento en la lista
        while (Q->Info != x && Q->LigaDer!=NULL){
            Q = Q->LigaDer; 
        }
        if(Q->Info != x){
            system("cls");
            printf("El elemento '%i' no existe.\n",x);
        }else if(Q == *P){
            *P = Q->LigaDer;
            (*P)->LigaIzq = NULL;
            free(Q);
        }else if(Q == *F){
            *F = Q->LigaIzq;
            (*F)->LigaDer = NULL;
            free(Q);
        }else{
            Q->LigaIzq->LigaDer = Q->LigaDer;
            Q->LigaDer->LigaIzq = Q->LigaIzq;
            free(Q);
        }
    }
}

//Allgoritmo 5
void eliminarNodoAntesDeOtro(struct NodoDoble **P){
    struct NodoDoble *Q = NULL;
    
    int x = 0;
    if(*P == NULL){
        system("cls");
        printf("\nNo hay elementos.\n");
    }else{
        system("cls");
        Q = *P;
        imprimirNodosPrincipioFinal(*P,Q,1);
        printf("Inserta el elemento a buscar: ");
        scanf("%i",&x);

        //Busca el elemento en la lista
        while (Q->Info != x && Q->LigaDer!=NULL){
            Q = Q->LigaDer; 
        }

        if(Q->Info != x){
            system("cls");
            printf("El elemento '%i' no existe.\n",x);
        }else if(Q == *P){
            system("cls");
            printf("No se puede eliminar el nodo anterior al primero.\n");
        }else if (Q->LigaIzq == *P){
            Q->LigaIzq = NULL;
            free(*P);
            *P = Q;
            system("cls");
        } 
        else {
            Q->LigaIzq = Q->LigaIzq->LigaIzq;
            free(Q->LigaIzq->LigaDer);
            Q->LigaIzq->LigaDer = Q;
            system("cls");
        }
    }
}


//Algoritmo 6
void inserteNodoPrincipio(struct NodoDoble **P,struct NodoDoble **F){
    struct NodoDoble *Q = NULL;
    system("cls");
    if(*P == NULL){
        (*P) = (struct NodoDoble *)malloc(sizeof(struct NodoDoble));
        (*P)->LigaIzq = NULL;
        (*P)->LigaDer = NULL;
        *F = *P;
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
    }else{
        Q = (struct NodoDoble *)malloc(sizeof(struct NodoDoble));
        Q->LigaIzq = NULL;
        Q->LigaDer = *P;
        (*P)->LigaIzq = Q;
        *P = Q;
        printf("Ingrese la informacion del nodo (entero): ");
        scanf("%i",&(*P)->Info);
    }
}

//Algoritmo 7 
void insertaNodoDespuesDeNodo(struct NodoDoble *P,struct NodoDoble **F){
    struct NodoDoble *Q = NULL,*U = NULL;
    int x;
    
    if (P == NULL){ //Si no hay elementos
        system("cls");
        printf("\nNo hay elementos.\n");
    } else {//Si hay elementos
        system("cls");
        imprimirNodosPrincipioFinal(P,*F,1);
        printf("Inserta el elemento a buscar: ");
        scanf("%i",&x);
        Q = P;

        while(Q->Info != x && Q->LigaDer != NULL){
            Q = Q->LigaDer;
        }

        if (Q->Info != x){ //Si el elemento no existe
            system("cls");
            printf("El elemento '%i' no existe.\n",x);
        } else {
            if (Q->LigaDer == NULL){ //Si el nodo es el ultimo
                (*F)->LigaDer = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
                *F = (*F)->LigaDer;
                (*F)->LigaIzq = Q;
                printf("Ingrese la informacion del nodo (entero): ");
                scanf("%i",&(*F)->Info);
                (*F)->LigaDer = NULL;
                system("cls");
            } else { //Si el nodo no es el ultimo
                U = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
                U->LigaIzq = Q;
                U->LigaDer = Q->LigaDer;
                printf("Ingrese la informacion del nodo (entero): ");
                scanf("%i",&U->Info);
                Q->LigaDer->LigaIzq = U;
                Q->LigaDer = U;
                system("cls");
            }
        }
    }
}

//Algoritmo 8
void esPalindromo(struct NodoDobleChar **P,struct NodoDobleChar **F){
    char palabra[50];
    int aux = 0;

    system("cls");
    printf("Inserte la palabra: ");
    scanf("%s",palabra);

    //Guardado del string en una lista doble
    *P = (struct NodoDobleChar *)malloc(sizeof(struct NodoDobleChar));
    (*P)->LigaIzq = NULL;
    (*P)->LigaDer = NULL;
    *F = *P;

    for(int i = 0; palabra[i] != '\0'; i++){
        (*F)->Info = palabra[i];
        if(palabra[i+1] != '\0'){
            (*F)->LigaDer = (struct NodoDobleChar *)malloc(sizeof(struct NodoDobleChar));
            (*F)->LigaDer->LigaIzq = *F;
            *F = (*F)->LigaDer;
        }
    }

    //Verificacion si es un palindromo
    if(*P == NULL){
        system("cls");
        printf("No se puede comparar.\n");
    }else {
        struct NodoDobleChar *Q = *P;
        struct NodoDobleChar *R = *F;
        //Izquierda a derecha
        while(Q != NULL){
            printf(" %c - ",toupper(Q->Info));
            Q = Q->LigaDer;
        }
        printf("\n");
        //Derecha a izquierda
        while(R != NULL){
            printf(" %c - ",toupper(R->Info));
            R = R->LigaIzq;
        }
        printf("\n");
        Q = *P;
        R = *F;
        while(Q != NULL && R != NULL){
            if(tolower(Q->Info) == tolower(R->Info)){
                aux = 1;
            }else{
                aux = 0;
                break;
            }
            Q = Q->LigaDer;
            R = R->LigaIzq;
        }
        if(aux){
            printf("La palabra '%s' es un palindromo.\n",palabra);
        }else{
            printf("La palabra '%s' no es un palindromo.\n",palabra);
        }
        Q = *P;
        while(Q != *F){
            Q = Q->LigaDer;
            free(Q->LigaIzq);
        }
        free(Q);
        *P = NULL;
        *F = NULL;
    }
}


void switchListasDobles(){
    struct NodoDoble *P = NULL, *F = NULL;
    struct NodoDobleChar *PC = NULL, *FC = NULL;
    int algoritmo;

    system("cls");
    do{
        printf("\n(1) Algoritmo que crea una lista doblemente ligada insertando a cada elemento por el final\n");
        printf("(2) Algoritmo que imprime el contenido de una lista doblemente ligada\n");
        printf("(3) Algoritmo que elimina el ultimo elemento\n");
        printf("(4) Algoritmo que elimina un elemento con información dada por el usuario\n");
        printf("(5) Algoritmo que elimina un elemento antes de otro nodo especifico\n");
        printf("(6) Algoritmo que inserta un elemento al principio de la lista.\n");
        printf("(7) Algoritmo que inserta un elemento despues de un nodo especifico\n");
        printf("(8) Algoritmo que determina si es un palindromo\n");
        printf("(9) Salir\n");
        printf("Selccione: ");
        scanf("%i",&algoritmo);
        switch(algoritmo){
            case 1:
                crearListaInsertaFinal(&P,&F);
            break;
            case 2:
                imprimirNodosPrincipioFinal(P,F,0);
            break;
            case 3:
                eliminarUltimoElementoListaDoble(&P,&F);
            break;
            case 4:
                eliminarNodoEspecificoDoble(&P,&F);
            break;
            case 5:
                eliminarNodoAntesDeOtro(&P);
            break;
            case 6:
                inserteNodoPrincipio(&P,&F);
            break;
            case 7:
                insertaNodoDespuesDeNodo(P,&F);
            break;
            case 8:
                esPalindromo(&PC,&FC);
            break;
            case 9:
                system("cls");
            break;
            default:
                printf("Opcion no valida.\n");
        }
    }while(algoritmo!=9);

    if(P != NULL){
        if(P == F){
            free(P);
        }else{
            struct NodoDoble *Q = P;
            while(Q != F){
                Q = Q->LigaDer;
                free(Q->LigaIzq);
            }
            free(Q);
        }
    }
}
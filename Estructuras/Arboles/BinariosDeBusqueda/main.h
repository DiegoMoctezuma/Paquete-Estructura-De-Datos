#include"../../Registros/main.h"

//Algoritmo 1
void insertarABB(struct NodoDoble **Raiz, int dato){
    int dato;
    printf("Dame el dato: ");
    scanf("%i",&dato);
    if(*Raiz == NULL){
        *Raiz = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
        (*Raiz)->Info = dato;
        (*Raiz)->LigaIzq = NULL;
        (*Raiz)->LigaDer = NULL;
    } else {
        insercion(Raiz,dato);
    }
}

void insercion(struct NodoDoble **Raiz, int dato){
    if(dato < (*Raiz)->Info){
        if((*Raiz)->LigaIzq == NULL){
            (*Raiz)->LigaIzq = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
            (*Raiz)->LigaIzq->Info = dato;
            (*Raiz)->LigaIzq->LigaIzq = NULL;
            (*Raiz)->LigaIzq->LigaDer = NULL;
        } else {
            insercion(&(*Raiz)->LigaIzq,dato);
        }
    } else {
        if((*Raiz)->LigaDer == NULL){
            (*Raiz)->LigaDer = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
            (*Raiz)->LigaDer->Info = dato;
            (*Raiz)->LigaDer->LigaIzq = NULL;
            (*Raiz)->LigaDer->LigaDer = NULL;
        } else {
            insercion(&(*Raiz)->LigaDer,dato);
        }
    }
}


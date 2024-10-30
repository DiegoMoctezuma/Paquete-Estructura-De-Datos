#include"../../Registros/main.h"

//Algoritmo 1
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

void insertarABB(struct NodoDoble **Raiz){
    int dato;
    system("clear");
    printf("Inserta la informacion: ");
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

//Algoritmo impresin *** Solo para comprobar ****
void impresionABB(struct NodoDoble *Raiz){
    if(Raiz != NULL){
        impresionABB(Raiz->LigaIzq);
        printf("%i ",Raiz->Info);
        impresionABB(Raiz->LigaDer);
    }
}

//Algoritmo 2 busqueda
void busqueda(struct NodoDoble *Raiz, int x){
    if(Raiz->Info == x){
        system("clear");
        printf("El dato %i se encuentra en el arbol\n",x);
    }else{
        if(x < Raiz->Info){
            if(Raiz->LigaIzq == NULL){
                system("clear");
                printf("El dato %i no se encuentra en el arbol\n",x);
            }else{
                busqueda(Raiz->LigaIzq,x);
            }
        }else{
            if(Raiz->LigaDer == NULL){
                system("clear");
                printf("El dato %i no se encuentra en el arbol\n",x);
            }else{
                busqueda(Raiz->LigaDer,x);
            }
        }
    }
}

void buscarElemento(struct NodoDoble *Raiz){
    if(Raiz == NULL){
        system("clear");
        printf("El arbol esta vacio\n");
    }else{
        int x;
        printf("Inserte el dato a buscar: ");
        scanf("%i",&x);
        busqueda(Raiz,x);
    }
}

//Algoritmo 3 eliminacion *** Pendiente ***

//Algoritmo liberar memoria
void liberarMemoriaABB(struct NodoDoble *Raiz){
    if(Raiz != NULL){
        liberarMemoriaABB(Raiz->LigaIzq);
        liberarMemoriaABB(Raiz->LigaDer);
        free(Raiz);
    }
}

void switchABB(){
    struct NodoDoble *Raiz = NULL;
    int subEstructura;
    
    do{
        printf("\n(1) Insertar en arbol \n(2) Buscar en arbol \n(3) Eliminar en arbol \n(4) Imprimir alrbol ordenado  \n(5) Salir \nSeleccione: ");
        scanf("%i",&subEstructura);
        switch(subEstructura){
            case 1:
                insertarABB(&Raiz);
            break;
            case 2:
                buscarElemento(Raiz);
            break;
            case 3:
                //impresionABB(Raiz);
                system("clear");
                printf("En construccion\n");
            break;
            case 4:
                system("clear");
                impresionABB(Raiz);
            case 5:
                system("clear");
            break;
            
        }
    }while(subEstructura != 5);
    liberarMemoriaABB(Raiz);
}

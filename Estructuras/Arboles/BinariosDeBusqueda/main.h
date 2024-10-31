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
void busqueda(struct NodoDoble *Raiz, int x, struct NodoDoble **nodoEncontrado, struct NodoDoble **nodoPadre) {
    *nodoEncontrado = NULL;
    *nodoPadre = NULL;
    struct NodoDoble *actual = Raiz;
    struct NodoDoble *padre = NULL;

    while (actual != NULL) {
        if (actual->Info == x) {
            *nodoEncontrado = actual;
            *nodoPadre = padre;
            return;
        }
        
        padre = actual;
        if (x < actual->Info) {
            actual = actual->LigaIzq;
        } else {
            actual = actual->LigaDer;
        }
    }
}

// Función para buscar un elemento en el ABB
void buscarElemento(struct NodoDoble *Raiz) {
    if (Raiz == NULL) {
        printf("El arbol esta vacio\n");
    } else {
        int x;
        printf("Inserte el dato a buscar: ");
        scanf("%i", &x);
        struct NodoDoble *nodoEncontrado = NULL;
        struct NodoDoble *nodoPadre = NULL;
        busqueda(Raiz, x, &nodoEncontrado, &nodoPadre);
        if (nodoEncontrado != NULL) {
            printf("El dato %i se encuentra en el arbol\n", x);
            if (nodoPadre != NULL) {
                printf("El padre del nodo es %i\n", nodoPadre->Info);
            } else {
                printf("El nodo es la raiz del arbol\n");
            }
        } else {
            printf("El dato %i no se encuentra en el arbol\n", x);
        }
    }
}

// Función que obtiene el mínimo de un árbol o sub-árbol
struct NodoDoble* obtenerMinimo(struct NodoDoble* Nodo) {
    struct NodoDoble* Rafa = Nodo;
    while (Rafa && Rafa->LigaIzq != NULL) {
        Rafa = Rafa->LigaIzq;
    }
    return Rafa;
}

// Función para encontrar el sucesor de un nodo
struct NodoDoble* encuentraSucesor(struct NodoDoble *Nodo, struct NodoDoble *Raiz) {
    // Si tiene hijo derecho
    if (Nodo->LigaDer != NULL) {
        return obtenerMinimo(Nodo->LigaDer);
    }
    // Si no tiene hijo derecho
    struct NodoDoble *Sucesor = NULL;
    struct NodoDoble *Actual = Raiz;
    while (Actual != NULL) {
        if (Nodo->Info < Actual->Info) {
            Sucesor = Actual;
            Actual = Actual->LigaIzq;
        } else if (Nodo->Info > Actual->Info) {
            Actual = Actual->LigaDer;
        } else {
            break;
        }
    }
    return Sucesor;
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

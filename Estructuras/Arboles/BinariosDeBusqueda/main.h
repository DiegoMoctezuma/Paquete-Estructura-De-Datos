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
void busquedaSimple(struct NodoDoble *Raiz, int x){
    if(Raiz->Info == x){
        system("clear");
        printf("El dato %i se encuentra en el arbol\n",x);
    }else{
        if(x < Raiz->Info){
            if(Raiz->LigaIzq == NULL){
                system("clear");
                printf("El dato %i no se encuentra en el arbol\n",x);
            }else{
                busquedaSimple(Raiz->LigaIzq,x);
            }
        }else{
            if(Raiz->LigaDer == NULL){
                system("clear");
                printf("El dato %i no se encuentra en el arbol\n",x);
            }else{
                busquedaSimple(Raiz->LigaDer,x);
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
        busquedaSimple(Raiz,x);
    }
}

//Algoritmo 3 eliminacion 
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
struct NodoDoble* obtenerMinimo(struct NodoDoble* Nodo) {// Función que obtiene el mínimo de un árbol o sub-árbol
    struct NodoDoble* Actual = Nodo;
    while (Actual && Actual->LigaIzq != NULL) {
        Actual = Actual->LigaIzq;
    }
    return Actual;
}
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

void eliminaNodo(struct NodoDoble **Raiz, int x) {
    struct NodoDoble *AUX1 = NULL, *AUX2 = NULL;
    busqueda(*Raiz, x, &AUX1, &AUX2);
    //AUX1 ES EL NODO A ELIMINAR, AUX2 ES SU PAPA

    if (AUX1 == NULL) {
        printf("El dato no esta en el arbol\n");
        return;
    }
    // CASO 1: NODO TERMINAL (sin hijos)
    if (AUX1->LigaIzq == NULL && AUX1->LigaDer == NULL) {
        if (AUX2 == NULL) { // Es la raíz
            *Raiz = NULL;
        } else {
            if (AUX2->LigaIzq == AUX1) {
                AUX2->LigaIzq = NULL;
            } else {
                AUX2->LigaDer = NULL;
            }
        }
        free(AUX1);
    }
    // CASO 2: UN SOLO HIJO
    else if (AUX1->LigaIzq == NULL || AUX1->LigaDer == NULL) {
        struct NodoDoble *Hijo = (AUX1->LigaIzq != NULL) ? AUX1->LigaIzq : AUX1->LigaDer;

        if (AUX2 == NULL) { // Es la raíz
            *Raiz = Hijo;
        } else {
            if (AUX2->LigaIzq == AUX1) {
                AUX2->LigaIzq = Hijo;
            } else {
                AUX2->LigaDer = Hijo;
            }
        }
        free(AUX1);
    }
    // CASO 3: DOS HIJOS
    else {
        struct NodoDoble *sucesor = encuentraSucesor(AUX1, *Raiz);
        AUX1->Info = sucesor->Info;
        eliminaNodo(&(AUX1->LigaDer), sucesor->Info);
    }
}

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
                eliminaNodo(&Raiz);
            break;
            case 4:
                system("clear");
                int x;
                printf("Inserte el dato a eliminar: ");
                scanf("%d", &x);
                eliminaNodo(&Raiz, x);
            case 5:
                system("clear");
            break;
            
        }
    }while(subEstructura != 5);
    liberarMemoriaABB(Raiz);
}

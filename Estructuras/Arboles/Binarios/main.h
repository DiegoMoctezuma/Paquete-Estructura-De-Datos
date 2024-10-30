#include"../../Registros/main.h"

//Algoritmo 1
void cargarArbol(struct NodoDoble **Raiz){
    char resp;

    system("clear");
    printf("Ingrese la informacion del nodo: ");
    scanf("%i",&(*Raiz)->Info);

    printf("El nodo '%i' tiene hijo izquierdo? (S/N): ",(*Raiz)->Info);
    scanf(" %c",&resp);
    if(toupper(resp) == 'S'){
        (*Raiz)->LigaIzq = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
        cargarArbol(&(*Raiz)->LigaIzq);
    }else{
        (*Raiz)->LigaIzq = NULL;
    }
    printf("El nodo '%i' tiene hijo derecho? (S/N): ",(*Raiz)->Info);
    scanf(" %c",&resp);
    if(toupper(resp) == 'S'){
        (*Raiz)->LigaDer = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
        cargarArbol(&(*Raiz)->LigaDer);
    }else{
        (*Raiz)->LigaDer = NULL;
    }
}
void creacionArbol(struct NodoDoble **Raiz){
    *Raiz = (struct NodoDoble*)malloc(sizeof(struct NodoDoble));
    cargarArbol(&*Raiz);
}

//Algoritmo 2
void impresionPreOrden(struct NodoDoble *Raiz){
    if(Raiz != NULL){
        printf("%i ",Raiz->Info);
        impresionPreOrden(Raiz->LigaIzq);
        impresionPreOrden(Raiz->LigaDer);
    }
}

//Algoritmo 3
void impresionInOrden(struct NodoDoble *Raiz){
    if(Raiz != NULL){
        impresionInOrden(Raiz->LigaIzq);
        printf("%i ",Raiz->Info);
        impresionInOrden(Raiz->LigaDer);
    }
}

//Algoritmo 4
void impresionPostOrden(struct NodoDoble *Raiz){
    if(Raiz != NULL){
        impresionPostOrden(Raiz->LigaIzq);
        impresionPostOrden(Raiz->LigaDer);
        printf("%i ",Raiz->Info);
    }
}

//Algoritmo liberar memoria
void liberarMemoria(struct NodoDoble *Raiz){
    if(Raiz != NULL){
        liberarMemoria(Raiz->LigaIzq);
        liberarMemoria(Raiz->LigaDer);
        free(Raiz);
    }
}

void switchArbolesBinarios(){
    struct NodoDoble *Raiz = NULL;
    int subEstructura;
    //menu:
    do{
        printf("\n(1) Crear arbol \n(2) Imprimir en preorden \n(3) Imprimir en inorden \n(4) Imprimir en postorden \n(5) Salir \nSeleccione: ");
        scanf("%i",&subEstructura);
        switch(subEstructura){
            case 1:
                creacionArbol(&Raiz);
            break;
            case 2:
                system("clear");
                printf("Preorden: ");
                impresionPreOrden(Raiz);
                printf("\n");
            break;
            case 3:
                system("clear");
                printf("Inorden: ");
                impresionInOrden(Raiz);
                printf("\n");
            break;
            case 4:
                system("clear");
                printf("Postorden: ");
                impresionPostOrden(Raiz);
                printf("\n");
            break;
            case 5:
                system("clear");
                liberarMemoria(Raiz);
            break;
            default:
                system("clear");
                printf("Opcion no valida.\n");
        }
    } while(subEstructura != 5);
    
}
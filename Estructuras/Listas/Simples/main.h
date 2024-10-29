#include "../../Registros/main.h"

//Algoritmo 1
void ingresarNodoInicio(struct Nodo **P){   
  char resp;
  system("clear");
  do {
      struct Nodo *Q = (struct Nodo*)malloc(sizeof(struct Nodo));
      printf("Ingresa la informacion del nodo (entero): ");
      scanf("%i", &Q->Info);

      Q->Liga = *P;
      *P = Q;

      printf("¿Ingresar otro numero? (S/N): ");
      scanf(" %c", &resp);

  } while (resp != 'n' && resp != 'N');
  system("clear");
}

//Algoritmo 2
void imprimirNodos(struct Nodo *P){
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

//Algoritmo 3
void eliminarUltimoElemento(struct Nodo **P){
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

//Algoritmo 4
void creacionListaAgregarNodoFinal(struct Nodo **P){
  struct Nodo *Q = NULL;
  char resp;
  Q = (struct Nodo*)malloc(sizeof(struct Nodo));
  system("clear");
  printf("Ingrese la informacion del nodo (entero): ");
  scanf("%i",&Q->Info);
  Q->Liga = NULL;
  *P = Q;
  printf("¿Ingresar otro numero? (S/N): ");
  scanf(" %c",&resp);

  while(resp != 'n' && resp != 'N'){
    Q->Liga = (struct Nodo*)malloc(sizeof(struct Nodo));
    printf("Ingrese la informacion del nodo (entero): ");
    scanf("%i",&Q->Liga->Info);
    Q->Liga->Liga = NULL;
    Q = Q->Liga;
    printf("¿Ingresar otro numero? (S/N): ");
    scanf(" %c",&resp);
  }
  system("clear");
}

//Algoritmo 5
void buscarElementoLista(struct Nodo *P){
  struct Nodo *Q = NULL;
  int x;
  if(P == NULL){ //No hay elementos
    system("clear");
    printf("\nNo hay elementos en la lista.\n");
  }else{ //Más de un elemento
    system("clear");
    printf("Ingresa el elemento a buscar: ");
    scanf("%i",&x);
    Q = P;

    //Busca el elemento en la lista
    while (Q->Info != x && Q->Liga!=NULL){
      Q = Q->Liga; 
    }
    if(Q->Info == x){
      printf("\nEl elemento '%i' esta en la lista\n",x);
    }else{
      printf("\nEl elemento '%i' no esta en la lista\n",x);
    }
  }
}

//Algoritmo 6
void insertarNodoPrincipio(struct Nodo **P){
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

//Algoritmo 7
void insertarNodoFinal(struct Nodo **P){
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

//Algoritmo 8
void eliminarPrimerNodo(struct Nodo **P){
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

//Algoritmo 9
void eliminaNodoEspecifico(struct Nodo **P){
  struct Nodo *Q = NULL, *S = NULL;
  int x;
  if(*P == NULL){
    printf("\nNo hay elementos en la lista.\n");
  } else {
    system("clear");
    printf("Elimina un nodo especifico.");
    imprimirNodos(*P);
    printf("Ingresa el elemento a buscar: ");
    scanf("%i",&x);
    Q = *P;

    //Busca el elemento en la lista
    while (Q->Info != x && Q->Liga!=NULL){
      S = Q;
      Q = Q->Liga; 
    }

    if (Q->Info != x){
      printf("\nEl nodo con informacion '%i' no existe.\n",x);
    } else {
      if (Q == *P){ //Es el primer elemento
        *P = Q->Liga;
        free(Q);
      } else if (Q->Liga == NULL){ //Es el ultimo elemento
        S->Liga = NULL;
        free(Q);
      } else { //Cualquier otro elemento
        S->Liga = Q->Liga;
        free(Q);
      }
    }
  }
}

//Algoritmo 10
void insertarNodoAntesDeOtro(struct Nodo **P){
  struct Nodo *Q = NULL, *S = NULL, *T = NULL;
  int x;
  system("clear");
  printf("Inserta un nodo antes de un nodo especifico.");
  imprimirNodos(*P);
  if (*P == NULL){ //No hay elementos en la lista -  agrega un nuevo elemento
    *P = (struct Nodo*)malloc(sizeof(struct Nodo));
    printf("Ingrese la informacion del nodo (entero): ");
    scanf("%i",&(*P)->Info);
    (*P)->Liga = NULL;
  } else{ //Hay más de un elemento
    printf("Ingresa el elemento a buscar: ");
    scanf("%i",&x);
    Q = *P;
    //Busca el elemento
    while (Q->Info != x && Q->Liga!=NULL){
      S = Q;
      Q = Q->Liga; 
    }

    if (Q->Info != x){ //No existe el elemento
      system("clear");
      printf("\nEl nodo con informacion '%i' no existe.\n",x);
    } else if (Q == *P){ //Es el primer elemento
      S = (struct Nodo*)malloc(sizeof(struct Nodo));
      printf("Ingrese la informacion del nodo (entero): ");
      scanf("%i",&S->Info);
      S->Liga = Q;
      *P = S;
      system("clear");
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

//Algoritmo 11
void insertaNodoDespuesDeUnoEspecifico(struct Nodo **P){
  struct Nodo *Q = NULL, *S = NULL, *T = NULL;
  int x;
  system("clear");
  printf("Inserta un nodo despues de un nodo especifico.");
  imprimirNodos(*P);
  if (*P == NULL){ //No hay elementos en la lista -  agrega un nuevo elemento
    Q = (struct Nodo*)malloc(sizeof(struct Nodo));
    printf("Ingrese la informacion del nodo (entero): ");
    scanf("%i",&Q->Info);
    Q->Liga = NULL;
    *P = Q;
  } else{ //Hay más de un elemento
    printf("Ingresa el elemento a buscar: ");
    scanf("%i",&x);
    Q = *P;
    T = Q->Liga;
    //Busca el elemento
    while (Q->Info != x && Q->Liga!=NULL){
      Q = Q->Liga; 
      T = Q->Liga;
    }

    if (Q->Info != x){ //No existe el elemento
      printf("\nEl nodo con informacion '%i' no existe.\n",x);
    } else if (Q->Liga == NULL){ //Es el ultimo elemento
      S = (struct Nodo*)malloc(sizeof(struct Nodo));
      printf("Ingrese la informacion del nodo (entero): ");
      scanf("%i",&S->Info);
      Q->Liga = S;
    } else { //Cualquier otro elemento
      S = (struct Nodo*)malloc(sizeof(struct Nodo));
      printf("Ingrese la informacion del nodo (entero): ");
      scanf("%i",&S->Info);
      Q->Liga = S;
      S->Liga = T;
    }
  }
  system("clear");
}

//Algoritmo 12
void eliminaUnoAntesDeOtro(struct Nodo **P){
  struct Nodo *Q = NULL,*S = NULL, *T = NULL;
  int x;
  if (P == NULL){ //Lista vacia
    printf("\nNo hay elementos en la lista.\n");
  } else {
    system("clear");
    printf("Elimina un nodo antes de un nodo especifico.");
    imprimirNodos(*P);
    printf("Ingresa el dato sucesor: ");
    scanf("%i", &x);
    Q = *P;
    S = *P;
    //Busca el elemento
    while (Q->Info != x && Q->Liga!= NULL){
      T = S;
      S = Q;
      Q = Q->Liga;
    }

    if(Q->Info != x) { //No existe el elemento
      system("clear");
      printf("\nEl nodo con informacion '%i' no existe.\n",x);
    }else if(Q == *P){ //Es el primer elemento
      system("clear");
      printf("\nNo se puede eliminar antes del primer elemento\n");
    }else if((*P)->Liga == Q){ // Eliminar el primer elemento
      *P = Q;
      free(S);
      system("clear");
    }else { //Eliminar cualquier otra posicion
      T->Liga = Q;
      free(S);
      system("clear");
    }
  }
}

//Algoritmo 13
void eliminaUnoDespuesDeOtro(struct Nodo *P){
  struct Nodo *Q = NULL, *S = NULL;
  int x;
  if(P == NULL){ //Lista vacia
    printf("\nNo hay elementos en la lista.\n");
  }else { //Más de un elemento
    system("clear");
    printf("Elimina un nodo despues de un nodo especifico.");
    imprimirNodos(P);
    printf("Ingresa el elemento a buscar: ");
    scanf("%i",&x);
    Q = P;
    //Busca el elemento
    while (Q->Info != x && Q->Liga!=NULL){
      Q = Q->Liga; 
    }
    if(Q->Info != x){ //No existe el elemento
      printf("\nEl nodo con informacion '%i' no existe.\n",x);
    }else{ //Existe el elemento
      if(Q->Liga == NULL){
        printf("\nNo se puede borrar un nodo despues del ultimo.\n");
      }else{
        S = Q->Liga;
        Q->Liga = S->Liga;
        free(S);
        system("clear");
      }
    }
  }
}

void switchListasSimples(){
  struct Nodo *P = NULL;
  int algoritmo;
  system("clear");
  do{
      printf("\n(01) Algoritmo que crea una lista simple agregando cada nuevo nodo al principio de la lista\n");
      printf("(02) Algoritmo que imprime una lista simple\n");
      printf("(03) Algoritmo que elimina el ultimo elemento\n");
      printf("(04) Algoritmo que crea una lista simple agregando cada nuevo nodo al final de la lista\n");
      printf("(05) Algoritmo que busca un elemento dentro de una lista\n");
      printf("(06) Algoritmo que inserte elementos por el inicio de una lista existente\n");
      printf("(07) Algoritmo que inserte elementos por el final de una lista existente\n");
      printf("(08) Algoritmo que elimine el primer elemento de una lista\n");
      printf("(09) Algoritmo que elimine un nodo que coincida con cierta informacion\n");
      printf("(10) Algoritmo que inserta un nodo antes de un nodo especifico\n");
      printf("(11) Algoritmo que inserta un nodo despues de un nodo especifico\n");
      printf("(12) Algoritmo que elimina un nodo antes de un nodo especifico\n");
      printf("(13) Algoritmo que elimina un nodo despues de un nodo especifico\n");
      printf("(14) Salir\n");
      printf("Selccione: ");
      scanf("%i",&algoritmo);
      switch(algoritmo){
        case 1:
          ingresarNodoInicio(&P);
        break;
        case 2:
          imprimirNodos(P);
        break;
        case 3:
          eliminarUltimoElemento(&P);
        break;
        case 4:
          creacionListaAgregarNodoFinal(&P);
        break;
        case 5:
          buscarElementoLista(P);
        break;
        case 6:
          insertarNodoPrincipio(&P);
        break;
        case 7:
          insertarNodoFinal(&P);
        break;
        case 8:
          eliminarPrimerNodo(&P);
        break;
        case 9:
          eliminaNodoEspecifico(&P);
        break;
        case 10:
          insertarNodoAntesDeOtro(&P);
        break;
        case 11:
          insertaNodoDespuesDeUnoEspecifico(&P);
        break;
        case 12:
          eliminaUnoAntesDeOtro(&P);
        break;
        case 13:
          eliminaUnoDespuesDeOtro(P);
        break;
        case 14:
          system("clear");
        break;
        default:
          printf("Opcion no valida.\n");
      }
    }while(algoritmo != 14);

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
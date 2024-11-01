#include "./Estructuras/estructuras.h"

int main(){
  int estructura,subEstructura;

  do{
    printf("\n(1) Listas \n(2) Pilas \n(3) Colas \n(4) Arboles \n(5)Salir\n");
    printf("Seleccione: ");
    scanf("%i",&estructura);
    system("cls");

    switch(estructura){
      //LISTAS
      case 1:
        do{
          printf("\n(1) Simples \n(2) Dobles \n(3) Circulares \n(4) Salir \nSeleccione: ");
          scanf("%i",&subEstructura);
          switch(subEstructura){
            case 1:
              switchListasSimples();
            break;
            case 2:
              switchListasDobles();
            break;
            case 3:
              switchListasCirculares();
            break;
            case 4:
              system("cls");
            break;
            default:
              system("cls");
              printf("Opcion no valida.\n");
          }
        }while(subEstructura != 4);
      break;

      //PILAS
      case 2:
        switchPilas();
      break;

      //COLAS
      case 3:
        do{
          printf("\n(1) Simples \n(2) Bicolas \n(3) Colas con prioridad \n(4) Salir \nSeleccione: ");
          scanf("%i",&subEstructura);
          switch(subEstructura){
            case 1:
              switchColasSimples();
            break;
            case 2:
              switchBicolas();
            break;
            case 3:
              switchColasPrioridad();
            break;
            case 4:
              system("cls");
            break;
            default:
              system("cls");
              printf("Opcion no valida.\n");
          }
        }while(subEstructura != 4);
      break;
      case 4:
        do{
          printf("\n(1) Arboles binairos \n(2) Arboles binarios de busqueda \n(3) Salir \nSeleccione: ");
          scanf("%i",&subEstructura);
          switch(subEstructura){
            case 1:
              system("cls");
              switchArbolesBinarios();
            break;
            case 2:
              system("cls");
              switchABB();
            break;
            case 3:
              system("cls");
            break;
            default:
              system("cls");
              printf("Opcion no valida.\n");
          }
        }while(subEstructura != 3);
      break;
      case 5:
        printf("Adios! :)");
      break;

      default:
        printf("Ingrese una opcion valida.");
    }

  }while(estructura != 5);

    return 0;
}



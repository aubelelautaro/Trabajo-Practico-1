#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define T 20


int main()
{
    char seguir='s';
    int opcion=0;
    int opcionStr[2];

    ePersona lista[T];

    inicializarEstados(lista, T);

    while(seguir == 's')
    {

        do
        {
            printf("1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por nombre\n");
            printf("4- Imprimir grafico de edades\n");
            printf("5- Salir\n");
            fflush(stdin);
            scanf("%s", &opcionStr);
        }
        while(validarNumero(opcionStr) == 0);
            opcion=atoi(opcionStr);

            switch(opcion)
            {
            case 1:
                altaPersona(lista,T);
                break;
            case 2:
                bajaPersona(lista,T);
                break;
            case 3:
                imprimirListaOrdPorNombre(lista,T);
                break;
            case 4:
                imprimirGraficoPorEdades(lista,T);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error, ingrese una opcion valida\n");
                break;
            }

    }

    return 0;
}

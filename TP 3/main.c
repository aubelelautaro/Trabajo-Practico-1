#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#define TAM 50

int main()
{
    char seguir='s';
    char nombreArchivo[20];
    int opcion=0;

    ePeli *pPeli;
    ePeli peli[TAM];

    pPeli=&peli;

    inicializarPeliculas(pPeli,TAM);

    if(!cargarArchivo(pPeli, TAM))
	{
	    printf("Archivo cargado\n\n");
	}
	else
	{
		printf("No se pudo abrir el archivo\n");
	}


    while(seguir=='s')
    {
        printf("1. Agregar pelicula\n");
        printf("2. Modificar pelicula\n");
        printf("3. Borrar pelicula\n");
        printf("4. Generar pagina web\n");
        printf("5. Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(pPeli,TAM);
                break;
            case 2:
                modificarPelicula(pPeli,TAM);
                break;
            case 3:
                borrarPelicula(pPeli,TAM);
               break;
            case 4:
                printf("Ingrese nombre de archivo a guardar: ");
                scanf("%s",&nombreArchivo);
                generarPagWeb(pPeli,TAM,nombreArchivo);
                break;
            case 5:
				seguir='n';
                break;
        }
    }

    return 0;
}

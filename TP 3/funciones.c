#include "funciones.h"
#include <stdio.h>
#include <string.h>

void inicializarPeliculas(ePeli *pPeli, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        strcpy((pPeli+i)->titulo," ");
        strcpy((pPeli+i)->genero," ");
        (pPeli+i)->duracion=0;
        strcpy((pPeli+i)->descripcion," ");
        (pPeli+i)->puntaje=0;
        strcpy((pPeli+i)->link," ");
    }
}

int agregarPelicula(ePeli *pPeli, int tam)
{
    int lugarLibre;

    lugarLibre = buscarLugarLibre(pPeli, tam);

    if(lugarLibre>=0)
    {

        printf("Ingrese titulo: ");
        fflush(stdin);
        gets((pPeli+lugarLibre)->titulo);

        printf("Ingrese genero: ");
        fflush(stdin);
        gets((pPeli+lugarLibre)->genero);

        do{
            printf("Ingrese duracion: ");
            fflush(stdin);
            scanf("%d",&(pPeli+lugarLibre)->duracion);

            if((pPeli+lugarLibre)->duracion<=0)
            {
                printf("Error");
            }

        }while((pPeli+lugarLibre)->duracion <= 0 && !isdigit((pPeli+lugarLibre)->duracion));


        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets((pPeli+lugarLibre)->descripcion);

        do{
            printf("Ingrese puntaje: ");
            fflush(stdin);
            scanf("%d", &(pPeli+lugarLibre)->puntaje);

            if((pPeli+lugarLibre)->puntaje<0 || (pPeli+lugarLibre)->puntaje>10)
            {
                printf("Error");
            }

        }while(((pPeli+lugarLibre)->puntaje<0 || (pPeli+lugarLibre)->puntaje>10) && !isdigit((pPeli+lugarLibre)->puntaje));

        printf("Ingrese link de imagen: ");
        fflush(stdin);
        gets((pPeli+lugarLibre)->link);
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
    if(lugarLibre==-1)
    {
        printf("No se pudo agregar la pelicula\n");
    }
    return lugarLibre;
}

int cargarArchivo(ePeli *pPeli,int tam)
{
    int flag = 0;

	FILE *archivoP;

	archivoP = fopen("archivo.bin", "rb");

	if(archivoP==NULL)
	{
		archivoP = fopen("archivo.bin", "wb");

		if(archivoP==NULL)
		{
			return 1;
		}

		flag = 1;
	}

	if(flag ==0)
	{
	    fread(pPeli,sizeof(ePeli),tam,archivoP);
    }
	fclose(archivoP);

	return 0;
}

int borrarPelicula(ePeli *pPeli, int tam)
{
    int opcion;
    int ret=-1;
    char opcion2;

    if(lugarLibre(pPeli,tam)==1)
    {
        printf("Seleccione pelicula a eliminar: \n");

        mostrarPeliculas(pPeli,tam);

        scanf("%d",&opcion);

        printf("Esta seguro que desea eliminar? (S/N): %s\n",(pPeli+(opcion-1))->titulo);

        fflush(stdin);
        opcion2=getchar();

            if(opcion>=1 && opcion<=tam && opcion2=='s')
            {
                strcpy((pPeli+(opcion-1))->titulo,"");
                strcpy((pPeli+(opcion-1))->genero,"");
                (pPeli+(opcion-1))->duracion=0;
                strcpy((pPeli+(opcion-1))->descripcion,"");
                (pPeli+(opcion-1))->puntaje=0;
                strcpy((pPeli+(opcion-1))->link,"");
            }
        ret=1;
    }
    if(ret==-1)
    {
        printf("No se puede borrar\n");
    }

    return ret;
}

int modificarPelicula(ePeli *pPeli, int tam)
{
    int opcion=-1;
    int opcion2;
    int ret=-1;
    int cantidadMostradas;

    if(lugarLibre(pPeli,tam)==1)
    {

    printf("Seleccione pelicula a modificar: \n");

    cantidadMostradas=mostrarPeliculas(pPeli,tam);

    scanf("%d",&opcion);
    }
    if(opcion<=cantidadMostradas && opcion>=1)
    {

    printf("MODIFICAR\n");
    printf("1. Titulo\n");
    printf("2. Genero\n");
    printf("3. Duracion\n");
    printf("4. Descripcion\n");
    printf("5. Puntaje\n");
    printf("6. Link de imagen\n");
    printf("7. Cancelar\n");

    fflush(stdin);
    scanf("%d",&opcion2);


        switch(opcion2)
        {
            case 1:
                {
                    printf("Ingrese nuevo titulo: ");
                    fflush(stdin);
                    gets((pPeli+(opcion-1))->titulo);
                }
                break;
            case 2:
                {
                    printf("Ingrese nuevo genero: ");
                    fflush(stdin);
                    gets((pPeli+(opcion-1))->genero);
                }
                break;
            case 3:
                {
                    do{
                    printf("Ingrese nueva duracion: ");
                    fflush(stdin);
                    scanf("%d", &(pPeli+(opcion-1))->duracion);
                    if((pPeli+(opcion-1))->duracion<=0)
                    {
                        printf("Error! ");
                    }
                    }while((pPeli+(opcion-1))->duracion<=0 && !isdigit((pPeli+(opcion-1))->duracion));
                }
               break;
            case 4:
                {
                    printf("%s\n\nIngrese nueva descripcion: ", (pPeli+(opcion-1))->descripcion);
                    fflush(stdin);
                    gets((pPeli+(opcion-1))->descripcion);
                }
                break;
            case 5:
                {
                    do{
                        printf("Ingrese puntaje: ");
                        fflush(stdin);
                        scanf("%d", &(pPeli+(opcion-1))->puntaje);
                        if((pPeli+(opcion-1))->puntaje<0 || (pPeli+(opcion-1))->puntaje>10)
                        {
                            printf("Error");
                        }
                    }while(((pPeli+(opcion-1))->puntaje< 0 || (pPeli+(opcion-1))->puntaje>10) && !isdigit((pPeli+(opcion-1))->puntaje));
                }
                break;
            case 6:
                {
                    printf("Ingrese nuevo link de la imagen: ");
                    fflush(stdin);
                    gets((pPeli+(opcion-1))->link);
                }
                break;
            case 7:
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
        }
        ret=1;
    }
    else
    {
        printf("Error\n");
    }
    if(ret=-1)
    {
        printf("No se pudo modificar\n");
    }

    return ret;
}

int buscarLugarLibre(ePeli *pPeli, int tam)
{
    int lugarLibre=-1;
	int i;
	for( i=0; i < tam; i++)
    {
        if((pPeli+i)->duracion==0)
        {
            lugarLibre=i;
            break;
        }
    }

	return lugarLibre;
}

int mostrarPeliculas(ePeli *pPeli,int tam)
{
    int i, ret=0;

    printf("Titulo\t *Genero\t *Duracion\t *Puntaje\n");

    for(i=0;i<tam;i++)
    {
        if((pPeli+i)->duracion>0)
        {
            printf("%d\t%s\t%s\t%d\t%d\n",i+1, (pPeli+i)->titulo, (pPeli+i)->genero,(pPeli+i)->duracion,(pPeli+i)->puntaje);
            ret+=1;
        }
    }
    return ret;
}

int guardarArchivo(ePeli *pPeli,int tam)
{
    int flag= 0;

	FILE *archivoP;

    archivoP=fopen("archivo.bin","wb");

    if(archivoP == NULL)
    {
        flag=1;
    }
    else
    {
        fwrite(pPeli,sizeof(ePeli),tam,archivoP);
        fclose(archivoP);
        flag=0;
    }

	return flag;
}

void generarPagWeb(ePeli *pPeli,int tam, char nombre[])
{
     int i;

     FILE* archivoP;

     strcat(nombre, ".html");

     archivoP = fopen(nombre, "w");

     if(archivoP == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         for(i=0; i<tam; i++)
         {
             fprintf(archivoP,"<article class='col-md-4 article-intro'>\n<a href='#'>\n");

             fprintf(archivoP,"<img class='img-responsive img-rounded' src='");

             if((pPeli+i)->duracion>0)
             {
                 fprintf(archivoP,"%s'\nalt=''>\n </a>\n <h3>\n <a href='#'>", (pPeli+i)->link);
                 fprintf(archivoP,"%s</a>\n </h3>\n<ul>\n<li>", (pPeli+i)->titulo);
                 fprintf(archivoP,"Genero: %s</li>\n<li>", (pPeli+i)->genero);
                 fprintf(archivoP,"Puntaje: %d</li>\n<li>", (pPeli+i)->puntaje);
                 fprintf(archivoP,"Duracion: %d</li>\n</ul>\n <p>", (pPeli+i)->duracion);
                 fprintf(archivoP,"%s</p>\n</article>\n", (pPeli+i)->descripcion);
             }

         }
      }

      fclose(archivoP);
      printf("HTML creado\n");
}

int lugarLibre(ePeli *pPeli,int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if(((pPeli+i)->duracion)!=0)
        {
            ret=1;
            break;
        }
    }
    return ret;
}

int pedirNombreArchivo(ePeli *pPeli,int tam,char nombreArchivo[])
{


    return nombreArchivo;
}

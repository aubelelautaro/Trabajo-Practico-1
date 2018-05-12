#include "funciones.h"
#include <stdio.h>
#include <string.h>

void inicializarEstados(ePersona lista[], int T)
{
    int i;

    for(i=0;i<T;i++)
    {
        lista[i].estado=0;
        strcpy(lista[i].nombre,"");
        lista[i].edad=0;
        lista[i].dni=0;
    }
}

void altaPersona(ePersona lista[], int T)
{
    int lugarLibre;
    char validaEdad[3];
    char validaDni[9];

    lugarLibre=obtenerEspacioLibre(lista, T);

    if(lugarLibre!=-1)
    {
        do{
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(lista[lugarLibre].nombre);
        }while(validarNombre(lista[lugarLibre].nombre)==0);


        do{
            printf("\nIngrese edad: ");
            scanf("%s",&validaEdad);
        }while(validarNumero(validaEdad)==0);

        lista[lugarLibre].edad=atoi(validaEdad);

        do{
            printf("\nIngrese DNI(solo los numeros): ");
            scanf("%s",&validaDni);
        }while(validarNumero(validaDni)==0);

        lista[lugarLibre].dni=atoi(validaDni);

        lista[lugarLibre].estado=1;
    }
    else
        printf("No se puede agregar mas personas.\n");
}

int obtenerEspacioLibre(ePersona lista[], int T)
{
    int i;
    int lugarLibre=-1;

    for(i=0;i<T;i++)
    {
        if(lista[i].estado==0)
        {
            lugarLibre=i;
            break;
        }
    }
    return lugarLibre;
}

void bajaPersona(ePersona lista[], int T)
{
    int dni;
    int index;
    int i;

    for(i=0;i<T;i++)
    {
        if(lista[i].estado==1)
        printf("Nombre: %s - Edad: %d - DNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);

    }
    if(lista[i].estado==0)
    {
        printf("No hay personas cargadas en el sistema\n");
    }
    else
    {
        printf("Ingrese dni a dar de baja: ");
        scanf("%d",&dni);
        index = buscarDni(lista, dni,T);
    }
    if(index!=-1)
    {
        lista[index].estado=0;
        strcpy(lista[index].nombre,"");
        lista[index].edad=0;
        lista[index].dni=0;
    }
    else
        printf("La persona seleccionada no esta registrada\n");
}

int buscarDni(ePersona lista[], int dni, int T)
{
    int i;
    int index=-1;

    for(i=0;i<T;i++)
    {
        if(dni==lista[i].dni)
        {
            index=i;
            break;
        }
        else if(i==T-1)
            printf("El DNI ingresado no esta en la lista. ");
    }

    return index;
}

void imprimirListaOrdPorNombre(ePersona lista[], int T)
{
    int i, j;
    int auxInt;
    int contAct=0;
    char aux[50];

    for(i=0;i<T;i++)
    {
        if(lista[i].estado==1)
        {
            contAct+=1;
        }
    }

    for(i=0;i<contAct-1;i++)
    {
        for(j=i+1;j<contAct;j++)
        {
            if((stricmp(lista[j].nombre,lista[i].nombre))==-1)
            {
                strcpy(aux,lista[j].nombre);
                strcpy(lista[j].nombre,lista[i].nombre);
                strcpy(lista[i].nombre,aux);

                auxInt=lista[j].edad;
                lista[j].edad=lista[i].edad;
                lista[i].edad=auxInt;

                auxInt=lista[j].dni;
                lista[j].dni=lista[i].dni;
                lista[i].dni=auxInt;
            }
        }
    }

    for(i=0;i<contAct;i++)
    {
        printf("Nombre: %s Edad: %d DNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
    }
}

void imprimirGraficoPorEdades(ePersona lista[], int T)
{
    int i, j;
    int cant1=0;
    int cant2=0;
    int cant3=0;
    int cantidades[21];
    int filas;
    int alto=0;

    for(i=0;i<T;i++)
    {
        if(lista[i].edad<18 && lista[i].estado==1)
        {
            cant1+=1;
        }

        if(lista[i].edad>=19 && lista[i].edad<=35 && lista[i].estado==1)
        {
            cant2+=1;
        }

        if(lista[i].edad>35 && lista[i].estado==1)
        {
            cant3+=1;
        }
    }

	cantidades[1]=cant1;
	cantidades[2]=cant2;
	cantidades[3]=cant3;

    for(i=1;i<=3;i++)
    {
        if (alto<cantidades[i])
        {
            alto= cantidades[i];
        }
    }

	filas = alto;

	for (i=0;i <alto;i++)
	{
		for (j=1;j<=3;j++)
		{
			if (cantidades[j]>= filas)
			{
				printf(" *        ");
			}
			else
			{
				printf("          ");
			}
		}
		filas = filas - 1;
		printf("\n");
	}

    printf("<18      ");
    printf("19-35      ");
    printf(">35\n");
}

int validarNumero(char numero[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            retorno=0;
            printf("Error, ingrese solo numeros. \n");
            break;
        }
    }

    return retorno;
}

int validarNombre(char nombre[])
{

    int retorno=1;
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>='A' && nombre[i]<='Z' || nombre[i]>='a' && nombre[i]<='z' || nombre[i]==' '))
        {
            printf("Error, solo se pueden ingresar letras.");
            retorno=0;
        }
    }
    return retorno;
}

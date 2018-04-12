#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int x=0;
    int y=0;

    do{
        printf("\n");
        printf("1.Ingresar 1er operando (A=x)\n");
        printf("2.Ingresar 2do operando (B=y)\n");
        printf("3.Calcular la suma (A+B)\n");
        printf("4.Calcular la resta (A-B)\n");
        printf("5.Calcular la division (A/B)\n");
        printf("6.Calcular la multiplicacion (A*B)\n");
        printf("7.Calcular el factorial (A!)\n");
        printf("8.Calcular todas las operaciones\n");
        printf("9.Salir\n");
        printf("A=%d\nB=%d\n", x, y);
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        while(!validarRango(opcion,1,9))
        {
            printf("\nIngrese una opcion valida: ");
            scanf("%d", &opcion);
        }
        switch(opcion)
        {
            case 1:
                x = pedirNumero("Ingrese un numero: ",x);
                break;
            case 2:
                y = pedirNumero("Ingrese el segundo numero: ",y);
                break;
            case 3:
                printf("\nLa suma es: %d\n",sumar(x,y));
                break;
            case 4:
                printf("\nLa resta es: %d\n",restar(x,y));
                break;
            case 5:
                validarDivision(x,y);
                break;
            case 6:
                printf("\nLa multiplicacion es: %d\n",multiplicar(x,y));
                break;
            case 7:
                validarFactorial(x,y);
                break;
            case 8:
                operacionesJuntas(x,y);
                break;
            case 9:
                seguir = 'n';
                break;
            default:
            break;
        }
    }
    while(seguir=='s');
    return 0;
}

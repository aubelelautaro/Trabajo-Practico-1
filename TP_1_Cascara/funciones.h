#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** int Pide un numero entero
 *  Operaciones:
 *  int Suma los numeros que se ingresen
 *  int Resta los numeros 
 *  int Multiplica los numeros
 *  float Divide los numeros
 *  long Factorial del numero ingresado (A)
 *  void Muestra las 5 operaciones de los numeros
 *  int Valida el rango de las opciones que se vayan a ejecutar
 *  int Valida que el divisor no sea 0
 *  int Valida que el numero no sea menor a 0
 */

int pedirNumero(char[],int);
int sumar (int,int);
int restar (int,int);
int multiplicar (int,int);
float dividir (int,int);
long factorial (int);
void operacionesJuntas (int,int);
int validarRango (int,int,int);
int validarDivision (int,int);
int validarFactorial (int,int);

#endif // FUNCIONES_H_INCLUDED

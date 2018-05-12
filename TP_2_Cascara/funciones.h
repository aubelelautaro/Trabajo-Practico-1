#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}ePersona;

#endif // FUNCIONES_H_INCLUDED

/** \brief Se busca el primer indice lbire
 * @param lista el array se pasa como parametro
 * @return el primer indice libre
 */
int obtenerEspacioLibre(ePersona lista[], int);

/** \brief Encuentra el indice que coincide con el dni buscado
 * @param lista el array se pasa como parametro
 * @param dni el dni que se va a buscar
 * @param largo (de la lista)
 * @return el indice en donde esta el elemento que coincide con el parametro del dni
 */
int buscarPorDni(ePersona lista[], int dni, int);

/** \brief Se ingresan personas si el array no esta lleno
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return void
 */
void altaPersona(ePersona lista[], int);

/** \brief Permite dar de baja la persona(todo en 0) ingresando el dni y sabiendo si esta o no validado
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return void
 */
void bajaPersona(ePersona lista[], int);

/** \brief Se imprime una lista por orden de nombre
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return void
 */
void imprimirListaOrdPorNombre(ePersona lista[], int);

/** \brief Se inicializan todos los estados en 0 antes de cargar algun dato
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return void
 */
void inicializarEstados(ePersona lista[], int);

/** \brief Muestra un grafico agregando barras vertical en 3 barras horizontales (< 18, de 19 a 35 y > de 35)
 * \param lista el array se pasa como parametro
 * \param largo (de la lista)
 * \return void
 */
void imprimirGraficoPorEdades(ePersona lista[], int);

/** \brief Valida que solo se ingresen numeros
 * \param numero[] char El array que tiene el numero
 * \return int Devuelve 0 si contiene un caracter distinto a un numero o 1 si son numeros
 */
int validarNumero(char numero[]);

/** \brief Valida que solo se ingresen letras en minuscula,mayuscula y espacios
 * \param nombre[] char El array que contiene al nombre
 * \return int Devuelve 0 si contiene un caracter distinto a lo validado o sino devuelve 1
 */
int validarNombre(char nombre[]);

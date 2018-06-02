#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
}ePeli;

#endif // FUNCIONES_H_INCLUDED

/** \brief se inicializa en 0 o " " los campos de la estructura
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \return void
 */
void inicializarPeliculas(ePeli *pPeli, int);

/** \brief agrega una pelicula al archivo binario
 *  \param ePeli *pPeli el puntero del array de peliculas
 *  \param int tam de peliculas
 *  \return int 1 o -1 si se pudo agregar la pelicula o no
 */
int agregarPelicula(ePeli *pPeli, int);

/** \brief
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \return int retorna 0 o 1 si se pudo agregar la pelicula o no
 */
int cargarArchivo(ePeli *pPeli,int);

/** \brief borra una pelicula del archivo binario
 *  \param ePeli *pPeli el puntero del array de peliculas
 *  \param int tam de peliculas
 *  \return int retorna 1 o -1 si se pudo eliminar la pelicula o no
 */
int borrarPelicula(ePeli *pPeli,int);

/** \brief Modificar una pelicula del archivo binario.
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \return int retorna 1 o -1 si se pudo eliminar la pelicula o no
 */
int modificarPelicula(ePeli *pPeli, int);

/**
 * \brief genera un archivo html con las peliculas del archivo binario
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \param char nombre el nombre del archivo
 * \return void
 */
void generarHTML(ePeli *pPeli, int, char);

/** \brief Busca el ultimo lugar cargado del array y devuelve el siguiente lugar
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \return int retorna el indice siguiente al ultimo cargado
 */
int buscarLugarLibre(ePeli *pPeli, int);

/** \brief Muestra las peliculas cargadas
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \return int retorna la cantidad de peliculas que se mostraron
 */
int mostrarPeliculas(ePeli *pPeli,int);

/** \brief Guarda los cambios hechos en el archivo binario
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \return int retorna 0 o 1 si se pudo agregar la pelicula o no
 */
int guardarArchivo(ePeli *pPeli,int);

/** \brief Me dice si no hay ninguna pelicula cargada.
 * \param ePeli *pPeli el puntero del array de peliculas
 * \param int tam de peliculas
 * \return int retorna -1 si no hay peliculas cargadas y 1 si hay alguna
 */
int lugarLibre(ePeli *pPeli,int);

/** \brief se pide el nombre del archivo a guardar
 * \param char nombreArchivo[] el nombre del archivo a guardar
 * \return void
 */
int pedirNombreArchivo(ePeli *pPeli,int,char[]);


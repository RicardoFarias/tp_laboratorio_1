#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Inicializa todo los estados en 0.
 * @param lista el array se pasa como parametro.
 * @return devuelve todo el array con los estados en 0.
 */
void inicializar (EPersona[],int);

/**
 * Da de alta una persona.
 * @param lista el array se pasa como parametro.
 * @return Carga una persona en el listado.
 */
void altaPersona (EPersona [], int);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(int,EPersona[],int);

/**
 * Carga una persona.
 * @param lista el array se pasa como parametro.
 * @return Muestra una persona cargada.
 */
void mostrarPersona(EPersona);
/**
 * Muestra todas las personas.
 * @param lista el array se pasa como parametro.
 * @return muestras las personas cargadas, en caso de no haber ninguna cargada avisa en un texto.
 */
void mostrarPersonas(EPersona[],int);
/**
 * Ordena por nombre el listado de personas.
 * @param lista el array se pasa como parametro.
 * @return la lista ordenada.
 */
void ordenarPorNombre(EPersona[], int);
/**
 * Da de baja una persona.
 * @param lista el array se pasa como parametro.
 * @return Elimina una persona del listado cambiando el estado o avisa que no esta cargada esa persona.
 */
void bajaPersona (EPersona [], int);
/**
 * Calcula estadistica
 * @param lista el array se pasa como parametro.
 * @return Muestra por pantalla el grafico de la estadistica de edades de las personas.
 */
void calculaEstadistica (EPersona lista [],int);

#endif // FUNCIONES_H_INCLUDED

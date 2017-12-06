/*===========================================*
 * Analizador lexico del pseudo-lenguaje     *
 *                 Alemán-C                  *
 *                                           *
 *      ---- Estructura Pila: código ----    *
 *===========================================*/

/* ##### Cabeceras con definiciones locales ##### */
#include <stdlib.h>     // Para hacer uso de memoria dinámica
#include "pila.h"       // Cabecera con definiciones para usar este modulo

/* ##### Prototipos de función ##### */
Pila * Pila_Nueva(void)
{
    Pila * nueva_pila = malloc(sizeof(Pila));

    if ( !nueva_pila )
        return NULL;

    nueva_pila->elementos = calloc(16, sizeof(void *));

    if ( !nueva_pila->elementos )
        return NULL;

    nueva_pila->tamanio = 16;
    nueva_pila->tope    = -1;

    return nueva_pila;
}

void   Pila_Borrar(Pila * p, void (*funcion_liberadora)(void *))
{
    if ( funcion_liberadora != NULL ) {
        for (int pos = 0; pos <= p->tope; pos++) {
            funcion_liberadora(p->elementos[pos]);
        }
    }

    free(p->elementos); // Se borra el arreglo de apuntadores
    free(p);            // Se borra la estructura
}

bool Pila_Insertar(Pila * p, void * elemento)
{
    if (p->tope == p->tamanio - 1) /* Está llena */ {
        void ** aux;

        // Vamos a intentar redimensionar la pila
        aux = realloc(p->elementos, p->tamanio * 2 * sizeof(void **));

        if ( aux ) /* Si se pudo redimensionar */ {
            p->elementos = aux;
            p->tamanio  *= 2;
        } else /* No se pudo redimensionar */ {
            return false;
        }
    }

    p->elementos[++p->tope] = elemento; // Insertamos el elemento
    return true;
}

void * Pila_RevisarPosicion(Pila * p, int posicion)
{
    if ( posicion >= 0 && posicion < p->tope )
        return p->elementos[posicion];
    return NULL;
}

int Pila_ObtenerPosicion(Pila * p, void * buscado, comparador cmp)
{
    for (int pos = 0; pos <= (p->tope); pos++)
        if ( cmp(p->elementos[pos], buscado) == 0 )
            return pos;

    return -1;
}

bool   Pila_Contiene(Pila * p, void * buscado, comparador cmp)
{
    return Pila_ObtenerPosicion(p, buscado, cmp) != -1;
}

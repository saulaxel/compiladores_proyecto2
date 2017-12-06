/*===========================================*
 * Analizador lexico del pseudo-lenguaje     *
 *                 Alemán-C                  *
 *                                           *
 *    ----- Estructura Pila: cabecera ----   *
 *===========================================*/

#ifndef PILA_H
#define PILA_H

/* ##### Cabeceras con definiciones globalmente ##### */
#include <stdbool.h>    // Para hacer uso de datos booleanos

typedef struct pila Pila;   // Declaración anticipada de la pila
typedef int (*comparador)(const void *, const void *);

struct pila {
    void ** elementos;
    int tope;
    int tamanio;
};

/* ##### Prototipos de función ##### */
Pila * Pila_Nueva(void);
void   Pila_Borrar(Pila * p, void (*funcion_liberadora)(void * ptr));

bool Pila_Insertar(Pila * p, void * elemento);

void * Pila_RevisarPosicion(Pila * p, int posicion);
int Pila_ObtenerPosicion(Pila * p, void * buscado, comparador cmp);
bool   Pila_Contiene(Pila * p, void * buscado, comparador cmp);

#endif /* PILA_H */

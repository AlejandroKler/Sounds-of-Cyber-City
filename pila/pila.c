/*************************************
	ALUMNO: Alejandro Kler 
	PADRON:100596
	CORRECTOR: Federico del Mazo 
**************************************/
#include "pila.h"
#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...
pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));
	if (!pila) return NULL;
	pila->datos = malloc(sizeof(void));
	if (!pila->datos) return NULL;
	pila->capacidad = 1;
	pila->cantidad = 0;
	return pila;
}
void pila_destruir(pila_t *pila){
	free(pila->datos);
	free(pila);
}
bool pila_esta_vacia(const pila_t *pila){
	return !(bool) pila->cantidad;
}
bool pila_apilar(pila_t *pila, void* valor){
	if (pila->cantidad == pila->capacidad){
		if (!pila_agrandar(pila)) return false;
	}
	pila->datos[pila->cantidad] = valor; //Agregamos en el proximo lugar
	pila->cantidad++;
	return true
}
bool pila_agrandar(pila_t *pila){
	return !(bool) realloc(pila->datos,sizeof(void) * pila->capacidad * 2);
}
void* pila_ver_tope(const pila_t *pila){
	if (!pila->cantidad) return NULL;
	return pila->datos[pila->cantidad - 1];
}
void* pila_desapilar(pila_t *pila){
	if (!pila->cantidad) return NULL;
	valor = pila->datos[pila->cantidad - 1];
	pila->cantidad--;
	return valor;
}
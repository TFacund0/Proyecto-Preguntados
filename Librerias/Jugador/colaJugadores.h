/**
 * @file colaJugadores.h
 * @brief Implementación del TDA Cola para la gestión de jugadores.
 * 
 * Este módulo gestiona una cola dinámica de jugadores, permitiendo la 
 * inserción, eliminación y recorrido de los usuarios que participan en el juego.
 */

#include <stdbool.h>

#include "../Actividad del Juego/Vidas.h"
#include "../Actividad del Juego/Intentos.h"
#include "../Actividad del Juego/Puntuacion.h"

#ifndef LISTA_H
#define LISTA_H

/**
 * @struct trUsuario
 * @brief Representa a un jugador con sus estadísticas y perfil.
 */
typedef struct {
	tVidas vidas;        /**< Contador de vidas restantes */
	tIntentos intentos;  /**< Cantidad de intentos disponibles */
	tPuntaje puntuacion; /**< Puntaje acumulado en la sesión */
	string nombre;       /**< Nombre identificador del jugador */
} trUsuario;

/**
 * @struct _nodo
 * @brief Nodo de una lista enlazada que contiene a un usuario.
 */
typedef struct _nodo {
	trUsuario usuario;   /**< Datos del usuario */
	struct _nodo *sig;   /**< Puntero al siguiente nodo */
}tNodo;

/**
 * @struct tCola
 * @brief Estructura de control para el TDA Cola.
 * Mantiene punteros al principio y final para operaciones O(1).
 */
typedef struct {
	tNodo *principio;    /**< Puntero al primer elemento de la cola */
	tNodo *final;        /**< Puntero al último elemento de la cola */
}tCola;

//OPERACIONES BASICAS COLA USUARIOS
void inicializarUsuarios(tCola *);
bool colaUsuarioVacia(tCola );

void cargarTagUsuario(trUsuario *);
void cargarPuntuacion(trUsuario *);

void agregarUsuario(tCola *, trUsuario);

void ingresarJugadores(tCola *);
void interfazUsuario(trUsuario);
void eliminarUsuario(tCola *pCola);

void conversion(char *);

/*FUNCIONALIDAD INTERNA*/
void inicializarUsuarios(tCola *pColaUsuarios) {
	pColaUsuarios->final = NULL;
	pColaUsuarios->principio = NULL;
}

bool colaUsuarioVacia(tCola pColaUsuarios) {
	return (pColaUsuarios.principio == NULL && pColaUsuarios.final == NULL);
}

void cargarTagUsuario(trUsuario *pUsuario) {
	    printf("\t Nombre(maximo 20 caracteres): ");
        fflush(stdin);
        fgets(pUsuario->nombre, 20, stdin);

        // Elimina el carácter de nueva línea, si está presente
        int longitud = strlen(pUsuario->nombre);

        if (longitud > 0 && pUsuario->nombre[longitud - 1] == '\n') {
            pUsuario->nombre[longitud - 1] = '\0';
            longitud--;
        }
}

void agregarUsuario(tCola *pColaUsuarios, trUsuario pUsuario) {
	tNodo *nuevoUsuario;
	
	nuevoUsuario = (tNodo *) malloc(sizeof(tNodo));
	nuevoUsuario->usuario = pUsuario;
	nuevoUsuario->sig = NULL;
	
	if (colaUsuarioVacia(*pColaUsuarios)){
		pColaUsuarios->principio = nuevoUsuario;
		pColaUsuarios->final = nuevoUsuario;
	}
	else{
		pColaUsuarios->final->sig = nuevoUsuario;
		pColaUsuarios->final = nuevoUsuario;
	}
}

void ingresarJugadores(tCola *pColaUsuarios){
	string respuesta;
	trUsuario rUsuario;
	
	printf("\n\tIngresar Usuario: \n");
	
	do{
		cargarTagUsuario(&rUsuario);
	    agregarUsuario(&(*pColaUsuarios), rUsuario);
	    
		printf("\n\tDesea cargar otro Usuario?");
		printf("\n\tRespuesta--> ");
		fflush(stdin);
	    scanf("%s",&respuesta);
	    printf("\n");
	    
	    conversion(respuesta);
		
	}while(strcmp(respuesta, "SI") == 0);
}

//Elimina de Golpe todos los elementos en la cola
void eliminarUsuario(tCola *pColaUsuarios) {
	tNodo *nodoSuprimir, *aux;
	aux = pColaUsuarios->principio;
	
	while(aux != NULL){
	
		nodoSuprimir = pColaUsuarios->principio;

		if( pColaUsuarios->principio == pColaUsuarios->final ){
			inicializarUsuarios(&(*pColaUsuarios));
		}
		else{
			pColaUsuarios->principio = pColaUsuarios->principio->sig;
		}
		
		free(nodoSuprimir);
		aux = aux->sig;
	}
	
}
	
void conversion(char *pRespuesta) {
	int i;
	int longCadena = strlen(pRespuesta);
	
	//Convierte todos los caracteres de la cadena en Mayusculas
	for (i = 0; i < longCadena; i++) {
		pRespuesta[i] = toupper(pRespuesta[i]);
	}
}
	
void interfazUsuario(trUsuario pUsuario) {	
	//Imprime una serie de lineas
	renglones(20, COLOR_DEFAULT, 0, 3);

	//Muestra los Datos del Usuario
	printf("\n Usuario: %s\n", pUsuario.nombre);
	mostrarVidas(pUsuario.vidas);
    mostrarIntentos(pUsuario.intentos);    

	//Imprime una serie de lineas
	renglones(20, COLOR_DEFAULT, 0, 7);
}
#endif
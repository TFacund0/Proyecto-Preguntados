/**
 * @file juegoPreguntados.c
 * @brief Punto de entrada principal para el juego de trivia Preguntados.
 * 
 * Este programa gestiona el flujo principal del juego, desde la inicialización de la 
 * cola de jugadores hasta el bucle de juego y la visualización de resultados finales.
 */

#include "Librerias/preguntados.h"

// Prototipos de funciones locales
void jugarPreguntados(tCola *);
int continuarJugando();

/**
 * @brief Función principal (Main).
 * Configura el entorno de consola, inicializa estructuras y gestiona el bucle principal de reinicio.
 */
int main() {
    tCola cola;
    
    // Configuración estética de la terminal (Color de fondo y dimensiones)
    system("COLOR 0F");
    system ("mode con: cols=125 lines=30");
    
    // Preparación inicial del sistema
    inicializarUsuarios(&cola);
    reglas(); // Muestra las reglas del juego
        
    system("cls");

	do {
		system("COLOR 0F");
		ingresarJugadores(&cola);
    	jugarPreguntados(&cola);	
	
	}while (continuarJugando() == 1);
	
    return 0;
}

void jugarPreguntados(tCola *pCola) {	
    tNodo *aux;
    int i = 0;

	aux = (*pCola).principio;

    do {
        inicializarVidas(&aux->usuario.vidas);
        inicializarIntento(&aux->usuario.intentos, MAX_INTENTOS);
        inicializarPuntaje(&aux->usuario.puntuacion);

        menuPreguntados(&aux->usuario);

        aux = aux->sig;

    } while (aux != NULL);

	procesarTablaPuntuaciones(*pCola);
    eliminarUsuario(pCola);
}

int continuarJugando() {
	int opcion;
	
	system("cls");
	printf("Continuar Jugando? \n\t(1-Si, 2-No)--> ");
	scanf("%d", &opcion);
	system("cls");
	
	return opcion;
}
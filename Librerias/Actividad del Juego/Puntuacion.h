#include "Vidas.h"

#ifndef PUNTUACION_H
#define PUNTUACION_H

//INTERFAZ

//CARACTERISTICAS OBJETO PUNTUACION
typedef int tPuntaje;

//OPERACIONES BASICAS OBJETO
void inicializarPuntaje(tPuntaje *);
void sumarPuntaje(tPuntaje *, int);
void puntajeFinal(tPuntaje *, tVidas);

//FUNCIONALIDAD INTERNA
void inicializarPuntaje (tPuntaje *pPuntos) {
    //Inicializa los puntos de cada usuario
	*pPuntos = 0;
}

void sumarPuntaje (tPuntaje *pPuntos, int nroPuntos) {
    //Suma los puntos que va ganando el usuario
	*pPuntos += nroPuntos;
}

void puntajeFinal(tPuntaje *pPuntos, tVidas pVidaJuego) {
	//Muestra los Puntos Obtenidos en el Juego, sin contar los puntos de Vidas
    printf("\n\tPuntos Obtenidos: %d", *pPuntos);
    
	//Acumula los Puntos del jugador segun las vidas y los puntos obtenidos en el juego
    *pPuntos += (pVidaJuego * 150);
	
	//Muestra las Vidas Restantes y El puntaje Final del Jugador
    printf("\n\tVidas Sobrantes: %d", pVidaJuego);
    printf("\n\tPuntaje Final: %d\n", *pPuntos);
}
#endif
#include "../Visualizacion Juego/Visualizacion.h"

#ifndef VIDAS_H
#define VIDAS_H

//INTERFAZ

//CARACTERISTICAS OBJETO VIDAS
typedef int tVidas;

//OPERACIONES BASICAS VIDAS
void inicializarVidas(tVidas *);
void perderVida(tVidas *);
void mostrarVidas(tVidas);
void perderVidaPreguntados(tVidas *);

//FUNCIONALIDAD INTERNA
void inicializarVidas(tVidas *pVidaJuego) {
    //Inicializa la Vida para Cada Usuario
	*pVidaJuego = 3;
}

void perderVida(tVidas *pVidaJuego) {
    //Decrementa las Vidas del Jugador
	if (pVidaJuego > 0) {
        *pVidaJuego = *pVidaJuego - 1;
    }
}

void mostrarVidas(tVidas pVidaJuego) {
	int i;
    
	printf(" Vidas: ");
    
	cambiarColor(COLOR_RED);//Cambia a Color Rojo
    	
    	//Esto Muestra el Simbolo del Corazon segun las vidas del jugador
	    for (i = 0 ; i < pVidaJuego; i++){
	    	printf("%c ", 3);
		}
	
	cambiarColor(COLOR_DEFAULT);//Resetea el Color
}


void perderVidaPreguntados(tVidas *pVida) {
    string leyendaCent;

    if (*pVida > 0) {
    	//Invoca a la Funcion para eliminar la vida y muestra un mensaje de lo sucedido
        perderVida(&(*pVida));
        
		strcpy(leyendaCent, "--Se desconto una vida--");
        imprimirCentrado(leyendaCent,120);
    }
}
#endif
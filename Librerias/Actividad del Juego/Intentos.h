#include "../Visualizacion Juego/Visualizacion.h"

#ifndef INTENTOS_H
#define INTENTOS_H

//INTERFAZ

//CARACTERISTICAS OBJETO INTENTO
#define MAX_INTENTOS 5

typedef int tIntentos;

//OPERACIONES BASICAS INTENTOS
void inicializarIntento(tIntentos *, int);
void restarIntentos(tIntentos *);
void mostrarIntentos(tIntentos);
void restarIntentoPreguntados(tIntentos *);

//FUNCIONALIDAD INTERNA	

void inicializarIntento (tIntentos *pNroIntento, int nro){
	//Inicializa los intentos, segun el numero que se pasa por parametro
	*pNroIntento = nro;
}

void restarIntentos (tIntentos *pNroIntento) {
    //Decrementa los intentos
	if (*pNroIntento > 0) {
        *pNroIntento = *pNroIntento - 1;
    }
}

void mostrarIntentos(tIntentos pNroIntentos) {
    //Muestra el Numero de Intentos Restantes
	printf("\n Intentos: %d\n", pNroIntentos);
}

void restarIntentoPreguntados(tIntentos *pNroIntento) {
    string leyendaCent;

    if (*pNroIntento > 0) {
    	//Invoca a la funcion para eliminar los intentos y muestra lo sucedido
        restarIntentos(&(*pNroIntento));
        
		strcpy(leyendaCent, "---Se desconto un intento---");
        imprimirCentrado(leyendaCent,120);
        
		sleep(2);
    }
}
#endif
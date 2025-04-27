#include "Librerias/preguntados.h"

void jugarPreguntados(tCola *);
int continuarJugando();

int main() {
	tCola cola;
	
	system("COLOR 0F");
	system ("mode con: cols=125 lines=30");
	
	inicializarUsuarios(&cola);
	reglas();
		
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
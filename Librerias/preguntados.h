#include "Actividad del Juego/Vidas.h"
#include "Actividad del Juego/Intentos.h"
#include "Actividad del Juego/Puntuacion.h"

#include "Jugador/colaJugadores.h"
#include "Jugador/ordenacion.h"
#include "Visualizacion Juego/Reglas.h"

#include "Visualizacion Juego/Visualizacion.h"

#ifndef PREGUNTADOS_H
#define PREGUNTADOS_H

//INTERFAZ

//CARACTERISTICAS OBJETO PREGUNTADOS
#define MAX_PREGUNTAS 24
#define CATEGORIAS 6
#define MAX 500

typedef string tvOpciones[4];

typedef struct {
    int categoria;
    string pregunta;
    string respuestaCorrecta;
    tvOpciones opciones;
} trPregunta;

bool preguntasMostradas[CATEGORIAS][MAX_PREGUNTAS];

//OPERACIONES BASICAS PREGUNTADOS
void menuPreguntados(trUsuario *);
void jugar(trUsuario*, tIntentos, tvCategorias,tvColores);

void lanzarPregunta(FILE **, trUsuario *, int);
void procesarRondaPreguntas(trPregunta, trUsuario *, int *);
void repetirPregunta(trPregunta, trUsuario *);

void abrirArchivo(FILE **,tvCategorias , int);
void cerrarArchivo(FILE **);

int busquedaPregunta(bool *);
void temporizadorSiguientePregunta();
void temporizadorTurno(trUsuario );

void imprimirPreguntaYOpciones(trPregunta );
void determinarRespuesta(trPregunta , trUsuario *, int *);
void determinarRepetirPregunta(trPregunta , trUsuario *, int *);

//FUNCIONALIDAD INTERNA
void jugar(trUsuario *pUsuario, tIntentos pIntentos, tvCategorias pvCategorias,tvColores pvColores){
	FILE *archivoPreguntas;
	int categoria, i;
	
	if( pIntentos == 0 ){
		printf("\n\t***Finalizo tus Intentos***\n\n\t---PUNTUACIONES JUGADOR---\n");
	}
	else {
		categoria = ruleta(pvCategorias, pvColores);
	    cambiarColor(pvColores[categoria]);
		
		imprimirTituloCategoria(pvCategorias,pvColores, categoria);
		interfazUsuario(*pUsuario);
		
		abrirArchivo(&archivoPreguntas, pvCategorias,categoria);
        lanzarPregunta(&archivoPreguntas, &(*pUsuario), categoria);
		cerrarArchivo(&archivoPreguntas);
		
		jugar(pUsuario, pUsuario->intentos, pvCategorias,pvColores);
	}	    
}

void menuPreguntados(trUsuario *pUsuario) {
	bool preguntasMostradas[CATEGORIAS][MAX_PREGUNTAS] = {false};	
  	jugar(pUsuario, pUsuario->intentos, categorias, colores);
    puntajeFinal(&pUsuario->puntuacion, pUsuario->vidas);
    
    sleep(3);
}

void lanzarPregunta(FILE **pArchivoPreguntas, trUsuario *pUsuario, int pCategoria) {
    trPregunta rPregunta;
    int numPregunta, advertencia = 0;

    numPregunta = busquedaPregunta(preguntasMostradas[pCategoria]);

    fseek(*pArchivoPreguntas, numPregunta * sizeof(trPregunta), SEEK_SET);
    fread(&rPregunta, sizeof(trPregunta), 1, *pArchivoPreguntas);

    procesarRondaPreguntas(rPregunta, &(*pUsuario), &advertencia);
    temporizadorTurno(*pUsuario);

    system("cls");
}

void procesarRondaPreguntas(trPregunta prPregunta, trUsuario *pUsuario, int *advertencia) {
	imprimirPreguntaYOpciones(prPregunta);
	determinarRespuesta(prPregunta, &(*pUsuario), &(*advertencia));
}

void abrirArchivo(FILE **pArchivoPreguntas,tvCategorias pvCategorias, int categoria) {
    string archivo;
    
    strcpy(archivo, "Categorias/");
    strcat(archivo, pvCategorias[categoria]);
    strcat(archivo, ".dat");

    *pArchivoPreguntas = fopen(archivo, "rb");
}

void cerrarArchivo(FILE **pArchivoPreguntas) {
    fclose(*pArchivoPreguntas);
}

int busquedaPregunta(bool *pPreguntasMostradas) {
    int pregunta;

    srand(time(NULL));
    do {
        pregunta = (rand() % MAX_PREGUNTAS);

    } while (pPreguntasMostradas[pregunta] == true);

    pPreguntasMostradas[pregunta] = true;

    return pregunta;
}

void temporizadorSiguientePregunta() {
    const int TIME = 3;
    int i, seg = TIME;

    printf("\n\t\t\tSiguiente Pregunta en ");

    for (i = 0; i < TIME; i++) {

        printf("%d", seg - i);
        sleep(1);
        printf("\b");
    }
}

void temporizadorTurno(trUsuario pUsuario){
	string leyendaFin;
	
	if (pUsuario.intentos != 0)  {
	    temporizadorSiguientePregunta();
	}
	else {
        strcpy(leyendaFin, "Su turno ha finalizado, En instantes el siguiente jugador");
        imprimirCentrado(leyendaFin, 120);

        sleep(2);
    }
}

void imprimirPreguntaYOpciones(trPregunta prPregunta) {
	    int i;
		
		imprimirCentrado(prPregunta.pregunta, 120);
            
        //Imprimir una serie de lineas
		renglones(48, COLOR_DEFAULT, 36, 9);
            
        //Imprimir Opciones para responder Pregunta
        printf("\n");
		for (i = 0; i < 4; i++) {
           	printf("\t\t\t\t      %d) %s\n", i+1, prPregunta.opciones[i]);	
		}
		
        //Imprimir una serie de lineas
		renglones(48, COLOR_DEFAULT, 36, 14);
}

void determinarRespuesta(trPregunta prPregunta, trUsuario *pUsuario, int *advertencia) {
	int respuesta;
	string cadenaRespuesta;

	printf("\n\t\t\tRespuesta-> ");
	do{
		//Obtenemos valor del ASCII, restamos 49 para obtener solo los valores (0-1-2-3), y así tener la posicion a la cual acceder en el vector
		respuesta = getch() - 49;
		//entra en bucle hasta que se ingrese una opcion valida, es una manera de evitar errores de tipeo
		
	}while(respuesta > 3 || respuesta < 0);
	
    printf("%d-%s\n", respuesta+1, prPregunta.opciones[respuesta]);
    
	if (strcmp(prPregunta.opciones[respuesta], prPregunta.respuestaCorrecta)== 0) {	
		strcpy(cadenaRespuesta, "***RESPUESTA CORRECTA***");
	    imprimirCentrado(cadenaRespuesta, 120);
		    
		if(*advertencia == 0) {
			restarIntentoPreguntados(&pUsuario->intentos);	
		}
	    
		sumarPuntaje(&pUsuario->puntuacion, 200);
	}
	else {
		strcpy(cadenaRespuesta, "***RESPUESTA INCORRECTA***");
	    imprimirCentrado(cadenaRespuesta, 120);
		
		if (*advertencia == 0) {
			
			restarIntentoPreguntados(&pUsuario->intentos);	
			determinarRepetirPregunta(prPregunta, &(*pUsuario), &(*advertencia));
		}	
	}
}

void determinarRepetirPregunta(trPregunta prPregunta, trUsuario *pUsuario, int *advertencia) {
	int opcion;
	string leyendaIntento;
	
	if (pUsuario->vidas != 0) {
	   	
		strcpy(leyendaIntento, "Desea volver a intentar? (se perdera una vida)");
    	imprimirCentrado(leyendaIntento, 120);
        
    	printf("\n\t\t\tRespuesta (1-SI 2-NO)-> ");
    	do{
			
			//Obtenemos valor del ASCII, restamos 49 para obtener solo los valores (0-1-2-3), y así tener la posicion a la cual acceder en el vector
			opcion = getch() - 48;
			//entra en bucle hasta que se ingrese una opcion valida, es una manera de evitar errores de tipeo
		
		}while(opcion > 2 || opcion < 1);
		
		printf("%d\n",opcion);
		
		if (opcion == 1) {
			*advertencia = 1;
					
			perderVidaPreguntados(&pUsuario->vidas);
			sleep(3);
						
	        system("cls");
	        printf("\n\n");
	        interfazUsuario(*pUsuario);
		
			procesarRondaPreguntas(prPregunta, &(*pUsuario), &(*advertencia));
		}
	}
}
#endif
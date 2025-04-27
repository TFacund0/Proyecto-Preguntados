#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 500

typedef char string[MAX];

typedef string tvOpciones[4];

typedef struct {
    int categoria;
    string pregunta;
    string respuestaCorrecta;
    tvOpciones opciones;
} trPregunta;

FILE *archivoPreguntas;
FILE *archivoCat;
trPregunta rPregunta;

int corteControl;
string nombreArchivo;

string cat[6] = {"Entretenimiento", "Deporte", "Geografia", "Historia", "Ciencia", "Arte"};

void inicializar();
void procesarArchivo();
void cerrarArchivo();

void principioCorte();
void unaCategoria(FILE **, trPregunta);
void finCategoria();

void leerPreguntas(trPregunta);

int main(){
	
	inicializar();
	procesarArchivo();
	cerrarArchivo();
	
	return 0;
}

void inicializar(){
	archivoPreguntas = fopen("Categorias.dat", "rb");
	
	if(archivoPreguntas != NULL){
		printf("Archivo Preguntas Abierto...\n");
	}
	
	fread(&rPregunta, sizeof(trPregunta), 1, archivoPreguntas);
	
	corteControl = rPregunta.categoria;	
}

void procesarArchivo(){
	while(!feof(archivoPreguntas)) {
		principioCorte();
		
		while(!feof(archivoPreguntas) && rPregunta.categoria == corteControl) {
			unaCategoria(&archivoCat, rPregunta);
			
			fread(&rPregunta, sizeof(trPregunta), 1, archivoPreguntas);
		}
		
		finCategoria();
	}	
}

void principioCorte() {
	strcpy(nombreArchivo, cat[corteControl-1]);
	strcat(nombreArchivo, ".dat");
	archivoCat = fopen(nombreArchivo, "wb");
	
	if (archivoCat != NULL) {
		printf("\n***Archivo %s Abierto...***\n", cat[rPregunta.categoria-1]);
	}
	
}

void unaCategoria(FILE **pArchivo, trPregunta pPregunta) {    
	leerPreguntas(pPregunta);
	fwrite(&pPregunta, sizeof(trPregunta), 1, *pArchivo);
}

void finCategoria(){
	int respuesta = fclose(archivoCat);
	
	if(respuesta == 0){
		printf("\n***Archivo %s Cerrado...***\n\n", cat[corteControl-1]);
		system("pause");
		system("cls");
	}
	
	corteControl = rPregunta.categoria;
}

void cerrarArchivo(){
	int respuesta = fclose(archivoPreguntas);
	
	if(respuesta == 0){
		printf("\nArchivo Categorias Cerrado...\n\n");
	}

}

void leerPreguntas(trPregunta pPregunta) {
	    int j;
	    string cat[6] = {"Entretenimiento", "Deporte", "Geografia", "Historia", "Historia", "Arte"};
	    
		printf("\n\tDatos Agregados Categoria %s\n", cat[pPregunta.categoria-1]);
	    
		printf("\n\tCategoria %d: %s\n", pPregunta.categoria, cat[pPregunta.categoria-1]);
		printf("\n\t\tPregunta: %s", pPregunta.pregunta);
		printf("\n\t\tRespuesta Correcta: %s\n", pPregunta.respuestaCorrecta);
        
        for (j = 0; j < 4; j++) {
            printf("\n\t\tOpcion %d: %s", j + 1, pPregunta.opciones[j]);
        }
        
        printf("\n\n");
}


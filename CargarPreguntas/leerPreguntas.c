#include <stdio.h>

#define MAX_CHAR 500

typedef char string[MAX_CHAR];

typedef string tvOpciones[4];

typedef struct {
    int categoria;
    string pregunta;
    string respuestaCorrecta;
    tvOpciones opciones;
} trPregunta;

void abrirArchivo(FILE **);
void cerrarArchivo(FILE **);

void procesarArchivo(FILE **);
void leerPreguntas(trPregunta );

int main() {
	FILE *archivo;
	
	abrirArchivo(&archivo);
	procesarArchivo(&archivo);
	cerrarArchivo(&archivo);
	
	return 0;
}

void abrirArchivo(FILE **pArchivo) {
	(*pArchivo) = fopen("Categorias.dat", "rb");
	
	if(*pArchivo != NULL) {
		printf("\nArchivo Abierto...\n");
	}	
}

void cerrarArchivo(FILE **pArchivo) {
	int respuesta = fclose((*pArchivo));
	
	if (respuesta == 0) {
		printf("\nArchivo Cerrado...\n");
	}
}

void procesarArchivo(FILE **pArchivo) {
	trPregunta pregunta;
	
	while (fread(&pregunta, sizeof(trPregunta), 1, (*pArchivo)) == 1) {
		leerPreguntas(pregunta);
	}
	
}

void leerPreguntas(trPregunta pPregunta) {
	    int j;
	    string cat[6] = {"Entretenimiento", "Deporte", "Geografia", "Historia", "Ciencia", "Arte"};
	    
		printf("\nCategoria %d: %s\n", pPregunta.categoria, cat[pPregunta.categoria-1]);
		printf("\n\tPregunta: %s", pPregunta.pregunta);
		printf("\n\tRespuesta Correcta: %s\n", pPregunta.respuestaCorrecta);
        
        for (j = 0; j < 4; j++) {
            printf("\n\tOpcion %d: %s", j + 1, pPregunta.opciones[j]);
        }
        
        printf("\n\n");
}

#include <stdio.h>
#include <windows.h>

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

void procesarCorte(FILE **);
void cargarPreguntas(FILE **);

void continuar(int *);

int main() {
	FILE *archivo;
 	
	abrirArchivo(&archivo);
	procesarCorte(&archivo);
	cerrarArchivo(&archivo);
	
	return 0;
}

//Funcionalidad Interna
void abrirArchivo(FILE **pArchivo) {
	(*pArchivo) = fopen("Categorias.dat", "ab");
	
	if(*pArchivo != NULL) {
		printf("\nArchivo Abierto...\n");
	}
}

void cerrarArchivo(FILE **pArchivo) {
	int respuesta = fclose(*pArchivo);
	
	if (respuesta == 0) {
		printf("\nArchivo Cerrado\n");
	}
}

void procesarCorte(FILE **pArchivo) {
	int opcion;
	
	do{
		cargarPreguntas(&(*pArchivo));	
		continuar(&opcion);
	}while (opcion == 1);
}

void cargarPreguntas(FILE **pArchivo) {
	trPregunta pregunta;
	string cat[6] = {"Entretenimiento", "Deporte", "Geografia", "Historia", "Ciencia", "Arte"};
	int i, j;

	printf("Categoria (1-Entretenimiento, 2-Deporte, 3-Geografia, 4-Historia, 5-Ciencia, 6-Arte): ");
	scanf("%d", &pregunta.categoria);
	
	for (i = 0; i < 40; i++) {
		system("cls");
		printf("\nCategoria %d: %s\nPregunta: %d\n\n", pregunta.categoria, cat[pregunta.categoria-1], i+1);
		
		printf("\tPregunta: ");
		fflush(stdin);
		scanf("%[^\n]s", &pregunta.pregunta);
		
		printf("\tRespuesta Correcta: ");
		fflush(stdin);
		scanf("%[^\n]s", &pregunta.respuestaCorrecta);
		
		for (j = 0; j < 4; j++) {
			printf("\n\tOpcion %d: ", j+1);
			fflush(stdin);
			scanf("%[^\n]s", &pregunta.opciones[j]);
		}
		
		fwrite(&pregunta, sizeof(trPregunta), 1, *pArchivo);
		printf("\n\n");
		system("pause");
	}
	
	printf("\nCategoria %d: %s cargada completamente\n\n", pregunta.categoria, cat[pregunta.categoria-1]);
	system("pause");
	system("cls");
}

void continuar(int *opcion){ 
	printf("Continuar (1-Si, 2-No): ");
	scanf("%d", &(*opcion));
}
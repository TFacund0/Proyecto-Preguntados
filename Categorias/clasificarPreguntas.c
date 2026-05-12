/**
 * @file clasificarPreguntas.c
 * @brief Programa auxiliar para la clasificación de preguntas por categoría.
 * 
 * Este programa lee un archivo maestro de preguntas (Categorias.dat) y utiliza la técnica 
 * de "Corte de Control" para agrupar y guardar las preguntas en archivos individuales 
 * según su categoría (ej. Arte.dat, Deporte.dat, etc.).
 * 
 * @author Desarrollo Original (2023)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 500

/**
 * @typedef string
 * @brief Redefinición de cadena de caracteres con tamaño máximo predefinido.
 */
typedef char string[MAX];

/**
 * @typedef tvOpciones
 * @brief Vector de 4 opciones de respuesta.
 */
typedef string tvOpciones[4];

/**
 * @struct trPregunta
 * @brief Estructura que representa el registro de una pregunta en el archivo binario.
 */
typedef struct {
    int categoria;
    string pregunta;
    string respuestaCorrecta;
    tvOpciones opciones;
} trPregunta;

// Variables Globales para el manejo de archivos y registros
FILE *archivoPreguntas;
FILE *archivoCat;
trPregunta rPregunta;

int corteControl;        /**< Variable para controlar el cambio de categoría (Corte de Control) */
string nombreArchivo;    /**< Nombre del archivo de salida actual */

/** Vector de nombres de categorías para la generación de archivos */
string cat[6] = {"Entretenimiento", "Deporte", "Geografia", "Historia", "Ciencia", "Arte"};

// Prototipos de funciones
void inicializar();
void procesarArchivo();
void cerrarArchivo();
void principioCorte();
void unaCategoria(FILE **, trPregunta);
void finCategoria();
void leerPreguntas(trPregunta);

/**
 * @brief Función principal que coordina el proceso de clasificación.
 */
int main(){
	
	inicializar();
	procesarArchivo();
	cerrarArchivo();
	
	return 0;
}

/**
 * @brief Inicializa la lectura del archivo maestro y establece el primer valor de corte.
 */
void inicializar(){
	archivoPreguntas = fopen("Categorias.dat", "rb");
	
	if(archivoPreguntas != NULL){
		printf("Archivo Preguntas Abierto...\n");
	}
	
	// Lectura anticipada (Prime Read)
	fread(&rPregunta, sizeof(trPregunta), 1, archivoPreguntas);
	
	corteControl = rPregunta.categoria;	
}

/**
 * @brief Implementa la lógica de Corte de Control para procesar el archivo por grupos.
 */
void procesarArchivo(){
	while(!feof(archivoPreguntas)) {
		principioCorte();
		
		// Mientras la categoría no cambie, se procesa dentro del mismo grupo
		while(!feof(archivoPreguntas) && rPregunta.categoria == corteControl) {
			unaCategoria(&archivoCat, rPregunta);
			
			fread(&rPregunta, sizeof(trPregunta), 1, archivoPreguntas);
		}
		
		finCategoria();
	}	
}

/**
 * @brief Acciones al inicio de un nuevo grupo: apertura del archivo de categoría.
 */
void principioCorte() {
	strcpy(nombreArchivo, cat[corteControl-1]);
	strcat(nombreArchivo, ".dat");
	archivoCat = fopen(nombreArchivo, "wb");
	
	if (archivoCat != NULL) {
		printf("\n***Archivo %s Abierto...***\n", cat[rPregunta.categoria-1]);
	}
}

/**
 * @brief Procesa un registro individual escribiéndolo en el archivo de categoría correspondiente.
 */
void unaCategoria(FILE **pArchivo, trPregunta pPregunta) {    
	leerPreguntas(pPregunta);
	fwrite(&pPregunta, sizeof(trPregunta), 1, *pArchivo);
}

/**
 * @brief Acciones al finalizar un grupo: cierre del archivo de categoría y actualización de la clave de corte.
 */
void finCategoria(){
	int respuesta = fclose(archivoCat);
	
	if(respuesta == 0){
		printf("\n***Archivo %s Cerrado...***\n\n", cat[corteControl-1]);
		system("pause");
		system("cls");
	}
	
	corteControl = rPregunta.categoria;
}

/**
 * @brief Cierra el archivo maestro de preguntas.
 */
void cerrarArchivo(){
	int respuesta = fclose(archivoPreguntas);
	
	if(respuesta == 0){
		printf("\nArchivo Categorias Cerrado...\n\n");
	}
}

/**
 * @brief Muestra por pantalla el contenido de la pregunta procesada.
 */
void leerPreguntas(trPregunta pPregunta) {
	    int j;
	    string cat[6] = {"Entretenimiento", "Deporte", "Geografia", "Historia", "Ciencia", "Arte"};
	    
		printf("\n\tDatos Agregados Categoria %s\n", cat[pPregunta.categoria-1]);
	    
		printf("\n\tCategoria %d: %s\n", pPregunta.categoria, cat[pPregunta.categoria-1]);
		printf("\n\t\tPregunta: %s", pPregunta.pregunta);
		printf("\n\t\tRespuesta Correcta: %s\n", pPregunta.respuestaCorrecta);
        
        for (j = 0; j < 4; j++) {
            printf("\n\t\tOpcion %d: %s", j + 1, pPregunta.opciones[j]);
        }
        
        printf("\n\n");
}

#include "Visualizacion.h"

void reglas();
void abrirArchivoReglas(FILE **);
void leerReglas(FILE **);
void cerrarArchivoReglas(FILE **);

void reglas(){
	int opcion;
	FILE *archivoReglas;
	
	gotoxy(29, 1);
	printf("Desea leer las reglas antes de comenzar el juego?(1-si 2-no):");
	
    	do{
			opcion = getch() - 48;
			//entra en bucle hasta que se ingrese una opcion valida, es una manera de evitar errores de tipeo
		
		}while(opcion > 2 || opcion < 1);
		
	if(opcion == 1){
		system("cls");
		
		abrirArchivoReglas(&archivoReglas);
		leerReglas(&archivoReglas);
		cerrarArchivoReglas(&archivoReglas);
		
		gotoxy(40,29);
		system("pause");
	}
}

void abrirArchivoReglas(FILE **pArchivo) {
	*pArchivo = fopen("Librerias/Visualizacion Juego/Reglas.txt", "r");
}

void leerReglas(FILE **pArchivo) {
	char letra;
	int opcion;
	
	system("color F0");
	
	letra = fgetc(*pArchivo);
	while(!feof(*pArchivo)) {
		printf("%c", letra);
		
		letra = fgetc(*pArchivo);	
	}

}

void cerrarArchivoReglas(FILE **pArchivo) {
	fclose(*pArchivo);
}
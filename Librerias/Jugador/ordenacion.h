#include "colaJugadores.h"

//INTERFAZ
#define MAX_PUNTAJES 3

//CARACTERISTICAS OBJETO ORDENACION TABLA
typedef trUsuario tvPuntajes[3];

//OPERACIONES BASICAS ORDENACION TABLA
void procesarTablaPuntuaciones(tCola );

void inicializarTabla(tCola , tvPuntajes *);
void cargarTablaMaxPuntaje(tCola , tvPuntajes *);

void cargarMayoresPuntuaciones(tvPuntajes *, trUsuario);
void ordenarTabla(tvPuntajes *);

void tablaOrdenada(tvPuntajes);

//FUNCIONALIDAD INTERNA
void procesarTablaPuntuaciones(tCola pCola) {
	tvPuntajes vPuntuaciones;
	
	inicializarTabla(pCola, &vPuntuaciones);
	cargarTablaMaxPuntaje(pCola , &vPuntuaciones);
	ordenarTabla(&vPuntuaciones);
	tablaOrdenada(vPuntuaciones);
}

//Carga el Vector de 3 elementos con los primeros elementos de la Cola
void inicializarTabla(tCola pCola, tvPuntajes *pvPuntajes) {
	tNodo *aux;
	int i;
	
	aux = pCola.principio;
	
	//Carga el vector con las registros de cada usuario o inicializa en 0, en el caso de que no haya usuario
	for (i = 0; i < MAX_PUNTAJES; i++) {
		
		if (aux != NULL) {
			(*pvPuntajes)[i] = aux->usuario;
			aux = aux->sig;
		}
		else {
			(*pvPuntajes)[i].puntuacion = 0;
		}		
	}
}

void cargarTablaMaxPuntaje(tCola pCola, tvPuntajes *pvPuntajes) {           
	tNodo *aux = pCola.principio;
	int i = 0;
	
	//Carga el Vector de 3 elementos con las mayores puntuaciones	
	while (aux != NULL) {
		
		if (i > 2) {
			cargarMayoresPuntuaciones(&(*pvPuntajes), aux->usuario);			
		}
				
		i++;
		aux = aux->sig;
	} 
}

void cargarMayoresPuntuaciones(tvPuntajes *pvPuntajes, trUsuario newUsuario) {
	trUsuario aux;
	int i, menor, pos = -1;
	
	//Realiza la Busqueda del menor puntaje en el Vector de Puntajes
	menor = 9999;
	
		for (i = 0; i < MAX_PUNTAJES; i++) {
	
				if ( ((*pvPuntajes)[i].puntuacion < menor) && ((*pvPuntajes)[i].puntuacion > 0)) {
					menor = (*pvPuntajes)[i].puntuacion;
					pos = i;
				}			
		}
			
		//Reemplaza el usuario que tenga menor puntuacion por el nuevo usuario en el caso de que tenga una mayor puntuacion
		if ( newUsuario.puntuacion > menor) {
			(*pvPuntajes)[pos] = newUsuario;
		}
}

void ordenarTabla(tvPuntajes *pvPuntajes) {
	int i, j;
	trUsuario aux;
	
	//Aplica Ordenacion por Burbuja debido a que se trata de un vector muy pequeño de elementos	
	for (i = 0; i < MAX_PUNTAJES-1; i++) {
		
		for (j = 0; j < MAX_PUNTAJES-1; j++) {
			
			if ((*pvPuntajes)[j].puntuacion < (*pvPuntajes)[j+1].puntuacion) {
		
				aux = (*pvPuntajes)[j];
				(*pvPuntajes)[j] = (*pvPuntajes)[j+1];
				(*pvPuntajes)[j+1] = aux;
				
			}
		
		}
	}
}

void tablaOrdenada(tvPuntajes pvPuntajes) {
	int i;
	
	//Muestra los Resultados de Efectuar todas las operaciones anteriores	
	system("cls");
	printf("\t\t        TOP 3");
	printf("\n\t***JUGADOR \t | \tPUNTUACION***\n");
	
	for (i = 0; i < MAX_PUNTAJES; i++) {
	
		if (pvPuntajes[i].puntuacion > 0) {
			gotoxy(8,3+i);
			printf("|");	    
			printf(" %d) %s", i+1, pvPuntajes[i].nombre);	
			gotoxy(39,3+i);
			printf("%d", pvPuntajes[i].puntuacion);
			gotoxy(44,3+i);
			printf("|");
		}

	}
	
	printf("\n\n");
	system("pause");
}


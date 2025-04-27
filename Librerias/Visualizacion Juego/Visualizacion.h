#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#ifndef VISUALIZACION_H
#define VISUALIZACION_H

#define COLOR_DEFAULT 15
#define COLOR_RED 12
#define COLOR_GREEN 10
#define COLOR_YELLOW 14
#define COLOR_NARANJA 6
#define COLOR_PINK  13
#define COLOR_CYAN 3

#define RULE 254

#define CATEGORIAS 6

//Interfaz
typedef char string[500];
typedef string tvCategorias[CATEGORIAS];
typedef int tvColores[CATEGORIAS];

tvCategorias categorias = {"Ciencia", "Geografia", "Entretenimiento", "Deporte", "Historia", "Arte"};
tvColores colores = {COLOR_GREEN, COLOR_CYAN, COLOR_PINK, COLOR_NARANJA, COLOR_YELLOW, COLOR_RED};

//Operaciones Basicas
void imprimirTituloCategoria(tvCategorias, tvColores, int);
void imprimirCentrado(char *, int);
void imprimirde2(string, string, int, int, int, int, int, tvCategorias, tvColores);
void renglones(int, int, int, int);

int ruleta(tvCategorias, tvColores);
void ruletaParte1(int, tvCategorias, tvColores);
void ruleta2LaReencarnacion(int, tvCategorias, tvColores);
void ruleta3MasRuletaQueNunca(int, tvCategorias, tvColores);
void ruleta4ElJuicioDeLaRuleta(int,tvCategorias,tvColores);
void circulo();
void parte1();
void parte2();
void parte3();
void parte4();

void gotoxy(int, int);
void cambiarColor(int color);

//Funcionalidad Interna
void imprimirTituloCategoria(tvCategorias pvCategorias, tvColores pvColores, int categoria) {
	renglones(20, pvColores[categoria], 50, 0);
	
	cambiarColor(pvColores[categoria]);      
	imprimirCentrado(pvCategorias[categoria], 120);
	        
	renglones(20, pvColores[categoria], 50, 2);
}

void imprimirCentrado(string cadena,int ancho) {
    int i;
    int longitudCadena = strlen(cadena);

    int margenIzquierdo = (ancho - longitudCadena) / 2;

	printf("\n");
	for (i = 0; i <= margenIzquierdo; i++) {
        putchar(' ');
    }
		
	printf("%s", cadena);
    printf("\n");
}

void imprimirde2(string cadena, string cadena2, int pos, int pos2, int margenIzquierdo, int margenDerecho, int y, tvCategorias pvCategorias, tvColores pvColores) {
		int longitudCadena = strlen(cadena);
        int longitudCadena2 = strlen(cadena2);

        printf("\n\n");
        margenIzquierdo = (margenIzquierdo - longitudCadena) / 2;
        margenDerecho = (margenDerecho - longitudCadena2) / 2;
        gotoxy(margenIzquierdo, y);

        cambiarColor(pvColores[pos]);
        printf("%s", cadena);

        gotoxy((120 - margenDerecho) - longitudCadena2 / 2, y);
        cambiarColor(pvColores[pos2]);
        printf("%s", cadena2);
        printf("\n\n");
}

void renglones(int largo, int color, int posicionX,int posicionY){
		int i;
		
		gotoxy(posicionX, posicionY);
		cambiarColor(color);	
		for(i = 0; i <= largo; i++){
           	printf("%c", 196);
		}
		cambiarColor(COLOR_DEFAULT);
}

int ruleta(tvCategorias pvCategorias, tvColores pvColores){
    int i, pos;
	
	srand(time(NULL));
    pos = (rand() % 6) + 12;
	
    for (i = 0; i < pos; i++){
     	ruleta3MasRuletaQueNunca(i,  pvCategorias, pvColores);
		ruleta2LaReencarnacion(i, pvCategorias, pvColores);
		ruleta4ElJuicioDeLaRuleta(i,pvCategorias,pvColores);
		ruletaParte1(i, pvCategorias, pvColores);
    }
    
    sleep(1);
	system("cls");
	
    return pos % 6;
}

void ruletaParte1(int i, tvCategorias pvCategorias, tvColores pvColores){
		int pos, pos2, j;
		int posiciones[3][2] = {{2,3}, {6,5}, {10,18}};
		
        system("cls");
        
		pos= (i+1) % 6;
        cambiarColor(pvColores[pos]);
        printf("\n\n");
        
        imprimirCentrado(pvCategorias[pos], 120);
        
        for(j = 0; j < 2; j++){
			pos= (i + posiciones[0][j]) % 6;
        	pos2= (i + posiciones[1][j]) % 6;
        	imprimirde2(pvCategorias[pos], pvCategorias [pos2], pos, pos2, 87, 103, posiciones[2][j], pvCategorias, pvColores);
		}
		
		pos2= (i + 4) % 6;
        cambiarColor(pvColores[pos2]);
        printf("\n\n");
        
        imprimirCentrado(pvCategorias [pos2], 120);
        cambiarColor(COLOR_DEFAULT);

        circulo();
        parte1();
        printf("\t\t\t\t\t\t\t    %c", 25);

        gotoxy(60, 29);
        usleep( pow(i*30, 2));
}

void ruleta2LaReencarnacion(int i, tvCategorias pvCategorias, tvColores pvColores){
        int pos, pos2, j;
		int posiciones[5][3] = {{1,2,3}, {6,5,4}, {100,84,100}, {114,98,114}, {6,14,22}};
		
		system("cls");
		
        for(j = 0; j < 3; j++){
			pos= (i + posiciones[0][j]) % 6;
			pos2= (i + posiciones[1][j]) % 6;
        	imprimirde2( pvCategorias[pos], pvCategorias[pos2], pos, pos2, posiciones[2][j], posiciones[3][j],posiciones[4][j], pvCategorias, pvColores);
		}
        cambiarColor(COLOR_DEFAULT);

        circulo();
        parte2();
        printf("\t\t\t\t\t\t\t    %c", 25);//la flechita de arriba de la ruleta
        
        gotoxy(60, 29);
        usleep( pow(i*30,2));
}

void ruleta3MasRuletaQueNunca(int i, tvCategorias pvCategorias, tvColores pvColores){
        int j, pos ;
        int posiciones[2][6] = {{6,1,5,2,4,3},{128,93,154,85,144,112}};
        
        system("cls");
        printf("\n\n\n");
        
		for(j = 0; j < 6; j++){
			pos= (i + posiciones[0][j]) % 6;
        	cambiarColor(pvColores[pos]);
        	imprimirCentrado(pvCategorias[pos], posiciones[1][j]);
        
        	printf("\n\n");
		}
		cambiarColor(COLOR_DEFAULT);
	
        circulo();
        parte3();
        printf("\t\t\t\t\t\t\t    %c", 25);

        gotoxy(60, 29);
        usleep( pow(i*30,2));
}

void ruleta4ElJuicioDeLaRuleta(int i, tvCategorias pvCategorias, tvColores pvColores){
        int j,pos;
        int posiciones[2][6] = {{1,6,2,5,3,4},{112,144,85,154,93,128}};
       
        system("cls");
        printf("\n\n\n");
        
		for(j=0;j<6;j++){
			pos= (i+posiciones[0][j])%6;
        	cambiarColor(pvColores[pos]);
        	imprimirCentrado(pvCategorias[pos], posiciones[1][j]);
        	//sleep(1);
        	printf("\n\n");
		}

		cambiarColor(COLOR_DEFAULT);
	
        circulo();
        parte4();
        printf("\t\t\t\t\t\t\t    %c",25);

        gotoxy(60,29);
        usleep(pow(i*35,2));
        
}

void circulo(){
	double radio, angulo;
	int centro_x, centro_y, x, y, i, resolution;
	
	radio = 28;
    centro_x = 60;
    centro_y = 14;

	resolution = 36;

    for ( i = 0; i < resolution; i++) {
        angulo = 2.0 * M_PI * i / resolution;
        x = centro_x + (int)(radio * cos(angulo));
        y = centro_y + (int)(0.5 * radio * sin(angulo));

        gotoxy(x, y);
        printf("%c", RULE);
    }
}		

void parte1(){
	int i, j;
	
	for (j = 0; j < 28; j++){
        gotoxy(j*2 + 34, 14);
        printf("%c", RULE);
    }
    for (i = 2; i < 27; i++){
        gotoxy(i + 46, i);
        printf("%c", RULE);
    }
    for (i = 28; i < 53; i++){
        gotoxy(i + 20, 34 - i + 20);
        printf("%c", RULE);
    }
    gotoxy(0,0);
}

void parte2(){
    int i, j;
	for (j = 1; j < 28; j++){
        gotoxy(60, j);
        printf("%c", RULE);
    }
    for (i = -1; i < 14; i++){
        gotoxy(i*2.8 + 44, 20-i);
        printf("%c", RULE);
    }
    for (i = 4; i < 19; i++){
        gotoxy(i*2.8 + 30, i+3);
        printf("%c", RULE);
    }
    gotoxy(0,0);
}

void parte3(){
	int i,j;
	for (i = -2; i < 9; i++){
        gotoxy((i+9) * 5, i+11);
        printf("%c", RULE);
    }
    for (i = 0; i < 22; i++){
        gotoxy(i*1.5 + 44, 25-i);
        printf("%c", RULE);
    }
	
    for (i = 1; i < 14; i++){
        gotoxy((i + 53), i*2);
        printf("%c", RULE);
    }
    gotoxy(0,0);
}

void parte4(){
		int i,j;
	for (i = -2; i < 9; i++){
        gotoxy((i +9)*5, 17-i);
        printf("%c", RULE);
    }
    for (i = 0; i < 22; i++){//LINEA DEL MEDIO
        gotoxy(i*1.5 +44, 3+i);
        printf("%c", RULE);
    }
	
    for (i = 1; i < 14; i++){
        gotoxy((i +53), 28-i*2);
        printf("%c", RULE);
    }
    gotoxy(0,0);
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void cambiarColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

#endif
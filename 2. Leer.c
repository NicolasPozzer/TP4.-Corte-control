#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char string[50];



typedef struct{
	int nroLibreta;
	string nombreAlumno;
	int codMateria;
	float Nota;
	
}tRegistroAlum;

tRegistroAlum regAlum;

FILE * archivo;


void inicializacion();
void procesoCorte();
void finalizacion();


void inicioCorte();
void unAlumno();
void finCorte();

int nroLibretaAnt;
//variables a utilizar
float acumNotasAlum;
float promedioNotasAlum;
int cantNotaAlum;
int totalAlumnos;
float mayorNota;
int aux;





void inicializacion(){
	archivo = fopen("Alumnos.dat", "rb");
	fread(&regAlum, sizeof(tRegistroAlum), 1, archivo);
	
	totalAlumnos = 0;
	mayorNota = 0;
	aux = 0;
	printf("\nnroLibreta\tNota Promedio\n");	
}

void procesoCorte(){
	while(!feof(archivo)){
		inicioCorte();
		
		while(!feof(archivo) && regAlum.nroLibreta == nroLibretaAnt){
			unAlumno();
			fread(&regAlum, sizeof(tRegistroAlum), 1, archivo);
			
		}
		
		
	finCorte();	
	
	
	}
	
}

void inicioCorte(){
	acumNotasAlum = 0;
	promedioNotasAlum = 0;
	cantNotaAlum = 0;
	
	nroLibretaAnt = regAlum.nroLibreta;
	
	
	printf("%d", regAlum.nroLibreta);
}

void unAlumno(){
	
	cantNotaAlum = cantNotaAlum + 1;
	acumNotasAlum = acumNotasAlum + regAlum.Nota;
	
	
}

void finCorte(){
	
	
	totalAlumnos = totalAlumnos + 1;
	promedioNotasAlum = acumNotasAlum / cantNotaAlum;
	
	printf("\t\t%.2f\n", promedioNotasAlum);
	
	if(promedioNotasAlum > mayorNota){
		mayorNota = promedioNotasAlum;
		aux = nroLibretaAnt;
	}
}

void finalizacion(){
	printf("\nEl total de alumnos es: %d\n",totalAlumnos);
	printf("\nEl Alumno con mayor promedio es: %d  Promedio: %.2f\n",aux ,mayorNota);
	fclose(archivo);
}


int main(){
	inicializacion();
	procesoCorte();
	finalizacion();
	
	return 0;
}



























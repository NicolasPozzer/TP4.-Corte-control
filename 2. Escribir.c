#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// funciones de archivo
void iniciar();
void ingresarDatos();
void guardar();
void finalizar();
void ingresarRespuesta();

typedef char string[50];

typedef struct{
	int nroLibreta;
	string nombreAlumno;
	int codMateria;
	float Nota;
}tRegistroAlum;

tRegistroAlum regAlum;

FILE * archivo;

char respuesta;

//cuerpo del programa y utilizacion de funciones
int main(){
	iniciar();
	ingresarRespuesta();
	while (respuesta == 's' || respuesta == 'S'){
		ingresarDatos();
		guardar();
		ingresarRespuesta();
	}
	finalizar();
	return 0;
}

void iniciar(){
	archivo = fopen("Alumnos.dat", "wb");
}

void ingresarRespuesta(){
	fflush(stdin);
	printf("\nDesea ingresar datos al archivo?(S-SI/N-NO): ");
	scanf("%c", &respuesta);
}

void ingresarDatos(){
	printf("\nIngrese numero de Libreta: ");
	scanf("%d", &regAlum.nroLibreta);fflush(stdin);
	printf("\nIngrese el nombre del alumno: ");	
	scanf("%[^\n]s", &regAlum.nombreAlumno);
	printf("\nIngrese codigo de Materia: ");
	scanf("%d", &regAlum.codMateria);
	printf("\nIngrese la Nota: ");
	scanf("%f", &regAlum.Nota);
}

void guardar(){
	fwrite(&regAlum, sizeof(tRegistroAlum), 1, archivo);
	printf("\nSE HAN GUARDADO CORRECTAMENTE LOS DATOS\n");
}

void finalizar(){
	fclose(archivo);
}































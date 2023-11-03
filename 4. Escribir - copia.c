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
	int ip;
	string nombreDocumento;
	int tipoDocumento;
	float tamBytes;
}tRegistroDocumento;

tRegistroDocumento regDocu;

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
	archivo = fopen("Documentos.dat", "wb");
}

void ingresarRespuesta(){
	fflush(stdin);
	printf("\nDesea ingresar datos al archivo?(S-SI/N-NO): ");
	scanf("%c", &respuesta);
}

void ingresarDatos(){
	printf("\nIngrese numero de IP: ");
	scanf("%d", &regDocu.ip);fflush(stdin);
	printf("\nIngrese el nombre del Documento: ");	
	scanf("%[^\n]s", &regDocu.nombreDocumento);
	printf("\nIngrese codigo de Documento: ");
	scanf("%d", &regDocu.tipoDocumento);
	printf("\nIngrese el tamaño de Bytes: ");
	scanf("%f", &regDocu.tamBytes);
}

void guardar(){
	fwrite(&regDocu, sizeof(tRegistroDocumento), 1, archivo);
	printf("\nSE HAN GUARDADO CORRECTAMENTE LOS DATOS\n");
}

void finalizar(){
	fclose(archivo);
}



























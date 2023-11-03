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
	int nroCuenta;
	string nombreCliente;
	int codOperacion;
	float importe;
}tRegistroCliente;

tRegistroCliente regCliente;

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
	archivo = fopen("Cliente.dat", "wb");
}

void ingresarRespuesta(){
	fflush(stdin);
	printf("\nDesea ingresar datos al archivo?(S-SI/N-NO): ");
	scanf("%c", &respuesta);
}

void ingresarDatos(){
	printf("\nIngrese numero de la numero de la cuenta: ");
	scanf("%d", &regCliente.nroCuenta);fflush(stdin);
	printf("\nIngrese el nombre del cliente: ");	
	scanf("%[^\n]s", &regCliente.nombreCliente);
	printf("\nIngrese codigo de operacion (1 - Deposito / 2 - Extraccion): ");
	scanf("%d", &regCliente.codOperacion);
	printf("\nIngrese importe: ");
	scanf("%f", &regCliente.importe);
}

void guardar(){
	fwrite(&regCliente, sizeof(tRegistroCliente), 1, archivo);
	printf("\nSE HAN GUARDADO CORRECTAMENTE LOS DATOS\n");
}

void finalizar(){
	fclose(archivo);
}































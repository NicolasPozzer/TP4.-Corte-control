#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char string[50];

typedef struct {
	
	int nroCuenta;
	string nombreCliente;
	int codOperacion;
	float importe;
	
}tRegistroCliente;
tRegistroCliente regCliente;

FILE * archivo;

//prototipado
void inicializacion();
void procesoCorte();
void finalizacion();

void inicioCorte();
void unCliente();
void finCorte();

//declaracion variable anterior si o si
int nroCuentaAnt;

//variables a usar
int contDeposito;
float acumDeposito;
int contExtraccion;
float acumExtraccion;


int main(){
	inicializacion();
	procesoCorte();
	finalizacion();
	
	return 0;
}

void inicializacion(){
	archivo = fopen("Cliente.dat", "rb");
	fread(&regCliente, sizeof(tRegistroCliente), 1, archivo);
	
	
	//TITULO
	printf("Nro. Cuenta\tDeposito\tExtraccion\n\n");
}

void procesoCorte(){
	while(!feof(archivo)){
		inicioCorte();
		
		while(!feof(archivo) && regCliente.nroCuenta == nroCuentaAnt){
			unCliente();
			fread(&regCliente, sizeof(tRegistroCliente), 1, archivo);
			
		}
		
		finCorte();
	}
	
}

void inicioCorte(){
	contDeposito = 0;
	acumDeposito = 0;
	contExtraccion = 0;
	acumExtraccion = 0;
	
	nroCuentaAnt = regCliente.nroCuenta;
	
	
}



void unCliente(){
	
	if(regCliente.codOperacion == 1){
		contDeposito =  contDeposito + 1;
		acumDeposito = acumDeposito + regCliente.importe;
		printf("%d\t%.2f\t0\n", regCliente.nroCuenta, regCliente.importe);
	}
	
	else{
		contExtraccion = contExtraccion + 1;
		acumExtraccion = acumExtraccion + regCliente.importe;
		printf("%d\t0\t%.2f\n", regCliente.nroCuenta, regCliente.importe);
	}
	
	
}

void finCorte(){
	
	printf("\nTotal cuenta: %d\t%.2f\t%.2f\n", nroCuentaAnt, acumDeposito, acumExtraccion);
	printf("Cantidad Movimiento cuenta: %d\t%d\t%d\n", nroCuentaAnt, contDeposito, contExtraccion);
	
}

void finalizacion(){
	
	fclose(archivo);
}
































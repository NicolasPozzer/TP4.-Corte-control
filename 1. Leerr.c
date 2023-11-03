#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Se solicita:
//a) Listar el detalle de movimientos por cuenta. 
//b) Informar cantidad de movimientos y totales de importes 
//    de depósitos y extracción, por cuenta.


//Primero los tipos de datos
typedef char string[50];

typedef struct{
	int nroCuenta;
	string nombreCliente;
	int codOperacion; // 1 deposito /   2 extraccion
	float importe;
}tRegistroCliente;

tRegistroCliente regCliente;

FILE * archivo;


void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unCliente();
void finCorte();

//Declaracion de Variables y el "ANTERIOR SI O SI"

int nroCuentaAnt;

int cantMovimientosD;
int cantMovimientosE;
float importDeposito;
float importExtraccion;



void inicializacion(){
	archivo = fopen("Cliente.dat","rb");
	fread(&regCliente,sizeof(tRegistroCliente),1,archivo);
	
	
	
	printf("\nNro. Cuenta\tNombre del Cliente\tCod. Operacion\tImporte\n");
	
}

void procesoCorte(){
	while(!feof(archivo)){
		principioCorte();
		
		
		while(!feof(archivo) && regCliente.nroCuenta == nroCuentaAnt){
			unCliente();
			fread(&regCliente, sizeof(tRegistroCliente), 1, archivo);
		}
		
		
		finCorte();
	}
		
}


void principioCorte(){
	cantMovimientosD = 0;
	cantMovimientosE = 0;
	importDeposito = 0;
	importExtraccion = 0;
	
	nroCuentaAnt = regCliente.nroCuenta;
	
	
}

void unCliente(){
	
	
	
	
	if(regCliente.codOperacion == 1){
		importDeposito = importDeposito + regCliente.importe;
		cantMovimientosD = cantMovimientosD + 1;
	}
	else{
		importExtraccion = importExtraccion + regCliente.importe;
		cantMovimientosE = cantMovimientosE + 1;
	}
	
	
	
	printf("\n %d\t\t%s\t\t\t%d\t\t%.2f\t",regCliente.nroCuenta,regCliente.nombreCliente,regCliente.codOperacion,regCliente.importe);
}

void finCorte(){
	
	
	printf("\nMonto Total en Depositos: %.2f",importDeposito);
	printf("\nMonto Total en Extracciones: %.2f",importExtraccion);
	printf("\n\nCantidad de mov. Depositos: %d\tExtracciones: %d",cantMovimientosD,cantMovimientosE);
	
	printf("\n\n\n");
	
}

void finalizacion(){
	fclose(archivo);
}

int main(){
	inicializacion();
	procesoCorte();
	finalizacion();
	
	return 0;
}












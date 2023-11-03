#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char string[50];

typedef struct{
	int codProvincia;
	string producto;
	int codCategoria;
	float importe;
}tRegistroEnvios;
tRegistroEnvios regEnvios;

FILE * archivo;

void inicializacion();
void procesoCorte();
void finalizacion();

void inicioCorte();
void unDocumento();
void finCorte();

int codProvAnt;

int contEnvios;
float acumImportes;
int contTotal;


void inicializacion(){
	archivo = fopen("Documentos.dat", "rb");
	fread(&regDocu, sizeof(tRegistroDocumento), 1, archivo);
	
	
	
	
	printf("IP\t\t\tDocumento\tTamaño(bytes)\n\n");
}

void procesoCorte(){
	while(!feof(archivo)){
		inicioCorte();
		
		while(!feof(archivo) && regDocu.ip == ipAnt){
			unDocumento();
			fread(&regDocu, sizeof(tRegistroDocumento), 1, archivo);
		}
		
		finCorte();
	}
}

void unDocumento(){
	cantDocumentos = cantDocumentos + 1;
	acumBytes = acumBytes + regDocu.tamBytes;
	
	
	switch(regDocu.tipoDocumento){
		
		case 01:
			printf("\t\t\t%s.docx\t%.2f\n", regDocu.nombreDocumento, regDocu.tamBytes);
			break;
		case 02:
			printf("\t\t\t%s.pdf\t%.2f\n", regDocu.nombreDocumento, regDocu.tamBytes);
			break;
		case 03:
			printf("\t\t\t%s.jpg\t%.2f\n", regDocu.nombreDocumento, regDocu.tamBytes);
			break;
		case 04:
			printf("\t\t\t%s.png\t%.2f\n", regDocu.nombreDocumento, regDocu.tamBytes);
			break;
		case 05:
			printf("\t\t\t%s.xlsx\t%.2f\n", regDocu.nombreDocumento, regDocu.tamBytes);
			break;						
	}
	
	//printf("%s\t%.2f\n", regDocu.nombreDocumento, regDocu.tamBytes);
}

void inicioCorte(){
	cantDocumentos = 0;
	acumBytes = 0;
	
	ipAnt = regDocu.ip;
	
	printf("%d\n",regDocu.ip);
}

void finCorte(){
	printf("\nCantidad de documentos\nde la PC: %d\tes: %d\t\t%.2f\n\n\n", ipAnt, cantDocumentos, acumBytes);
	
	
}

void finalizacion(){
	fclose(archivo);
}

int main(){
	inicializacion();
	procesoCorte();
	finalizacion();
}


























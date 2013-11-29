#ifndef GETPAR_H_
#define GETPAR_H_

struct _par {
	
	char * i;	// Archivo de entrada
	int m; 		// Modo de ejecución
	
	int check[2];

} par;

void getpar(int argc, char * argv[]);

void printpar();

#endif
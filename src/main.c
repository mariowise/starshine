#include <stdio.h>
#include <stdlib.h>

#include <getpar.h>
#include <stars.h>

int main(int argc, char * argv[]) {

	getpar(argc, argv);
	printpar();

	load(par.i, 0, 1, 0, 1);	

	return 0;
}
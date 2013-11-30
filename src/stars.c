#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stars.h>

#define SEPARATOR "\t"

void loadSize(char * filePath) {

	FILE * fd = fopen(filePath, "r");
	if(fd == NULL) {
		printf("* Error: el archivo '%s' no ha podido abrirse para lectura.\n", filePath);
		exit(1);
	}

	// Lectura del archivo de entrada
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char * token = NULL;

	// Lee la primera fila
	read = getline(&line, &len, fd);

		token = strtok(line, SEPARATOR);
		map_size_y = atoi(token);

		token = strtok(NULL, SEPARATOR);
		map_size_x = atoi(token);

	free(line);
	fclose(fd);

}

void push(int newInt) {

	matrix[ai][aj] = newInt;
	aj++;

	if(aj == matrix_size_x) {
		aj = 0;
		ai++;	
	}

}

void load(char * filePath, int xini, int xfin, int yini, int yfin) {

	// Apertura del archivo de entrada
	FILE * fd = fopen(filePath, "r");
	if(fd == NULL) {
		printf("* Error: el archivo '%s' no ha podido abrirse para lectura.\n", filePath);
		exit(1);
	}

	// Lectura del archivo de entrada
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	matrix = NULL;
	matrix_size_x = 0;
	matrix_size_y = 0;

	int * row = NULL;
	int rowLen = 0;

	int i = 0, j = 0, li = -1, lj = 0, k;
	char * token = NULL;

	// Lee la primera fila
	read = getline(&line, &len, fd);

		token = strtok(line, SEPARATOR);
		map_size_y = atoi(token);

		token = strtok(NULL, SEPARATOR);
		map_size_x = atoi(token);

	
	matrix_size_x = (xfin-xini+1)+2;
	matrix_size_y = (yfin-yini+1)+2;

	matrix = (int **) malloc(sizeof(int *) * matrix_size_y);
	for(k = 0; k < matrix_size_y; k++)
		matrix[k] = (int *) malloc(sizeof(int) * matrix_size_x);

	ai = aj = 0;


	while((read = getline(&line, &len, fd)) != -1) {

		token = strtok(line, SEPARATOR);

		/////////////////////////////////////////////////////
		if(i >= (yini-1) && i <= (yfin+1) &&
			j >= (xini-1) && j <= (xfin+1) ) {

			push(atoi(token));
			printf("*");

		}
		/////////////////////////////////////////////////////
		printf("%s\t", token);

		j++;

		while((token = strtok(NULL, SEPARATOR)) != NULL) {

			/////////////////////////////////////////////////////
			if(i >= (yini-1) && i <= (yfin+1) &&
				j >= (xini-1) && j <= (xfin+1) ) {

				push(atoi(token));
				printf("*");
			}
			/////////////////////////////////////////////////////
			printf("%s\t", token);
			j++;

		}

		printf("\n");

		i++;
		j = 0;
		lj = 0;

	}


	free(line);

	printf("---%dx%d\n", map_size_y, map_size_x);

	for(i = 0; i < matrix_size_y; i++) {
	for(j = 0; j < matrix_size_x; j++)
		printf("%d\t", matrix[i][j]);
	printf("\n");
	}

	fclose(fd);

}

void process() {


	int i, j;

	output = (float **) malloc(sizeof(float *) * matrix_size_y);
	for(i = 0; i < map_size_y; i++)
		output[i] = (float *) malloc(sizeof(float) * matrix_size_x);

	// Para todas las filas
	for(i = 1; i < matrix_size_y - 1; i++) {

		for(j = 1; j < matrix_size_x - 1; j++) {

			output[i][j] = 	(float) (matrix[i][j] +
							matrix[i-1][j] +
							matrix[i+1][j] +
							matrix[i][j-1] +
							matrix[i][j+1]) / (float) 5.0f;

		}

	}

	printf("------------------Salida\n");

	for(i = 0; i < matrix_size_y; i++) {
	for(j = 0; j < matrix_size_x; j++)
		if(output[i][j] > 6.0f)
			printf("* ");
		else
			printf("  ");
		// printf("%.1f\t\t", output[i][j]);
	printf("\n");
	}


}
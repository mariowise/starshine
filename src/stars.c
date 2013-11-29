#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stars.h>

#define SEPARATOR "\t"

void pushRow(int * row) {

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

	int i = 0, j = 0, li = 0, lj = 0;
	char * token = NULL;

	read = getline(&line, &len, fd);

		token = strtok(line, SEPARATOR);
		map_size_y = atoi(token);

		token = strtok(NULL, SEPARATOR);
		map_size_x = atoi(token);

	matrix = (int *) malloc(sizeof(int *) * matrix_size_y);

	
	while((read = getline(&line, &len, fd)) != -1) {

		if(i >= (yini-1) && i <= (yfin+1)) {

			token = strtok(line, SEPARATOR);

			if(j >= (xini-1) && j <= (xfin+1)) {
				row = (int *) realloc(row, sizeof(int) * (rowLen+1));
				row[rowLen++] = atoi(token);
				lj++;
				matrix_size_y++;

				printf("%d\t", row[rowLen-1]);
			}

			j++;

			while((token = strtok(NULL, SEPARATOR)) != NULL) {
				
				if(j >= (xini-1) && j <= (xfin+1)) {
					row = (int *) realloc(row, sizeof(int) * (rowLen+1));
					row[rowLen++] = atoi(token);
					lj++;

					printf("%d\t", row[rowLen-1]);
				}

				j++;

			}

			matrix[li] = row;
			matrix_size_x++;
			row = NULL;
			rowLen = 0;

			printf("\n");

		}

		i++;
		li++;
		j = 0;
		lj = 0;

	}

	free(line);

	printf("---\n");

	for(i = 0; i < matrix_size_y; i++) {
	for(j = 0; j < matrix_size_x; j++)
		printf("%d\t", matrix[i][j]);
	printf("\n");
	}

}
#ifndef STARS_H_
#define STARS_H_

int ** matrix;

int ** shine;

int matrix_size_x, matrix_size_y;
int map_size_x, map_size_y;

int ai, aj;

float ** output;

void load(char * filePath, int xini, int xfin, int yini, int yfin);

void process();

#endif
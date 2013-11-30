#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include <getpar.h>
#include <stars.h>

int main(int argc, char * argv[]) {

	getpar(argc, argv);
	printpar();

	int TAG = 0;
	int rank, size;

	MPI_Init (&argc, &argv);
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	MPI_Comm_size (MPI_COMM_WORLD, &size);

		loadSize(par.i);

		int intervalo = (map_size_y-2) / size;

		printf("PROCESO %d\n", rank);

		int lower = 1 + intervalo * rank;
		int upper = lower + intervalo;
		if(upper > map_size_y-2)
			upper = map_size_y-2;


		load(par.i, 1, map_size_x-2, lower, upper);
		
		process();

	MPI_Finalize();

	return 0;
}
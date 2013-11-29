
INCLUDE = -I src/
OUTPUT = ./bin/stars.run

CFLAG = -c -w

main: build/main.o build/getpar.o build/stars.o
	@ mpicc -o $(OUTPUT) build/*.o -w $(INCLUDE)
	@ echo "Compilación terminada"

build/main.o: src/main.c
	@ echo "  mpicc src/main.c"
	@ mpicc $(CFLAG) -o build/main.o src/main.c $(INCLUDE)

build/getpar.o: src/getpar.c
	@ echo "  mpicc src/getpar.c"
	@ mpicc $(CFLAG) -o build/getpar.o src/getpar.c $(INCLUDE)

build/stars.o: src/stars.c
	@ echo "  mpicc src/stars.c"
	@ mpicc $(CFLAG) -o build/stars.o src/stars.c $(INCLUDE)

clean: 
	@ clear
	@ rm -r build/*.o
	@ rm -r bin/*.run
	@ echo "Limpiando compilación"

run:
	@ clear
	@ $(OUTPUT) -i etc/input.mat -m 1

me: clean main run
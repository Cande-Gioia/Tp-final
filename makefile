main: main.o obj.o rana.o colisiones.o
	gcc main.o  obj.o rana.o colisiones.o -o main -Wall -g
main.o: main.c obj.h colisiones.h rana.h
	gcc main.c -c  -Wall
obj.o: obj.c obj.h 
	gcc obj.c -c -Wall
rana.o: rana.c rana.h 
	gcc rana.c -c -Wall
colisiones.o: colisiones.c colisiones.h rana.h obj.h
	gcc colisiones.c -c -Wall

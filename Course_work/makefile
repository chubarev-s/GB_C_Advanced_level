all: dron.exe

dron.exe: main.o direction.o init.o
	gcc -o dron main.o direction.o init.o

main.o: main.c config.h
	gcc -c -o main.o main.c

direction.o: direction.c
	gcc -c -o direction.o direction.c

init.o: init.c
	gcc -c -o init.o init.c

clean:
	del *.o dron.exe
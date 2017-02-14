CC = g++

CFLAGS = -Wall

all: main

main: main.o
	${CC} ${CFLAGS} main.o -o main

clean:
	\rm -rf *.o

cleanall:
	\rm -rf main *.o

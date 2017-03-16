CC = g++

CFLAGS = -Wall

all: main

main: main.o extraction.o
        ${CC} ${CFLAGS} main.o extraction.o -o main

extraction: extraction.o
        ${CC} ${CFLAGS} extraction.o
clean:
        \rm -rf *.o

cleanall:
        \rm -rf main *.o *.txt

CC = g++

CFLAGS = -Wall

all: main

main: main.o extraction.o elements.o
    ${CC} ${CFLAGS} main.o extraction.o -o main elements.o 

extraction: extraction.o
    ${CC} ${CFLAGS} extraction.o
    
clean:
    \rm -rf *.o

cleanall:
    \rm -rf main *.o *.txt *.csv

elements: elements.o 
    $(CC) $(CFLAGS) elements.o

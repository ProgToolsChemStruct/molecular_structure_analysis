CC = g++

CFLAGS = -Wall

all: main

main: main.o extraction.o center_of_mass.o
	${CC} ${CFLAGS} main.o extraction.o center_of_mass.o -o main

extraction: extraction.o
	${CC} ${CFLAGS} extraction.o

center_of_mass: center_of_mass.o
	${CC} ${CFLAGS} center_of_mass.o

clean:
	\rm -rf *.o

cleanall:
	\rm -rf main *.o *.txt

cleanfiles:
	\rm -rf *.txt

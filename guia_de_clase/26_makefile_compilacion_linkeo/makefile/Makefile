CC=gcc
EJECUTABLE=main.out
HEADERS=./include
CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
LIBS= -lm
all: main.o funciones.o
$(CC) $(LFLAGS) main.o funciones.o $(LIBS) -o$(EJECUTABLE)
main.o: main.c
$(CC) $(CFLAGS) main.c -omain.o
funciones.o: funciones.c
$(CC) $(CFLAGS) funciones.c -ofunciones.o
doxy:
doxygen Doxyfile
firefox ./doxy/html/index.html &
clean:
rm -f ./*.o
rm -f ./*.out
rm ./doxy -rf
ejecutar:
./ejemplo.out

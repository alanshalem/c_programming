CC=gcc
EJECUTABLE=main.out
HEADERS=./include
CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
ARFLAGS=rcs
LIBS= -lm
all: main.o funciones.o
$(CC) $(LFLAGS) main.o funciones.o $(LIBS) -o$(EJECUTABLE)
main.o: main.c
$(CC) $(CFLAGS) main.c -omain.o
funciones.o: funciones.c
$(CC) $(CFLAGS) funciones.c -ofunciones.o
#-- Creo la lib estatica --
libStatic: funciones.o
$(AR) $(ARFLAGS) libfunciones.a funciones.o
#-- Compilo con la lib estatica --
compileLibStatic: main.o
$(CC) -o$(EJECUTABLE) main.o -L. -lfunciones
doxy:
doxygen Doxyfile
firefox ./doxy/html/index.html &
clean:
rm -f ./*.o
rm -f ./*.out
rm -f ./*.a
rm ./doxy -rf
ejecutar:
./main.out
CC=gcc
EJECUTABLE=main.out
HEADERS=./include
CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
ARFLAGS=
LIBS= -lm
all: main.o funciones.o
$(CC) $(LFLAGS) main.o funciones.o $(LIBS) -o$(EJECUTABLE)
main.o: main.c
$(CC) $(CFLAGS) main.c -omain.o
funciones.o: funciones.c
$(CC) $(CFLAGS) funciones.c -ofunciones.o
#-- Creo la lib shared --
libShared: funciones.o
$(CC) $(CFLAGS) -Werror -fPIC funciones.c
$(CC) -shared -o libfunciones.so funciones.o
#-- Compilo con la lib shared --
compileLibShared: main.o
$(CC) -L./ -Wall main.o -o$(EJECUTABLE) -lfunciones
#export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
doxy:
doxygen Doxyfile
firefox ./doxy/html/index.html &
clean:
rm -f ./*.o
rm -f ./*.out
rm -f ./*.so
rm ./doxy -rf
#unset LD_LIBRARY_PATH
ejecutar:
./main.out

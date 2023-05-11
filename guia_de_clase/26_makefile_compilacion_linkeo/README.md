## 26\. Uso de makefile: compilación y linkeo.

Programas necesarios: Use apt para instalarlos

<table><tbody><tr><td>Paquete&nbsp;</td><td>Descripción&nbsp;</td></tr><tr><td>make&nbsp;</td><td>Herramienta para asistir en la compilación automática de código fuente.&nbsp;</td></tr><tr><td>gdb&nbsp;</td><td>Debugger&nbsp;</td></tr></tbody></table>

### Pasos de la compilación

1\. Precompilador: En este paso se realizan las siguientes operaciones.   
● Resuelve las directivas que comienzan con # como los includes, ifdef y las macros.  
● Se eliminan los comentarios. Cuando se compila con la opción -save-temps o -E se genera la salida luego de este paso. Suele ser una archivo con extensión .i

2\. Compilación: Toma la salida del paso anterior y produce una salida con el código a nivel de assembly. Cuando se compila con la opción -save-temps o -S se genera la salida luego de este paso. Suele ser una archivo con extensión .s

3\. Ensamblado: Toma la salida del paso de compilación y lo traduce a lenguaje de máquina. Cuando se compila con la opción -save-temps o -c se genera la salida luego de este paso. Suele ser una archivo con extensión .o

4\. Linkeo: Este es el último paso para formar el archivo ejecutable, en esta fase se agrega código para el inicio y la finalización del programa. Además se unen las llamadas a función con su código y las . El gcc es un wrapper que realiza estos pasos para compilar todo.

Guardamos el siguiente código en un archivo llamado ejemplo.c   
```c
#include <stdio.h>
#define CANT((int) 10)
int main(void) {
int i;
for (i = 0; i < CANT; i++) {
printf("%d.Hola\r\n", i);
}
return (0);
}
```

Ejecutamos el siguiente comando que genera todos los archivos intermedios del proceso de compilación   
`root@linuxVm:~$ gcc ejemplo.c -Wall -save-temps -oejemplo.out`  
`root@linuxVm:~$ ls ejemplo.c ejemplo.i ejemplo.o ejemplo.out ejemplo.s`

### Compilación de varios .c y .h

Transcriba el siguiente código en un archivo llamado funciones.c

```c
#include <stdio.h>
#include <string.h>
int suma(int a, int b) {
 return (a + b);
}
int resta(int a, int b) {
 return (a - b);
}
int division(int a, int b) {
 return (a / b);
}
int multiplicacion(int a, int b) {
 return (a * b);
}
```

Transcriba el siguiente código en un archivo llamado funciones.h

```c
#ifndef FUNCIONES_H
#define FUNCIONES_H
enum op_E {
 SUMA = 0,
   RESTA,
   DIVISION,
   MULTIPLICACION
};
int suma(int a, int b);
int resta(int a, int b);
int division(int a, int b);
int multiplicacion(int a, int b);
#endif
```

Transcriba el siguiente código en un archivo llamado main.c

```c
#include <stdio.h>
#include <string.h>
#include "funciones.h"
int main(void) {
 int a, b, r;
 char op, * p;
 int(func[4])(int, int);
 char listOp[] = "+-/";
 int opIndex;
 //-- Asignacion del puntero a funcion --
 func[SUMA] = suma;
 func[RESTA] = resta;
 func[DIVISION] = division;
 func[MULTIPLICACION] = multiplicacion;
 //-- Ingreso de datos --
 printf("Ingrese un numero:\r\n");
 scanf("%d", & a);
 printf("Ingrese operacion\r\n");
 scanf("%*c%c", & op);
 printf("Ingrese un numero:\r\n");
 scanf("%d", & b);
 p = strchr(listOp, op);
 if (p == NULL) {
   printf("Operacion invalida\r\n");
   return (0);
 }
 opIndex = (int)(p - listOp);
 //-- Uso del puntero a funcion --
 r = func[opIndex](a, b);
 printf("El resultado es: %d\r\n", r);
 return (0);
}
```

Compile el código de la siguiente manera  
`root@linuxVm:~$ gcc main.c funciones.c -Wall -oejemplo.out`

Makefile  
Transcriba el siguiente código en un archivo llamado Makefile y colóquelo junto con los archivos del  
ejemplo anterior.

```c
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
rm -f ./.o
rm -f ./.out
rm ./doxy -rf
ejecutar:
./ejemplo.out
```

Compile el código de la siguiente manera  
`root@linuxVm:~$ Makefile`

Como instalar debugger en Atom  
Instalar el paquete de Atom dbg-gdb

1.  Entre a las preferencias de Atom Edit->Preferences
2.  Seleccione el menú Install y busque el paquete dbg-gdb, luego instálelo.
3.  Instale todas las dependencias que la instalación requiera.  
    Cómo debuggear un programa en C
4.  Copie el siguiente código en un archivo llamado ejemplo.c

```c
#include <stdio.h>
#define CANT ((int)10)
int main (void)
{
int i;
for (i = 0; i < CANT; i++) {
printf ("%d.Hola\r\n", i);
}
return (0);
}
```

1.  Compile el código utilizando la opción -g  
    `root@linuxVm:~$ gcc ejemplo.c -Wall -g -oejemplo.out`
2.  Puede colocar breakpoints (puntos de detención) haciendo click a la izquierda del número de línea  
    aparecerá un círculo rojo indicando que el breakpoint pudo colocarse.
3.  Presione la tecla F5 para configurar el debugger. En el panel que aparece seleccione el archivo  
    ejemplo.out que genero en el punto 2
4.  Presione el botón Debug para comenzar la ejecución del código
5.  Para continuar la ejecución puede presionar la tecla F5

### Library

Es un conjunto de funciones compiladas juntas pensadas para ser reutilizadas.  
En linux tenemos de 3 tipos  
● Static library: La library se copia en el programa al cual se linkea.  
● Dynamic library: Sólo se incluye una referencia a la library, por lo cual se puede modificar la Library  
sin recompilar todo el programa.

#### Static library

Transcriba el siguiente código en un archivo llamado Makefile y colóquelo junto con los archivos del  
ejemplo anterior.

```c
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
rm -f ./.o
rm -f ./.out
rm -f ./.a
rm ./doxy -rf
ejecutar:
./main.out
```

_Compile el código de la siguiente manera_  
`_root@linuxVm:~$ Makefile_`

#### _Dynamic library_

```c
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
rm -f ./.o
rm -f ./.out
rm -f ./.so
rm ./doxy -rf
#unset LD_LIBRARY_PATH
ejecutar:
./main.out
```

Compile el código de la siguiente manera

root@linuxVm:$ Makefile

Agregue el path donde esta la library en la variable de entorno LD_LIBRARY_PATH

`root@linuxVm:$ export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH`

Utilizando este comando puede eliminar la configuracion anterior.

`root@linuxVm:$ unset LD_LIBRARY_PATH`

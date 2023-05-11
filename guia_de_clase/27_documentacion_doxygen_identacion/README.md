## Documentación del código: Doxygen e identación

### Programas necesarios

Use apt para instalarlos

<table><tbody><tr><td>Paquete&nbsp;</td><td>Descripción</td></tr><tr><td>doxygen&nbsp;</td><td>Programa para documentar código fuente en c, c++m etc</td></tr><tr><td>doxygen-gui</td><td>Interfaz gráfica de doxygen</td></tr><tr><td>graphviz</td><td>Herramientas para generar gráficos.</td></tr></tbody></table>

### Doxygen

Es un generador de documentación para C, C++, Python, VHDL, etc el cual nos permite contener Centro de los mismos archivos de código fuente la documentación facilitando mantener la documentación actualizada.  
 

### Documentando con doxygen

La documentación en doxygen se realiza directamente sobre los archivos fuente como comentarios utilizando comentarios de bloque y/o en línea especialmente identificados para ser tomados como arte de la documentación y no como un comentario del código.  
● Comentario de bloque

```c
/**
Comentario de bloque
*/
```

● Comentario en línea

```c
//! Comentario en linea
```

● Comentario en línea para documentar en detalle un define o un campo de una estructura.

```c
//!< Comentario en linea_
```

Dentro de estos comentarios se colocan tags para realizar la documentación entre ellos podemos mencionar  
_● \\file Para documentar un archivo_  
_● \\fn Para documentar una función_  
_● \\struct Para documentar una estructura_  
_● \\enum Para documentar un enum_  
_● \\brief Descripción breve del elemento documentado._  
_● \\detail Descripción detallada del elemento documentado._  
_● \\author Autor del elemento documentado._  
_● \\date Fecha del elemento documentado._  
_● \\version Versión del elemento documentado._  
_● \\param Parámetro de la función documentada_  
_● \\return Valor de retorno de la_  
_● \\todo Agrega el texto a la lista de todo de la documentación_  
 

_Ejemplo de documentación de archivo con función main_

```c
/**
\file main.c
\brief Programa ejemplo que llama a una funcion alojada en otro archivo .c
\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
\date 2021.05.05
\version 1
*/
//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include "oper.h"
/**
\fn int main (void)
\brief Pide el ingreso de dos numeros enteros y realiza su suma utilizando
la funcion operSuma, si los dos operandos son cero sale del programa.
\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
\date 2021.05.05
\return Retorna siempre cero.
\bug No verifica el rango de los números ingresados.
*/
int main(void) {
 int a, b;
 int resultadoS;
 int resultadoM;
 do {
   //-- Ingreso de datos --
   printf("Ingrese numero:\r\n");
   scanf("%d", & a);
   printf("Ingrese numero:\r\n");
   scanf("%d", & b);
   //-- llamo a la funcion ---
   resultadoS = operSuma(a, b);
   resultadoM = operMult(a, b);
   //-- Imprimo el resultado de la operacion --
   printf("\r\n%d + %d = %d\r\n", a, b, resultadoS);
   printf("\r\n%d * %d = %d\r\n", a, b, resultadoM);
 } while ((a != 0) || (b != 0));
 return (0);
}
Guarde este código en un archivo llamado main.c
```

  
_Ejemplo de documentación de archivo con funciones varias._

```c
/**
\file oper.c
\brief Contiene funciones que realizan operaciones matematicas
\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
\date 2021.05.05
\version 1
\todo Agregar mas operaciones.
*/
//--------------
//-- Includes --
//--------------
#include "oper.h"
/**
\fn int operSuma (int a, int b)
\brief Suma dos numeros enteros y retorna el resultado
\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
\date 2021.05.05
\param a Primer operando a sumar
\param b Segundo operando a sumar
\return Retorna la suma de los operandos pasados como parametros
\todo Modificar para que verificar overflow.
*/
int operSuma(int a, int b) {
 return (a + b);
}
/**
\fn int operMult (int a, int b)
\brief Multiplica dos numeros enteros y retorna el resultado
\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
\date 2021.05.05
\param a Primer operando a sumar
\param b Segundo operando a sumar
\return Retorna la suma de los operandos pasados como parametros
*/
int operMult(int a, int b) {
 return (a * b);
}
```

_Guarde este código en un archivo llamado oper.c_  
  
_Ejemplo de documentación de archivo .h_

```c
/*
\file oper.h
\brief Prototipos de funciones de oper.c
\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
\date 2021.05.05
\version 1.0.0
*/
#ifndef OPER_H
#define OPER_H
//----------------
//-- Prototipos --
//----------------
int operSuma(int a, int b);
int operMult(int a, int b);
#endif
```

  
Compilamos el código

`root@linuxVm: $ gcc -Wall main.c oper.c -osuma.out`

Generamos el archivo de configuración doxygen.

`root@linuxVm:$ doxygen -g`  
``Configuration file `Doxyfile' created.``  
`Now edit the configuration file and enter`  
 `doxygen Doxyfile`  
`to generate the documentation for your project`

Generamos la documentación  
`root@linuxVm:$ doxygen`  
Abrimos la documentación utilizando el firefox o cualquier browser que utilice.  
`root@linuxVm:~$ firefox ./html/index.html`
/* Modificadores de Variables
● auto: Todas las variables son auto salvo que se indique lo contrario. Estas variables son alojadas
en el stack. Las variables de este tipo dejan de existir una vez que salimos de la función donde
fueron definidas.
● extern: Se usa en variables globales, para que las mismas puedan ser accedidas fuera del .c en el
cual están definidas.
● static: Su funcionamiento depende de si se usa en una variable local o global.
○ Si se usa en una variable local a una función el valor de la misma persiste por más que se
haya salido de la función. Es como una variable local, pero solo puede ser usada dentro de
90
la función que fue definida. Al definir una variable local como static la misma debe ser
inicializada en el momento que se define.
○ Si se usa en una variable global, esta no puede ser accedida desde otro .c Incluso si se
hace un extern la variable no podrá ser accedida desde otro .c
● volatile: Una variable declarada así le indica al compilador que no optimice la variable por que no
encuentra que esté siendo usada en ese contexto.
● const: Al declararla de esta forma se evita que la variable sea modificada luego de inicializarla.
● register: Es una sugerencia para colocar la variable en un registro del procesador.
El siguiente muestra ejemplos de:
*/
#include <stdio.h>
int funcSuma1(int param)
{
    static int suma = 0; //-- Declaro una variable static --
    suma = param + 1;
    return (suma);
}
int main(void)
{
    int num, res;             //-- Variables auto --
    const int CONSTANTE = 10; //-- Declaro una variable constante --
    printf("Ingrese numero\r\n");
    scanf("%d", &num);
    res = funcSuma1(num);
    printf("res = %d\r\n", res);
    return (0);
}

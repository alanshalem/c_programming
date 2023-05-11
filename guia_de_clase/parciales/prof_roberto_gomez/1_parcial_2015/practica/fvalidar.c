#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


//==============================================================================
int validar_email(char *s){
    char *p; 
    
    // valida que no empiece con '@'
    if (*s == '@')
        return 0;

    // valida una longitud minima. tipo: a@b.com
    if (strlen(s) < 7)
        return 0;
    
    // valida que termine con ".com"
    if (strcmp(&(s[strlen(s) -4]), ".com"))
        return 0;
    
    // valida que haya una '@'
    if ((p=strchr(s, '@')) == NULL)
        return 0;
        
    // valida que no haya otra '@'
    if (strchr(p+1, '@') != NULL)
        return 0;
        
    // valida que inmediatamente despues de '@' no venga un '.'
    if (*(p+1) == '.')
        return 0;

    // valida que no haya un '.' entre el '@' y el ".com"
    if (strchr(strchr(p+1, '.')+1, '.') != NULL)
        return 0;

    // todo ok     
    return 1;
}

//==============================================================================
int validar_ip(char *s){
    int l, n;
    char b[16]; // un buffer para trabajar con una copia del string
    char *p[4]; // un array de 4 punteros a las direcciones donde comienza cada digito
    char *paux; // para buscar el punto
    int d;
    
    // verifica la longitud minima (n.n.n.n) y maxima (xxx.xxx.xxx.xxx) del string
    l = strlen(s);
    if (l<7 || l>15)
        return 0;

    // me guardo una copia porque voy a modificar el contenido del string
    strcpy(b, s);
    
    // busco los 3 puntos, los reemplazo por '\0' 
    // y me guardo el puntero al proximo grupo de digitos
    // en el medio voy verificando que sean numeros
    n = 0;
    p[0] = b;
    paux = b;
    while (*paux){
        if (*paux == '.'){
            *paux = '\0';
            n++;
            if (n>3)        // hay mas de 3 puntos
                return 0;
            p[n] = paux+1;  // me guardo el comienzo el proximo grupo de digitos
        }
        else{
            if (!isdigit(*paux))    // verifica que los caracters sean digitos
                return 0;
        }
        paux++;
        if((paux - p[n]) > 3) // Hay mas de 3 digitos en el grupo
            return 0;
    }
 
    // verifica que haya 3 puntos y no menos
    if (n<3)
        return 0;
 
    // verifica que los digitos esten entre los limites 0..255   
    for (n=0; n<4; n++){
        d = atoi(p[n]);
        if(d<0 || d>255)
            return 0;
    }
    
    // todo ok
    return 1;
}

//==============================================================================
int validar_tarjeta(char *s){
    int n, i;
    char *p;
    
    // valida la longitud del string
    if (strlen(s) != 19)
        return 0;

    // verifica los '-'
    if( (s[4]!='-') || (s[9]!='-') || (s[14]!='-') )
        return 0;

    // verifica los cuatro grupos de cuatro digitos
    for (i=0, p=s; i<4; i++, p++)
        for (n=0; n<4; n++, p++)
            if(!isdigit(*p))
                return 0;

    // todo ok
    return 1;
}

//==============================================================================
int validar_fecha(char *s){
    char b[3], *p;
    int n;
    int mes, dia, hora, minutos, segundos;
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // valida la longitud del string
    if (strlen(s) != 19)
        return 0;

    // verifica los separadores ('-', '#', ':')
    if( (s[4]!='-') || (s[7]!='-') || (s[10]!='#') || (s[13]!=':') || (s[16]!=':') )
        return 0;
  
    // anio
    // verifica que los cuatro primeros caracteres sean dígitos 
    for (n=0, p=s; n<4; n++, p++)
        if(!isdigit(*p))
            return 0; 

    // mes
    // verifica que los caracteres del mes sean digitos
    b[2] = '\0';
    for (n=0, p++; n<2; n++, p++)
        if(!isdigit(*p))
            return 0;
        else
            b[n] = *p;
    
    // verifica que el mes estre ente los limites 1..12
    mes = atoi(b);
    if (mes<1 || mes>12)
        return 0;
            
    // dia
    // verifica que los caracteres del dia sean digitos
    for (n=0, p++; n<2; n++, p++)
        if(!isdigit(*p))
            return 0;
        else
            b[n] = *p;
    
    // verifica que el dia este entre los limites 1.. y los dias que corresponden al mes
    dia = atoi(b);
    if (dia<1 || dia>dias[mes])
        return 0;


    // hora
    // verifica que los caracteres de la hora sean digitos
    for (n=0, p++; n<2; n++, p++)
        if(!isdigit(*p))
            return 0;
        else
            b[n] = *p;
    
    // verifica que la hora este entre los limites 0..23
    hora = atoi(b);
    if (hora<0 || hora>23)
        return 0;

    // minutos
    // verifica que los caracteres de las minutos sean digitos
    for (n=0, p++; n<2; n++, p++)
        if(!isdigit(*p))
            return 0;
        else
            b[n] = *p;
    
    // verifica que los minutos esten entre los limites 0..59
    minutos = atoi(b);
    if (minutos<0 || minutos>23)
        return 0;

    // segundos
    // verifica que los caracteres de las minutos sean digitos
    for (n=0, p++; n<2; n++, p++)
        if(!isdigit(*p))
            return 0;
        else
            b[n] = *p;
    
    // verifica que los segundos esten entre los limites 0..59
    segundos = atoi(b);
    if (segundos<0 || segundos>23)
        return 0;

    // todo ok
    return 1;
}





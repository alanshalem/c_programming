/*
14. Implemente una función que determine si un password cumple con todas las recomendaciones de
seguridad que se describen a continuación:
a. Debe tener al menos 8 caracteres.
b. No debe tener espacios.
c. Debe contener letras mayúsculas y minúsculas.
d. Debe contener alguno de estos símbolos ~! @ # $% ^& * _-+ = ' | \ \ (){}\ []:; "' <>,.? /
e. Debe contener un dígito base 10. (0 - 9)
El prototipo de la función es el siguiente
int validarPassword(char *dataPtr)
Donde:
● dataPtr: Es el puntero al password a validar.
● Devuelve:
○ 1: El password cumple las cuatro recomendaciones de seguridad.
○ -1: Si no cumple la recomendación a
○ -2: Si no cumple la recomendación b
○ -3: Si no cumple la recomendación c
○ -4: Si no cumple la recomendación d
○ -5: Si no cumple la recomendación e
*/

int validarPassword(char *dataPtr)
{
    int tiene_longitud = 0;
    int tiene_letras_mayusculas = 0;
    int tiene_letras_minusculas = 0;
    int tiene_simbolos_especiales = 0;
    int tiene_digitos = 0;

    // Comprobar longitud
    int longitud = strlen(dataPtr);
    if (longitud < 8)
    {
        return -1;
    }
    tiene_longitud = 1;

    // Comprobar espacios
    for (int i = 0; i < longitud; i++)
    {
        if (dataPtr[i] == ' ')
        {
            return -2;
        }
    }

    // Comprobar letras mayúsculas y minúsculas
    for (int i = 0; i < longitud; i++)
    {
        if (isupper(dataPtr[i]))
        {
            tiene_letras_mayusculas = 1;
        }
        else if (islower(dataPtr[i]))
        {
            tiene_letras_minusculas = 1;
        }
    }
    if (!(tiene_letras_mayusculas && tiene_letras_minusculas))
    {
        return -3;
    }

    // Comprobar símbolos especiales
    char simbolos[] = "~!@#$%^&*_-+='|\\(){}[]:;\"<>,.?/";
    for (int i = 0; i < strlen(simbolos); i++)
    {
        if (strchr(dataPtr, simbolos[i]))
        {
            tiene_simbolos_especiales = 1;
            break;
        }
    }
    if (!tiene_simbolos_especiales)
    {
        return -4;
    }

    // Comprobar dígitos
    for (int i = 0; i < longitud; i++)
    {
        if (isdigit(dataPtr[i]))
        {
            tiene_digitos = 1;
            break;
        }
    }
    if (!tiene_digitos)
    {
        return -5;
    }

    // Si se llega aquí, el password cumple con todas las recomendaciones
    return 1;
}

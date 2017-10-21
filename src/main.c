#include <stdio.h>

int main() {
    //parsear archivo init.uni
    typedef struct
    {
        int x;
        int y;
        int matriz;
    } Datos;

    FILE *archivo;
    archivo = fopen("init.uni","r");
    int caracter;

    if (archivo == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }
    else
    {
        printf("\nEl contenido del archivo de prueba es \n\n");
        while((caracter = fgetc(archivo)) != EOF)
        {
            printf("%c",caracter);
        }
    }
    fclose(archivo);
    return 0;
}
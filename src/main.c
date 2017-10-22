#include <stdio.h>
#include <stdlib.h>
/*
typedef struct
{
    int x;
    int y;
    int matriz;
} Datos;
*/
int main()
{
    FILE *archivo;
    char caracteres[100];
    archivo = fopen("init.txt","r");
    if (archivo == NULL)
        exit(1);
    else
    {
        printf("\nEl contenido del archivo de prueba es \n\n");
        while (feof(archivo) == 0)
        {
            fgets(caracteres,100,archivo);
            printf("%s",caracteres);
        }
    }
    fclose(archivo);
    return 0;
}
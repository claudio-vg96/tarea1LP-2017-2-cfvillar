#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int ancho = 0; //ancho mapa
    int largo = 0; //largo mapa
    char str[20];
    int linea = 0;
    int indice = 0;
    char caracteres[100];
    char *ptr;
    FILE *archivo;
    archivo = fopen("init.txt","r");
    if (archivo == NULL){
        printf("No se ha podido abrir el archivo\n");
        exit(1);
    }
    while(!feof(archivo))
    {
        fgets(caracteres,100,archivo);
        linea ++;
        ptr = strtok(caracteres," ");
        while(ptr != NULL)
        {
            if(linea == 1) //linea 1
            {
                if(indice == 0)
                {
                    strcpy(str,ptr);
                    ancho = atoi(str);
                    indice++;
                }
                else
                {
                    strcpy(str,ptr);
                    largo = atoi(str);
                    indice = 0;
                }
            }
                //printf("%s\n", ptr);
            else if (linea!= 1 && linea != 6 && linea != 7) // linea 2-5
            {
                if (indice == 0)
                {

                }
                else
                {

                }
            }
            ptr = strtok(NULL, " ");
        }
    }
    printf("ancho:%d\n",ancho);
    printf("largo:%d\n",largo);
    return 0;
}
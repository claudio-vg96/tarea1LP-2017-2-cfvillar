#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genetic_behaviour.h"

struct celula{
    int id;
    int x; //posicion x
    int y; //posicion y
};


int main()
{
    int movement[4];
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
        // tomamos linea por linea
        fgets(caracteres,100,archivo);
        linea ++;
        printf("caracteres:%s\n", caracteres);
        ptr = strtok(caracteres," ");

        //tomamos cada elemento separado por espacio
        while(ptr != NULL)
        {
            if(linea == 1) //dimensiones universo
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
                    int matriz[ancho][largo]; //definiendo universo

                }
            }
                //printf("%s\n", ptr);
            else if (linea!= 1 && linea != 6 && linea != 7) // linea 2-5 caract genetica
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
    return 0;
}
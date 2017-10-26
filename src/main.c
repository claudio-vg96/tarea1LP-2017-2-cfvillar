#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "genetic_behaviour.h"

struct celula{
    int id;
    int x; //posicion x
    int y; //posicion y
};

void apareamiento(struct celula *cell, int matriz)
{

}

void remover_celula(struct celula *cell, int matriz)
{

}

void usage(const char **argv)
{
    fprintf(stderr, "Usage: %s", *argv);
    exit(EXIT_FAILURE);
}

int main(int argc, const char**argv)
{
    if (argc!= 2){
        usage(argv);
    }

    const char *name = argv[1];
    int cont = 0;
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
    while(!feof(archivo)) {
        // tomamos linea por linea
        fgets(caracteres,100,archivo);
        linea ++;
        printf("linea:%d\n", linea);
        printf("caracteres:%s\n", caracteres);
        strtok(caracteres,"\n");
        ptr = strtok(caracteres," ");
        //tomamos cada elemento separado por espacio
        while(ptr != NULL) {
            if(linea == 1) { //dimensiones universo
                if(indice == 0) {
                    strcpy(str,ptr);
                    ancho = atoi(str);
                    indice++;
                }
                else {
                    strcpy(str,ptr);
                    largo = atoi(str);
                    indice = 0;
                    int matriz[ancho-1][largo-1]; //definiendo universo
                }
            }
            else if (linea == 2 || linea == 3 || linea == 4 || linea == 5) { // A libw.so
                printf("PUNTERO:%s\n", ptr);
                int len;
                char *error;
                char var[15];
                strcpy(var,ptr); // A o libw.so
                len = strlen(var);
                if (len > 1) { // libreria del estilo libw.so cargarla
                    if( strstr(var,"/") != NULL){ // si var contiene a "/"
                        void*handle = dlopen(var,RTLD_NOW);
                        void (*lib)(char event,int *movement);
                        if(!handle){
                            printf("ERROR CARGANDO EL ARCHIVO %s\n", dlerror());
                            exit(1);
                        }
                        lib = dlsym(handle,"libreria");
                        if ((error = dlerror() != NULL )) {
                            fprintf(stderr, "%s\n", error);
                            exit(1);
                        }

                    }
                    else{
                        char ruta[15];
                        strcpy(ruta, "./");
                        strcat(ruta,var);
                        printf("RUTA:%s\n",ruta);
                        void *handle = dlopen(ruta,RTLD_NOW);
                        if(handle == NULL) {
                            fprintf(stderr, "dlopen:%s\n", dlerror());
                            exit(EXIT_FAILURE);
                        }
                        void (*lib) (char, int) = dlsym(handle,"libreria");
                        if(lib == NULL){
                            fprintf(stderr, "dlsym:%s\n", dlerror());
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
            ptr = strtok(NULL, " ");
        }
    }
    return 0;
}
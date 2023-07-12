#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNodo {
    char* producto;
    float precio;
    int codigo;
    struct sNodo* sig;
};

typedef struct sNodo* tNodo;

struct sNodoAux {
    char producto[50];
    float precio;
    int codigo;
};

typedef struct sNodoAux tNodoAux;

void eliminarPorRangoPrecios(tNodo* ls, float min, float max) {
    if (*ls != NULL) {
        if ( (*ls)->precio > min && (*ls)->precio < max ) {
            tNodo aux = *ls;
            *ls = (*ls)->sig;
            free(aux);
            eliminarPorRangoPrecios( ls, min, max );
        } else {
            eliminarPorRangoPrecios( &((*ls)->sig), min, max );
        }
    }
}

void imprimirListaR(tNodo ls) {
    if (ls != NULL) {
        printf("%-14s %7.1f %7d\n", ls->producto, ls->precio, ls->codigo);
        imprimirListaR(ls->sig);
    }
}

void cargarOrdenadoPorNombre(tNodo* ls, char* producto, float precio, int codigo) {
    if (*ls == NULL) {
        *ls = malloc(sizeof(struct sNodo));
        (*ls)->producto = malloc( strlen(producto) + 1 );

        strcpy((*ls)->producto, producto);
        (*ls)->precio = precio;
        (*ls)->codigo = codigo;

        (*ls)->sig = NULL;
    } else {
        if ( strcmp( (*ls)->producto, producto ) > 0 ) {
            tNodo aux = malloc(sizeof(struct sNodo));
            aux->producto = malloc( strlen(producto) + 1 );
            aux->sig = *ls;

            strcpy(aux->producto, producto);
            aux->precio = precio;
            aux->codigo = codigo;

            *ls = aux;
        } else {
            cargarOrdenadoPorNombre( &((*ls)->sig), producto, precio, codigo );
        }
    }
}

int cargarArchivoLista(tNodo* ls, char* nomArch) {
    FILE* arch;
    arch = fopen(nomArch, "r");

    if (arch == NULL) {
        return -1;
    }

    tNodoAux aux;
    int r = fscanf(arch, "%[^,],%f,%d\n", aux.producto, &aux.precio, &aux.codigo);
    while ( r != EOF ) {
        cargarOrdenadoPorNombre( ls, aux.producto, aux.precio, aux.codigo);
        r = fscanf(arch, "%[^,],%f,%d\n", aux.producto, &aux.precio, &aux.codigo);
    }

    return 0;
}   

int main() {
    tNodo ls = NULL;
    cargarArchivoLista(&ls, "07-repaso-datos.csv");
    imprimirListaR(ls);
    printf("---------\n");
    eliminarPorRangoPrecios(&ls, 5, 20);
    imprimirListaR(ls);

    return 0;
}   
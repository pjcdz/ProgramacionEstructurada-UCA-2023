#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_nodo {
    char* producto;
    float precio;
    int codigo;
    struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;

struct s_nodoAux {
    char producto[50];
    float precio;
    int codigo;
};

typedef struct s_nodoAux t_nodoAux;

void appendOrdenadoNombre( t_nodo* ls, char* producto, float precio, int codigo ) {
    t_nodo aux = NULL;

    if (*ls == NULL) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->producto = malloc( strlen(producto) + 1 );

        strcpy( (*ls)->producto, producto );
        (*ls)->precio = precio;
        (*ls)->codigo = codigo;

        (*ls)->sig = NULL;
    } else {
        if ( strcmp( (*ls)->producto, producto ) > 0 ) {
            aux = malloc(sizeof(struct s_nodo));
            aux->producto = malloc( strlen(producto) + 1 );
            aux->sig = (*ls);

            strcpy(  aux->producto , producto );
            aux->precio = precio;
            aux->codigo = codigo;

            (*ls) = aux;
        } else {
            appendOrdenadoNombre ( &((*ls)->sig), producto, precio, codigo );
        }
    }
}

int cargaArchivoEnLista(t_nodo* ls, char* archivo) {
    FILE* arch;
    arch = fopen(archivo, "r");

    if ( arch == NULL ) {
        return -1;
        printf("error");
    }

    t_nodoAux aux;
    int r = fscanf(arch, "%[^,], %f, %d\n", aux.producto, &aux.precio, &aux.codigo);
    while ( r != EOF ) {
        // printf("%-16s || %7.1f || %6d\n", aux.producto, aux.precio, aux.codigo);    
        appendOrdenadoNombre( &(*ls), aux.producto, aux.precio, aux.codigo );
        r = fscanf(arch, "%[^,], %f, %d\n", aux.producto, &aux.precio, &aux.codigo);
    }

    return 0;
}

void imprimirRecursivo (t_nodo ls) {
    if (ls != NULL) {
        printf("%-16s || %7.1f || %6d\n", ls->producto, ls->precio, ls->codigo);    
        imprimirRecursivo ( ls->sig );
    }
}

void eliminarRangoPrecios (t_nodo* ls, float min, float max ) {
    t_nodo aux = NULL;
    if (*ls != NULL) {
        if ( (*ls)->precio >= min && (*ls)->precio <= max ) {
            aux = (*ls);
            (*ls) = (*ls)->sig;
            free(aux);
            eliminarRangoPrecios( &(*ls), min, max );
        } else {
            eliminarRangoPrecios( &((*ls)->sig), min, max );
        }
    }
}

void busquedaPorCodigo (t_nodo* ls, t_nodo* resultado, int codigo) {
    if (*ls != NULL) {
        if ( (*ls)->codigo == codigo ) {
            appendOrdenadoNombre ( &(*resultado), (*ls)->producto, (*ls)->precio, (*ls)->codigo );
            busquedaPorCodigo( &((*ls)->sig), &(*resultado), codigo);
        } else {
            busquedaPorCodigo( &((*ls)->sig), &(*resultado), codigo);
        }
    }
}

int main() {
    t_nodo ls = NULL;

    cargaArchivoEnLista(&ls, "06-parcial-datos.csv");
    imprimirRecursivo(ls);

    printf("-------------------\n");
    // eliminarRangoPrecios(&ls, 5, 20);
    // imprimirRecursivo(ls);

    t_nodo resultado = NULL;
    busquedaPorCodigo(&ls, &resultado, 736);
    imprimirRecursivo(resultado);

    
}
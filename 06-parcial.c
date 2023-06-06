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

void appendUltimo (t_nodo* ls, char* producto, float precio, int codigo) {
    if (*ls == NULL) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->producto = malloc( strlen(producto) * sizeof(char));

        strcpy((*ls)->producto, producto);
        (*ls)->precio = precio;
        (*ls)->codigo = codigo;

        (*ls)->sig = NULL;
    } else {
        appendUltimo( &((*ls)->sig), producto, precio, codigo);
    }
}

void appendOrdenadoCodigo (t_nodo *ls, char* producto, float precio, int codigo) {
    t_nodo aux = NULL;

    if (*ls == NULL) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->producto = malloc( strlen(producto) * sizeof(char));

        strcpy( (*ls)->producto, producto );
        (*ls)->precio = precio;
        (*ls)->codigo = codigo;

        (*ls)->sig = NULL;
    } else {
        if ( (*ls)->codigo < codigo ) {
            aux = malloc(sizeof(struct s_nodo));
            aux->producto = malloc( strlen(producto) * sizeof(char));
            aux->sig = (*ls);

            strcpy( aux->producto, producto );
            aux->precio = precio;
            aux->codigo = codigo;

            (*ls) = aux;
        } else {
            appendOrdenadoCodigo( &((*ls)->sig), producto, precio, codigo );
        }
    }
}

int leerArchCargaLs (t_nodo* ls, char* archivo) {
    FILE* arch;
    arch = fopen(archivo, "r");

    if ( arch == NULL ) {
        return -1;
    }

    t_nodoAux aux;
    int r = fscanf(arch, "%[^,], %f, %d", aux.producto, &aux.precio, &aux.codigo);

    while (r != EOF) {
        // appendUltimo( ls, aux.producto, aux.precio, aux.codigo);
        appendOrdenadoCodigo( ls, aux.producto, aux.precio, aux.codigo);
        // printf("%-16s | %7.01f | %6d", aux.producto, aux.precio, aux.codigo);
        r = fscanf(arch, "%[^,], %f, %d", aux.producto, &aux.precio, &aux.codigo);
    }

    // strcpy(aux.producto, "\0");
    // aux.precio = -1;
    // aux.codigo = -1;
    // appendUltimo( ls, aux.producto, aux.precio, aux.codigo);

    return 0;
}

void imprimirRecursivo(t_nodo ls) {
    if (ls != NULL) {
        printf("%-16s | %7.01f | %6d\n", ls->producto, ls->precio, ls->codigo);
        imprimirRecursivo( ls->sig );
    }
}

int main() {
    t_nodo ls = NULL;
    leerArchCargaLs(&ls, "06-parcial-datos.txt");
    imprimirRecursivo(ls);

    return 0;
}
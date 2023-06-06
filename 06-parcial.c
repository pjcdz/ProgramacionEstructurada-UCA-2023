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

// ################### CargarArchivoEnLista ######################################################################################

void appendUltimo (t_nodo* ls, char* producto, float precio, int codigo) {
    if (*ls == NULL) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->producto = malloc( strlen(producto) + 1 );

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
        (*ls)->producto = malloc( strlen(producto) + 1 );

        strcpy( (*ls)->producto, producto );
        (*ls)->precio = precio;
        (*ls)->codigo = codigo;

        (*ls)->sig = NULL;
    } else {
        if ( (*ls)->codigo < codigo && (*ls)->codigo != -1) {
            aux = malloc(sizeof(struct s_nodo));
            aux->producto = malloc( strlen(producto) + 1 );
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

void appendOrdenadoNombre (t_nodo* ls, char* producto, float precio, int codigo) {
    t_nodo aux = NULL;

    if (*ls == NULL) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->producto = malloc( strlen(producto) + 1 );

        strcpy((*ls)->producto, producto);
        (*ls)->precio = precio;
        (*ls)->codigo = codigo;

        (*ls)->sig = NULL;
    } else {
        if ( strcmp( (*ls)->producto, producto ) > 0 && (*ls)->codigo != -1 ) {
            aux = malloc(sizeof(struct s_nodo));
            aux->producto = malloc( strlen(producto) + 1 );
            aux->sig = (*ls);

            strcpy(aux->producto, producto);
            aux->precio = precio;
            aux->codigo = codigo;

            (*ls) = aux;
        } else {
            appendOrdenadoNombre( &((*ls)->sig), producto, precio, codigo );
        }
    }
}

void appendPrimero(t_nodo* ls, char* producto, float precio, int codigo) {
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->producto = malloc( strlen(producto) + 1 );
    aux->sig = (*ls);

    strcpy(aux->producto, producto);
    aux->precio = precio;
    aux->codigo = codigo;

    (*ls) = aux;
}

int leerArchCargaLs (t_nodo* ls, char* archivo) {
    FILE* arch;
    arch = fopen(archivo, "r");

    if ( arch == NULL ) {
        return -1;
    }

    t_nodoAux aux;
    int r = fscanf(arch, "%[^,], %f, %d\n", aux.producto, &aux.precio, &aux.codigo);

    while (r != EOF) {
        // printf("%-16s | %7.01f | %6d\n", aux.producto, aux.precio, aux.codigo);
        appendUltimo( ls, aux.producto, aux.precio, aux.codigo);
        // appendOrdenadoCodigo( ls, aux.producto, aux.precio, aux.codigo);
        // appendOrdenadoNombre( ls, aux.producto, aux.precio, aux.codigo);
        // appendPrimero( ls, aux.producto, aux.precio, aux.codigo);
        r = fscanf(arch, "%[^,], %f, %d\n", aux.producto, &aux.precio, &aux.codigo);
    }

    aux.producto[0] = '\0';
    aux.precio = -1;
    aux.codigo = -1;
    appendUltimo( ls, aux.producto, aux.precio, aux.codigo);

    return 0;
}

// ################### ImprimirLista ######################################################################################

void imprimirRecursivo(t_nodo ls) {
    if (ls != NULL && ls->codigo != -1) {
        printf("%-16s | %7.01f | %6d\n", ls->producto, ls->precio, ls->codigo);
        imprimirRecursivo( ls->sig );
    }
}

// void imprimirIterativo(t_nodo ls) {
//     while (ls != NULL && ls->codigo != -1) {
//         printf("%-16s | %7.01f | %6d\n", ls->producto, ls->precio, ls->codigo);
//         ls = ls->sig;
//     }
// }

// ################### EliminarDeLaLista ######################################################################################

void eliminar1Codigo (t_nodo *ls, int codigo) {
    t_nodo aux = NULL;
    if (*ls != NULL) {
        if ( (*ls)->codigo == codigo ) {
            aux = (*ls);
            (*ls) = (*ls)->sig;
            free(aux);
        } else {
            eliminar1Codigo ( &((*ls)->sig), codigo);
        }   
    }
}

void eliminar1Producto (t_nodo *ls, char* producto) {
    t_nodo aux = NULL;
    if (*ls != NULL) {
        if ( strcmp( (*ls)->producto, producto ) == 0 ) {
            aux = (*ls);
            (*ls) = (*ls)->sig;
            free(aux);
        } else {
            eliminar1Producto ( &((*ls)->sig), producto );
        }
    }
}

void eliminarTodasCodigo (t_nodo* ls, int codigo) {
    t_nodo aux = NULL;
    if (*ls != NULL) {
        if ( (*ls)->codigo == codigo ) {
            aux = (*ls);
            (*ls) = (*ls)->sig;
            free(aux);
            eliminarTodasCodigo( &(*ls), codigo );
        } else {
            eliminarTodasCodigo( &((*ls)->sig), codigo );
        }
    }
}

void eliminarTodasProducto (t_nodo* ls, char* producto) {
    t_nodo aux = NULL;
    if (*ls != NULL) {
        if ( strcmp( (*ls)->producto, producto ) == 0 ) {
            aux = (*ls);
            (*ls) = (*ls)->sig;
            free(aux);
            eliminarTodasProducto( &(*ls), producto );
        } else {
            eliminarTodasProducto( &((*ls)->sig), producto );
        }
    }
}

// ################### Main ######################################################################################

int main() {
    t_nodo ls = NULL;
    leerArchCargaLs(&ls, "06-parcial-datos.csv");
    imprimirRecursivo(ls);
    printf("---------------------------------------\n");
    // eliminar1Codigo(&ls, 1024);
    // eliminar1Producto(&ls, "Regla 30");
    // eliminarTodasCodigo(&ls, 1024);
    // eliminarTodasProducto(&ls, "Lapicera Bic");
    imprimirRecursivo(ls);
    // imprimirIterativo(ls);

    return 0;
}
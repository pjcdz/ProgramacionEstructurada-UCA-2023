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

void appendOrdenadoNombre (t_nodo* ls, char* producto, float precio, int codigo) {
    if (*ls == NULL) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->producto = malloc ( strlen(producto) + 1 );

        strcpy( (*ls)->producto, producto );
        (*ls)->precio = precio;
        (*ls)->codigo = codigo;

        (*ls)->sig = NULL;
    } else {
        if ( strcmp( (*ls)->producto, producto ) > 0 ) {
            t_nodo aux = malloc(sizeof(struct s_nodo));
            aux->producto = malloc( strlen(producto) + 1 );

            aux->sig = (*ls);

            strcpy( aux->producto, producto );
            aux->precio = precio;
            aux->codigo = codigo;

            (*ls) = aux;
        } else {
            appendOrdenadoNombre ( &((*ls)->sig), producto, precio, codigo );
        }
    }
}

int leerArchivoCargarLs(t_nodo* ls, char* archivo) {
    FILE* arch;
    arch = fopen(archivo, "r");

    if ( arch == NULL ) {
        printf("error");
        return -1;
    }

    t_nodoAux aux;
    int r = fscanf(arch, "%[^,], %f, %d\n", aux.producto, &aux.precio, &aux.codigo);
    while ( r != EOF ) {
        // printf("%-16s || %7.1f || %6d\n", aux.producto, aux.precio, aux.codigo);
        appendOrdenadoNombre( &(*ls), aux.producto, aux.precio, aux.codigo );
        r = fscanf(arch, "%[^,], %f, %d\n", aux.producto, &aux.precio, &aux.codigo);
    }

    aux.producto[0] = '\0';
    aux.precio = -1;
    aux.codigo = -1;

    fclose(arch);

    return 0;
}

void imprimirRecursiva(t_nodo ls) {
    if (ls != NULL) {
        printf("%-16s || %7.1f || %6d\n", ls->producto, ls->precio, ls->codigo);
        imprimirRecursiva(ls->sig);
    }
}

void eliminarRangoPrecios (t_nodo* ls, float min, float max) {
    t_nodo aux = NULL;

    if (*ls != NULL) {
        if ( (*ls)->precio >= min && (*ls)->precio <= max ) {
            aux = (*ls);
            (*ls) = (*ls)->sig;
            free(aux);
            eliminarRangoPrecios ( &(*ls), min, max );
        } else {
            eliminarRangoPrecios ( &((*ls)->sig), min, max );
        }
    }
}

void busquedaRangoPrecios (t_nodo* ls, t_nodo* resultado, float min, float max) {
    if( *ls != NULL ) {
        if ( (*ls)->precio >= min && (*ls)->precio <= max ) {
            appendOrdenadoNombre( &(*resultado), (*ls)->producto, (*ls)->precio, (*ls)->codigo );
            busquedaRangoPrecios( &((*ls)->sig), &(*resultado), min, max );
        } else {
            busquedaRangoPrecios( &((*ls)->sig), &(*resultado), min, max );
        }
    }
}   

int vocales ( char* str ) {
    if ( *str != '\0' ) {
        int esVocal = ( *str == 'a' || *str == 'e' || *str == 'i' || 
                        *str == 'o' || *str == 'u' || *str == 'A' ||
                        *str == 'E' || *str == 'I' || *str == 'O' ||
                        *str == 'U');

        return esVocal + vocales(str+1);
    } 
}

void busquedaVocales (t_nodo* ls, t_nodo* resultado, int nVocales) {
    if ( *ls != NULL ) {
        if ( vocales((*ls)->producto) == nVocales ) {
            appendOrdenadoNombre ( &(*resultado), (*ls)->producto, (*ls)->precio, (*ls)->codigo );
            busquedaVocales ( &((*ls)->sig), &(*resultado), nVocales );
        } else {
            busquedaVocales ( &((*ls)->sig), &(*resultado), nVocales );
        }
    }
}

int main () {
    t_nodo ls = NULL;

    leerArchivoCargarLs(&ls, "06-parcial-datos.csv");
    imprimirRecursiva(ls);

    printf("-------------------------------------\n");
    eliminarRangoPrecios (&ls, 5, 20);
    imprimirRecursiva(ls);

    // printf("-------------------------------------\n");
    // t_nodo resultado = NULL;
    // busquedaRangoPrecios(&ls, &resultado, 5, 20);
    // imprimirRecursiva(resultado);

    // printf("-------------------------------------\n");
    // // printf("%d", vocales("hola"));
    // t_nodo resultado = NULL;
    // busquedaVocales(&ls, &resultado, 2);
    // imprimirRecursiva(resultado);

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct sNodo {
//     char* producto;
//     float precio;
//     int codigo;
//     struct sNodo* sig;
// };

// typedef struct sNodo* tNodo;

// struct sNodoAux {
//     char producto[50];
//     float precio;
//     int codigo;
// };

// typedef struct sNodoAux tNodoAux;

// void eliminarPorRangoPrecios(tNodo* ls, float min, float max) {
//     if (*ls != NULL) {
//         if ( (*ls)->precio > min && (*ls)->precio < max ) {
//             tNodo aux = *ls;
//             *ls = (*ls)->sig;
//             free(aux);
//             eliminarPorRangoPrecios( ls, min, max );
//         } else {
//             eliminarPorRangoPrecios( &((*ls)->sig), min, max );
//         }
//     }
// }

// void imprimirListaR(tNodo ls) {
//     if (ls != NULL) {
//         printf("%-14s %7.1f %7d\n", ls->producto, ls->precio, ls->codigo);
//         imprimirListaR(ls->sig);
//     }
// }

// void cargarOrdenadoPorNombre(tNodo* ls, char* producto, float precio, int codigo) {
//     if (*ls == NULL) {
//         *ls = malloc(sizeof(struct sNodo));
//         (*ls)->producto = malloc( strlen(producto) + 1 );

//         strcpy((*ls)->producto, producto);
//         (*ls)->precio = precio;
//         (*ls)->codigo = codigo;

//         (*ls)->sig = NULL;
//     } else {
//         if ( strcmp( (*ls)->producto, producto ) > 0 ) {
//             tNodo aux = malloc(sizeof(struct sNodo));
//             aux->producto = malloc( strlen(producto) + 1 );
//             aux->sig = *ls;

//             strcpy(aux->producto, producto);
//             aux->precio = precio;
//             aux->codigo = codigo;

//             *ls = aux;
//         } else {
//             cargarOrdenadoPorNombre( &((*ls)->sig), producto, precio, codigo );
//         }
//     }
// }

// int cargarArchivoLista(tNodo* ls, char* nomArch) {
//     FILE* arch;
//     arch = fopen(nomArch, "r");

//     if (arch == NULL) {
//         return -1;
//     }

//     tNodoAux aux;
//     int r = fscanf(arch, "%[^,],%f,%d\n", aux.producto, &aux.precio, &aux.codigo);
//     while ( r != EOF ) {
//         cargarOrdenadoPorNombre( ls, aux.producto, aux.precio, aux.codigo);
//         r = fscanf(arch, "%[^,],%f,%d\n", aux.producto, &aux.precio, &aux.codigo);
//     }

//     return 0;
// }   

// int main() {
//     tNodo ls = NULL;
//     cargarArchivoLista(&ls, "07-repaso-datos.csv");
//     imprimirListaR(ls);
//     printf("---------\n");
//     eliminarPorRangoPrecios(&ls, 5, 20);
//     imprimirListaR(ls);

//     return 0;
// }   

// ############################################################################################################################################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNodoBin {
    int valor;
    struct sNodoBin* izq;
    struct sNodoBin* der;
};

typedef struct sNodoBin* tNodoBin;

struct sNodo {
    tNodoBin valor;
    struct sNodo* sig;
};

typedef struct sNodo* tNodo;

struct sQueue {
    tNodo head;
    tNodo tail;
};

typedef struct sQueue tQueue;

void eliminarArbol(tNodoBin* arbol) {
    if (*arbol != NULL) {
        eliminarArbol( &((*arbol)->izq) );
        eliminarArbol( &((*arbol)->der) );
        free(*arbol);
        *arbol = NULL;
    }
}

void buscarYBorrarEnArbol( tNodoBin* arbol, int valor ) {
    if (*arbol != NULL) {
        if ( (*arbol)->valor > valor ) {
            buscarYBorrarEnArbol( &((*arbol)->izq), valor );
        } else if ( (*arbol)->valor < valor ) {
            buscarYBorrarEnArbol( &((*arbol)->der), valor );
        } else {
            eliminarArbol( arbol );
        }
    }
}

int sumarUnNivel(tNodoBin arbol, int nivel) {
    int res = 0;

    if (arbol != NULL) {
        if ( nivel == 0 ) {
            res = arbol->valor;
        }

        res = res + sumarUnNivel( arbol->izq, nivel-1 );
        res = res + sumarUnNivel( arbol->der, nivel-1 );
    }

    return res;
}

tNodoBin dequeue(tQueue* cola) {
    tNodoBin valor = NULL;

    tNodo aux = cola->head;
    valor = aux->valor;
    cola->head = cola->head->sig;
    free(aux);

    if (cola->head == NULL) {
        cola->tail = NULL;
    }

    return valor;
}

void queue(tQueue* cola, tNodoBin valor) {
    tNodo aux = malloc(sizeof(struct sNodo));
    aux->valor = valor;
    aux->sig = NULL;

    if ( cola->head == NULL && cola->tail == NULL ) {
        cola->head = aux;
        cola->tail = aux;
    } else {
        cola->tail->sig = aux;
        cola->tail = aux;
    }
}

void porNivelesImprimir( tNodoBin arbol ) {
    tQueue cola = {NULL,NULL};
    tNodoBin nodoAux = NULL;

    queue(&cola, arbol);

    while( cola.head != NULL ) {
        nodoAux = dequeue(&cola);

        if ( nodoAux->izq != NULL ) {
            queue(&cola, nodoAux->izq);
        }

        if ( nodoAux->der != NULL ) {
            queue(&cola, nodoAux->der);
        }

        printf("%d - ", nodoAux->valor);
    }

    printf("\n");
}

void postOrderImprimir(tNodoBin arbol) {
    if (arbol != NULL) {
        postOrderImprimir( arbol->izq );
        postOrderImprimir( arbol->der );
        printf("%d - ", arbol->valor);
    }
}

void inOrderImprimir(tNodoBin arbol) {
    if (arbol != NULL) {
        inOrderImprimir( arbol->izq );
        printf("%d - ", arbol->valor);
        inOrderImprimir( arbol->der );
    }
}

void preOrderImprimir(tNodoBin arbol) {
    if (arbol != NULL) {
        printf("%d - ", arbol->valor);
        preOrderImprimir( arbol->izq );
        preOrderImprimir( arbol->der );
    }
}

void insertarEnArbol(tNodoBin* arbol, int valor) {
    if ( *arbol == NULL ) {
        *arbol = malloc(sizeof(struct sNodoBin));
        (*arbol)->valor = valor;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    } else {
        if ( (*arbol)->valor > valor ) {
            insertarEnArbol( &((*arbol)->izq), valor );
        } else {
            insertarEnArbol( &((*arbol)->der), valor );
        }
    }
}

int main() {
    tNodoBin arbol = NULL;

    insertarEnArbol( &arbol, 35 );
    insertarEnArbol( &arbol, 45 );
    insertarEnArbol( &arbol, 30 );
    insertarEnArbol( &arbol, 20 );
    insertarEnArbol( &arbol, 15 );
    insertarEnArbol( &arbol, 40 );
    insertarEnArbol( &arbol, 38 );
    insertarEnArbol( &arbol, 41 );
    insertarEnArbol( &arbol, 55 );
    insertarEnArbol( &arbol, 21 );

    printf("-------- preOrder ---------\n");
    preOrderImprimir(arbol);

    printf("\n-------- inOrder ---------\n");
    inOrderImprimir(arbol);

    printf("\n-------- postOrder ---------\n");
    postOrderImprimir(arbol);

    printf("\n-------- por niveles Imprimir ---------\n");
    porNivelesImprimir(arbol);

    printf("\n-------- Sumatoria de un nivel ---------\n");
    printf("%d \n", sumarUnNivel(arbol, 3) );

    printf("\n-------- Buscar y borrar valor ---------\n");
    buscarYBorrarEnArbol(&arbol, 20);

    printf("\n-------- inOrder ---------\n");
    inOrderImprimir(arbol);

    return 0;
}

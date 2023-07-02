// ################### LISTAS ######################################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNodo{
    int valor;
    struct sNodo* sig;
};

typedef struct sNodo* tNodo;

// ------------------------

void insertarEnListaPrimero(tNodo*, int);
void insertarEnListaUltimo(tNodo*, int);
void insertarEnListaPorPosicion(tNodo*, int, int);
void insertarEnListaOrdenado(tNodo*, int);

void eliminarEnListaPorValor(tNodo* nodo, int);
int eliminarEnListaPorPosicion(tNodo* nodo, int);

void imprimirListaI(tNodo);
void imprimirListaR(tNodo);
void imprimirListaInversaR(tNodo);

int largoLista(tNodo);
void eliminarlista(tNodo*);
int esListaVacia(tNodo);

// ------------------------

int main() {
    int n,c;
    tNodo ls = NULL;

    printf("-------------------------\n");

    insertarEnListaUltimo(&ls, 10);
    insertarEnListaUltimo(&ls, 20);
    insertarEnListaUltimo(&ls, 30);
    insertarEnListaUltimo(&ls, 114);
    imprimirListaI(ls);

    printf("\n-------------------------\n");

    insertarEnListaPrimero(&ls, 114);
    insertarEnListaPrimero(&ls, 7);
    imprimirListaR(ls);

    printf("\n-------------------------\n");

    eliminarEnListaPorValor(&ls, 114);
    imprimirListaR(ls);

    printf("\n-------------------------\n");

    insertarEnListaOrdenado(&ls, 22);
    insertarEnListaOrdenado(&ls, 3);
    imprimirListaR(ls);

    printf("\n-------------------------\n");

    int val = eliminarEnListaPorPosicion(&ls, 1);
    printf("Se elimino de la lista: %d\n", val);
    imprimirListaR(ls);

    printf("\n-------------------------\n");

    insertarEnListaPorPosicion(&ls, 111, 1);
    imprimirListaR(ls);

    printf("\n-------------------------\n");

    printf("Inversa:\n");
    imprimirListaInversaR(ls);

    printf("\n-------------------------\n");

}

// ------------------------

void insertarEnListaUltimo(tNodo* ls, int valor) {
    if (*ls == NULL) {
        *ls = malloc(sizeof(struct sNodo));
        (*ls)->valor = valor;
        (*ls)->sig = NULL;
    } else {
        insertarEnListaUltimo( &((*ls)->sig) , valor );
    }
}

void imprimirListaR(tNodo ls) {
    if (ls != NULL) {
        printf("%d ", ls->valor);
        imprimirListaR(ls->sig);
    }
}

// ------------------------

void insertarEnListaPrimero(tNodo* ls, int valor) {
    tNodo aux = malloc(sizeof(struct sNodo));

    aux->valor = valor;
    aux->sig = *ls;

    *ls = aux;
}

void imprimirListaI(tNodo ls) {
    while (ls!=NULL) {
        printf("%d ", ls->valor);
        ls = ls->sig;
    }
}

// ------------------------

void eliminarEnListaPorValor(tNodo* ls, int valor) {
    tNodo aux = NULL;

    if (*ls!=NULL) {
        if ( (*ls)->valor == valor ) {
            aux = *ls;
            *ls = (*ls)->sig;
            free(aux);
            eliminarEnListaPorValor( &(*ls), valor );
        } else {
            eliminarEnListaPorValor( &((*ls)->sig), valor );
        }
    }
}

// ------------------------

void insertarEnListaOrdenado(tNodo* ls, int valor) {
    tNodo aux = malloc(sizeof(struct sNodo));

    if (*ls == NULL) {
        *ls = malloc(sizeof(struct sNodo));
        (*ls)->valor = valor;
        (*ls)->sig = NULL;
    } else {
        if ( (*ls)->valor > valor ) {
            aux->valor = valor;
            aux->sig = (*ls);
            (*ls) = aux;
        } else {
            insertarEnListaOrdenado( &((*ls)->sig), valor );
        }
    }
}

// ------------------------

int eliminarEnListaPorPosicion(tNodo* ls, int pos) {
    int eliminado = 0;
    tNodo aux = NULL;

    if ( *ls != NULL && pos == 0) {
        aux = *ls;
        eliminado = aux->valor;
        *ls = (*ls)->sig;
        free(aux);
    } else {
        eliminado = eliminarEnListaPorPosicion( &((*ls)->sig), pos-1);
    }

    return eliminado;
}

// ------------------------

void insertarEnListaPorPosicion(tNodo* ls, int valor, int pos) {
    tNodo aux = malloc(sizeof(struct sNodo));
    if ( pos == 0 ) {
        aux->valor = valor;
        aux->sig = *ls;
        *ls = aux;
    } else {
        insertarEnListaPorPosicion( &((*ls)->sig), valor, pos-1 );
    }
}

// ------------------------

void imprimirListaInversaR(tNodo ls) {
    if (ls !=NULL) {
        imprimirListaInversaR(ls->sig);
        printf("%d ", ls->valor);
    }
}
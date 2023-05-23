// ############################# EJ 01 #######################################################################################

#include <stdio.h>
#include <stdlib.h>

struct s_nodo {
    int val;
    struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;

void append(t_nodo* nodo, int val) {
    if ( *nodo == NULL ) {
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->val = val;
        (*nodo)->sig = NULL;
    } else {
        append( &((*nodo)->sig), val );
    }
}

void imprimirLsRecursivo(t_nodo ls) {
    if ( ls != NULL ) {
        printf("valor=%d, dirNodo:<%p>, dirSig:<%p>\n",(ls)->val,ls,ls->sig);
        imprimirLsRecursivo ( ls->sig );
    }
}

void imprimirLsRecursivoInverso(t_nodo ls) {
    if ( ls != NULL ) {
        imprimirLsRecursivoInverso ( ls->sig );
        printf("valor=%d, dirNodo:<%p>, dirSig:<%p>\n",(ls)->val,ls,ls->sig);
    }
}


int main() {
    t_nodo ls = NULL;
    append(&ls, 14);
    append(&ls, 17);
    append(&ls, 20);
    append(&ls, 23);
    imprimirLsRecursivo(ls);
    printf("----------------\n");
    imprimirLsRecursivoInverso(ls);

    return 0;
}
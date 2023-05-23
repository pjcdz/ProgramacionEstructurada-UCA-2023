// ############################# EJ 01 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// struct s_nodo {
//     int val;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void append(t_nodo* nodo, int val) {
//     if ( *nodo == NULL ) {
//         *nodo = malloc(sizeof(struct s_nodo));
//         (*nodo)->val = val;
//         (*nodo)->sig = NULL;
//     } else {
//         append( &((*nodo)->sig), val );
//     }
// }

// void imprimirLsRecursivo(t_nodo ls) {
//     if ( ls != NULL ) {
//         printf("valor=%d, dirNodo:<%p>, dirSig:<%p>\n",(ls)->val,ls,ls->sig);
//         imprimirLsRecursivo ( ls->sig );
//     }
// }

// void imprimirLsRecursivoInverso(t_nodo ls) {
//     if ( ls != NULL ) {
//         imprimirLsRecursivoInverso ( ls->sig );
//         printf("valor=%d, dirNodo:<%p>, dirSig:<%p>\n",(ls)->val,ls,ls->sig);
//     }
// }


// int main() {
//     t_nodo ls = NULL;
//     append(&ls, 14);
//     append(&ls, 17);
//     append(&ls, 20);
//     append(&ls, 23);
//     imprimirLsRecursivo(ls);
//     printf("----------------\n");
//     imprimirLsRecursivoInverso(ls);

//     return 0;
// }

// ############################# EJ 01.01 #######################################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_nodo {
    char* nombre;
    char* apellido;
    int dni;
    struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;

void append(t_nodo* nodo, char* nombre, char* apellido, int dni) {
    if ( *nodo == NULL ) {
        *nodo = malloc(sizeof(struct s_nodo));
        // printf("%s, %s\n", nombre, apellido);
        (*nodo)->nombre = malloc( (strlen(nombre)) * sizeof(char) );
        strcpy( (*nodo)->nombre, nombre);
        (*nodo)->apellido = malloc( (strlen(apellido)) * sizeof(char) );
        strcpy( (*nodo)->apellido, apellido);
        (*nodo)->dni = dni;
        (*nodo)->sig = NULL;
    } else {
        append( &((*nodo)->sig), nombre, apellido, dni );
    }
}

void imprimirLsRecursiva (t_nodo ls) {
    if (ls != NULL) {
        printf("nombre: %s, apellido: %s, dni=%d, dirA=<%p>, dirSig=<%p>\n", ls->nombre, ls->apellido, ls->dni, ls, ls->sig);
        imprimirLsRecursiva(ls->sig);
    }
}

void imprimirLsRecursivaInvertida (t_nodo ls) {
    if (ls != NULL) {
        imprimirLsRecursivaInvertida(ls->sig);
        printf("nombre: %s, apellido: %s, dni=%d, dirA=<%p>, dirSig=<%p>\n", ls->nombre, ls->apellido, ls->dni, ls, ls->sig);
    }
}

void freeLista(t_nodo ls) {
    if (ls != NULL) {
        freeLista(ls->sig);
        free(ls->nombre);
        free(ls->apellido);
        free(ls);
    }
}

int main() {
    t_nodo ls = NULL;
    append(&ls, "Juan", "Martinez", 123);
    append(&ls, "Laura", "Adam", 456);
    append(&ls, "Andrew", "Ryan", 789);

    imprimirLsRecursiva(ls);
    printf("----------------\n");
    imprimirLsRecursivaInvertida(ls);

    freeLista(ls);

    return 0;
}

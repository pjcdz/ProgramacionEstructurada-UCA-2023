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

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct s_nodo {
//     char* nombre;
//     char* apellido;
//     int dni;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void append(t_nodo* nodo, char* nombre, char* apellido, int dni) {
//     if ( *nodo == NULL ) {
//         *nodo = malloc(sizeof(struct s_nodo));
//         // printf("%s, %s\n", nombre, apellido);
//         (*nodo)->nombre = malloc( (strlen(nombre)) * sizeof(char) );
//         strcpy( (*nodo)->nombre, nombre);
//         (*nodo)->apellido = malloc( (strlen(apellido)) * sizeof(char) );
//         strcpy( (*nodo)->apellido, apellido);
//         (*nodo)->dni = dni;
//         (*nodo)->sig = NULL;
//     } else {
//         append( &((*nodo)->sig), nombre, apellido, dni );
//     }
// }

// void imprimirLsRecursiva (t_nodo ls) {
//     if (ls != NULL) {
//         printf("nombre: %s, apellido: %s, dni=%d, dirA=<%p>, dirSig=<%p>\n", ls->nombre, ls->apellido, ls->dni, ls, ls->sig);
//         imprimirLsRecursiva(ls->sig);
//     }
// }

// void imprimirLsRecursivaInvertida (t_nodo ls) {
//     if (ls != NULL) {
//         imprimirLsRecursivaInvertida(ls->sig);
//         printf("nombre: %s, apellido: %s, dni=%d, dirA=<%p>, dirSig=<%p>\n", ls->nombre, ls->apellido, ls->dni, ls, ls->sig);
//     }
// }

// void freeLista(t_nodo ls) {
//     if (ls != NULL) {
//         freeLista(ls->sig);
//         free(ls->nombre);
//         free(ls->apellido);
//         free(ls);
//     }
// }

// int main() {
//     t_nodo ls = NULL;
//     append(&ls, "Juan", "Martinez", 123);
//     append(&ls, "Laura", "Adam", 456);
//     append(&ls, "Andrew", "Ryan", 789);

//     imprimirLsRecursiva(ls);
//     printf("----------------\n");
//     imprimirLsRecursivaInvertida(ls);

//     freeLista(ls);

//     return 0;
// }

// ############################# EJ 01.02 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct employee {
//     int id;
//     char* name;
//     struct address* datos;
//     struct employee* sig;
// };

// typedef struct employee* e_node;

// struct address {
//     char* street;
//     char* city;
//     char* state;
//     int zip;
// } addr;

// void append(e_node* ls, int id, char* name, char* street, char* city, char* state, int zip) {
//     if ( *ls == NULL ) {
//         *ls = malloc( sizeof(struct employee) );

//         (*ls)->id = id;
//         (*ls)->name = malloc( strlen(name) * sizeof(char) );
//         strcpy ( (*ls)->name, name ); // ya se esta pasando con el * asi que no lo agrego nuevamente

//         // (*ls)->datos = NULL; // Malloc reará automáticamente un puntero 
//         // válido a la estructura address, por lo que no es necesario
//         // inicializarlo con NULL antes de asignar memoria.

//         (*ls)->datos = malloc ( sizeof(struct address) );
//         (*ls)->datos->street =  malloc( strlen(street) * sizeof(char) );
//         (*ls)->datos->city =  malloc( strlen(city) * sizeof(char) );
//         (*ls)->datos->state =  malloc( strlen(state) * sizeof(char) );
        
//         strcpy ( (*ls)->datos->street, street ); 
//         strcpy ( (*ls)->datos->city , city ); 
//         strcpy ( (*ls)->datos->state, state );
//         (*ls)->datos->zip = zip;
        
//         (*ls)->sig = NULL;
//     } else {
//         append( &((*ls)->sig), id, name, street, city, state, zip );
//     }
// }

// void imprimirLsRecursiva (e_node ls) {
//     if (ls != NULL) {
//         printf("Datos del empleado: ID = %d, Nombre = %s\n", ls->id, ls->name);
//         printf("Direccion: Calle = %s, State = %s, Ciudad = %s, ZIP = %d\n\n", ls->datos->street, ls->datos->state, ls->datos->state, ls->datos->zip);
//         imprimirLsRecursiva (ls->sig);
//     }
// }

// int main() {
//     e_node ls = NULL;
//     append( &ls, 1, "John Smith", "123 Main St.", "New York", "NY", 10001 );
//     imprimirLsRecursiva(ls);

//     return 0;
// }

// ############################# EJ 02 #######################################################################################

#include <stdio.h>
#include <stdlib.h>

struct s_nodo {
    int val;
    struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;

void appendOrdenado (t_nodo* ls, int val) {
    if ( *ls == NULL ) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->val = val;
        (*ls)->sig = NULL;
    } else {
        if ( val < (*ls)->val ) {
            int temp = (*ls)->val;
            (*ls)->val = val;

            appendOrdenado( &((*ls)->sig), temp );     
        } else {
            appendOrdenado( &((*ls)->sig), val ); 
        }
        
    }
}

void imprimirLsRecursiva (t_nodo ls) {
    if ( ls != NULL ) {
        printf("val: %d, dirAct: <%p>, dirSig: <%p>\n", ls->val, ls, ls->sig);
        imprimirLsRecursiva(ls->sig);
    }
}


int main() {
    t_nodo ls = NULL;
    appendOrdenado(&ls, 20);
    appendOrdenado(&ls, 50);
    appendOrdenado(&ls, 10);
    appendOrdenado(&ls, 30);
    
    imprimirLsRecursiva(ls);

    return 0;
}
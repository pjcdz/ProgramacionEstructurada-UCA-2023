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

// #include <stdio.h>
// #include <stdlib.h>

// struct s_nodo {
//     int val;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void appendOrdenado (t_nodo* ls, int val) {
//     if ( *ls == NULL ) {
//         *ls = malloc(sizeof(struct s_nodo));
//         (*ls)->val = val;
//         (*ls)->sig = NULL;
//     } else {
//         if ( val < (*ls)->val ) {
//             int temp = (*ls)->val;
//             (*ls)->val = val;
//             appendOrdenado( &((*ls)->sig), temp );     
//         } else {
//             appendOrdenado( &((*ls)->sig), val ); 
//         }
        
//     }
// }

// void imprimirLsRecursiva (t_nodo ls) {
//     if ( ls != NULL ) {
//         printf("val: %d, dirAct: <%p>, dirSig: <%p>\n", ls->val, ls, ls->sig);
//         imprimirLsRecursiva(ls->sig);
//     }
// }


// int main() {
//     t_nodo ls = NULL;
//     appendOrdenado(&ls, 20);
//     appendOrdenado(&ls, 50);
//     appendOrdenado(&ls, 10);
//     appendOrdenado(&ls, 30);
    
//     imprimirLsRecursiva(ls);

//     return 0;
// }

// ############################# EJ 02.01.01 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct s_nodo {
//     int dni;
//     char* nombre;
//     char* apellido;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void appendOrdenadoDni(t_nodo* ls, int dni, char* nombre, char* apellido) {
//     if ( *ls == NULL ) {
//         *ls = malloc( sizeof( struct s_nodo ) );
//         (*ls)->nombre = malloc( strlen(nombre) * sizeof(char) );
//         (*ls)->apellido = malloc( strlen(nombre) * sizeof(char) );
//         (*ls)->dni = dni;
//         strcpy( (*ls)->nombre, nombre );
//         strcpy( (*ls)->apellido, apellido );
//         (*ls)->sig = NULL;
//     } else {
//         if ( dni < (*ls)->dni ) {
        //     int tempDni = (*ls)->dni;
        //     (*ls)->dni = dni;
        //     char* tempNombre = malloc ( strlen( (*ls)->nombre ) * sizeof(char) );
        //     char* tempApellido = malloc ( strlen( (*ls)->apellido ) * sizeof(char) );
        //     strcpy( tempNombre, (*ls)->nombre );
        //     strcpy( tempApellido, (*ls)->apellido );
        //     strcpy( (*ls)->nombre, nombre );
        //     strcpy( (*ls)->apellido, apellido );

        //     appendOrdenadoDni( &((*ls)->sig), tempDni, tempNombre, tempApellido );
        // } else {
//             appendOrdenadoDni( &((*ls)->sig), dni, nombre, apellido );
//         }
//     }
// }

// void imprimirLsRecursiva( t_nodo ls ) {
//     if ( ls != NULL ) {
//         printf("DNI: %d, Nombre: %s, Apellido: %s\n", ls->dni, ls->nombre, ls->apellido);
//         printf("dirAct: <%p>, dirSig <%p>\n", ls, ls->sig);
//         imprimirLsRecursiva( ls->sig );
//     }
// }

// int main() {
//     t_nodo ls = NULL;
//     appendOrdenadoDni( &ls, 95127, "Joaquin", "Cam");
//     appendOrdenadoDni( &ls, 45123, "Briana", "White");
//     appendOrdenadoDni( &ls, 53677, "Pablo", "Dozocar");
//     appendOrdenadoDni( &ls, 73253, "Manu", "Cayo");
    
//     imprimirLsRecursiva(ls);

//     return 0;
// }

// ############################# EJ 02.01.02 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct s_nodo {
//     int dni;
//     char* nombre;
//     char* apellido;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void appendOrdenadoApellido ( t_nodo* ls, int dni, char* nombre, char* apellido ) {
//     if (*ls == NULL) {
//         *ls = malloc( sizeof(struct s_nodo) );
//         (*ls)->nombre = malloc ( strlen(nombre) * sizeof(char) );
//         (*ls)->apellido = malloc ( strlen(apellido) * sizeof(char) );

//         (*ls)->dni = dni;
//         strcpy( (*ls)->nombre, nombre );
//         strcpy( (*ls)->apellido, apellido );

//         (*ls)->sig = NULL;
//     } else {
//         if ( strcmp( (*ls)->apellido, apellido ) > 0 ) {
//             int tempDni = (*ls)->dni;
//             (*ls)->dni = dni;
//             char* tempNombre = malloc ( strlen( (*ls)->nombre ) * sizeof(char) );
//             char* tempApellido = malloc ( strlen( (*ls)->apellido ) * sizeof(char) );
//             strcpy( tempNombre, (*ls)->nombre );
//             strcpy( tempApellido, (*ls)->apellido );
            
//             strcpy( (*ls)->nombre, nombre );
//             strcpy( (*ls)->apellido, apellido );

//             appendOrdenadoApellido ( &((*ls)->sig), tempDni, tempNombre, tempApellido );
//         } else {
//             appendOrdenadoApellido ( &((*ls)->sig), dni, nombre, apellido );
//         }
//     }
// }

// void imprimirLsRecursiva( t_nodo ls ) {
//     if ( ls != NULL ) {
//         printf("DNI: %d, Nombre: %s, Apellido: %s\n", ls->dni, ls->nombre, ls->apellido);
//         printf("dirAct: <%p>, dirSig <%p>\n", ls, ls->sig);
//         imprimirLsRecursiva( ls->sig );
//     }
// }

// int main() {
//     t_nodo ls = NULL;
//     appendOrdenadoApellido( &ls, 95127, "Joaquin", "Cam");
//     appendOrdenadoApellido( &ls, 45123, "Briana", "White");
//     appendOrdenadoApellido( &ls, 53677, "Pablo", "Dozocar");
//     appendOrdenadoApellido( &ls, 73253, "Manu", "Myto");
    
//     imprimirLsRecursiva(ls);

//     return 0;
// }

// ############################# EJ 03.00 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// struct s_nodo {
//     int valor;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void appendUltimo (t_nodo* ls, int valor) {
//     if ( *ls == NULL ) {
//         *ls = malloc(sizeof(struct s_nodo));
//         (*ls)->valor = valor;
//         (*ls)->sig = NULL;
//     } else {
//         appendUltimo( &((*ls)->sig), valor );
//     }
// }

// void printRecurviso(t_nodo ls) {
//     if (ls != NULL) {
//         printf("%d ", ls->valor);
//         printRecurviso(ls->sig);
//     }
// }

// void eliminarValor(t_nodo* ls, int valor) {
//     t_nodo aux = NULL;
//     if ( *ls != NULL) {
//         if ( (*ls)-> valor == valor ) {
//             aux = (*ls);
//             *ls = (*ls)->sig;
//             free(aux);
//             // eliminarValor( &(*ls), valor);
//         } else {
//             eliminarValor( &((*ls)->sig), valor);
//         }
//     }
// }


// int main() {
//     t_nodo ls = NULL;

//     appendUltimo(&ls, 3);
//     appendUltimo(&ls, 5);
//     appendUltimo(&ls, 9);
//     appendUltimo(&ls, 5);
//     appendUltimo(&ls, 3);
//     printRecurviso(ls);
//     printf("\n");
//     eliminarValor(&ls, 5);
//     printRecurviso(ls);
//     return 0;
// }

// ############################# EJ 03.01 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// struct s_nodo {
//     int valor;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void appendUltimo(t_nodo* ls, int valor) {
//     if ( *ls == NULL ) {
//         *ls = malloc(sizeof(struct s_nodo));
//         (*ls)->valor = valor;
//         (*ls)->sig = NULL;
//     } else {
//         appendUltimo( &((*ls)->sig), valor );
//     }
// }

// void imprimirRecursivo(t_nodo ls) {
//     if (ls != NULL) {
//         printf("%d ", ls->valor);
//         imprimirRecursivo(ls->sig);
//     }
// }

// void eliminarTodasOcurrencias(t_nodo* ls, int valor) {
//     t_nodo aux = NULL;
//     if (*ls != NULL) {
//         if ( (*ls)->valor == valor ) {
//             aux = (*ls);
//             (*ls) = (*ls)->sig;
//             free(aux);
//             eliminarTodasOcurrencias( &(*ls), valor);
//         } else {
//             eliminarTodasOcurrencias( &((*ls)->sig), valor);
//         }
//     }
// }

// int main() {
//     t_nodo ls = NULL;

//     appendUltimo(&ls, 5);
//     appendUltimo(&ls, 5);
//     appendUltimo(&ls, 5);
//     appendUltimo(&ls, 9);
//     imprimirRecursivo(ls);
//     printf("\n");
//     eliminarTodasOcurrencias(&ls, 5);
//     imprimirRecursivo(ls);

//     return 0;
// }

// ############################# EJ 03.02.01 #######################################################################################

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

// void appendUltimo (t_nodo* ls, char* nombre, char* apellido, int dni) {
//     if (*ls == NULL) {
//         *ls = malloc(sizeof(struct s_nodo));
//         (*ls)->nombre = malloc( strlen(nombre) * sizeof(char));
//         (*ls)->apellido = malloc( strlen(apellido) * sizeof(char));

//         strcpy( (*ls)->nombre, nombre );
//         strcpy( (*ls)->apellido, apellido );
//         (*ls)->dni = dni;
//         (*ls)->sig = NULL;
//     } else {
//         appendUltimo ( &((*ls)->sig), nombre, apellido, dni);
//     }
// }

// void imprimirRecursivo(t_nodo ls) {
//     if (ls != NULL) {
//         printf("DNI: %d, Nombre: %s, Apellido: %s\n", ls->dni, ls->nombre, ls->apellido);
//         printf("dirAct: <%p>, dirSig <%p>\n", ls, ls->sig);
//         imprimirRecursivo( ls->sig );
//     }
// }

// void eliminarUnaOcurrencia(t_nodo* ls, int dni) {
//     t_nodo aux = NULL;
//     if (*ls != NULL) {
//         if ( (*ls)->dni == dni ) {
//             aux = (*ls);
//             (*ls) = (*ls)->sig;
//             free(aux);
//             eliminarUnaOcurrencia( &(*ls), dni );
//         } else {
//             eliminarUnaOcurrencia( &((*ls)->sig), dni );
//         }
//     }
// }

// int main() {
//     t_nodo ls = NULL;

//     appendUltimo( &ls, "Joaquin", "Cam", 3451);
//     appendUltimo( &ls, "Briana", "White", 12313);
//     appendUltimo( &ls, "Pablo", "Dozocar", 9341);
//     appendUltimo( &ls, "Manu", "Myto", 45764);
//     appendUltimo( &ls, "Pablo", "Dozocar", 9341);
//     imprimirRecursivo(ls);
//     printf("\n");
//     eliminarUnaOcurrencia(&ls, 9341);
//     imprimirRecursivo(ls);

//     return 0;
// }

// ############################# EJ 04 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// struct s_nodo {
//     int valor;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void appendUltimo(t_nodo* ls, int valor) {
//     if (*ls == NULL) {
//         *ls = malloc(sizeof(struct s_nodo));
//         (*ls)->valor = valor;
//         (*ls)->sig = NULL;
//     } else {
//         appendUltimo( &((*ls)->sig), valor );
//     }
// }

// void imprimirRecursivo(t_nodo ls) {
//     if (ls != NULL) {
//         printf("%d ", ls->valor);
//         imprimirRecursivo(ls->sig);
//     }
// }

// int eliminarNodoPorPosicion(t_nodo* ls, int pos) {
//     t_nodo aux = NULL;
//     int valor = 0;

//     if (*ls != NULL) {
//         if ( pos == 0) {
//             aux = (*ls);
//             valor = aux->valor;
//             (*ls) = (*ls)->sig;
//             free(aux);
//         } else if ( pos > 0) {
//             valor = eliminarNodoPorPosicion( &((*ls)->sig), pos-1 );
//         }
//     }

//     return valor;
// }

// int main() {
//     t_nodo ls = NULL;

//     appendUltimo(&ls, 1);
//     appendUltimo(&ls, 2);
//     appendUltimo(&ls, 3);
//     appendUltimo(&ls, 4);
//     appendUltimo(&ls, 5);
//     imprimirRecursivo(ls);
//     printf("\n");
//     int eliminado = eliminarNodoPorPosicion(&ls, 0);
//     printf("Eliminado: %d\n", eliminado);

//     imprimirRecursivo(ls);

//     return 0;
// }


// ############################# EJ 04 #######################################################################################

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

void appendUltimo(t_nodo* ls, char* nombre, char* apellido, int dni) {
    if (*ls == NULL) {
        *ls = malloc(sizeof(struct s_nodo));
        (*ls)->nombre = malloc( strlen(nombre) * sizeof(char));
        (*ls)->apellido = malloc( strlen(apellido) * sizeof(char));

        strcpy((*ls)->nombre, nombre);
        strcpy((*ls)->apellido, apellido);
        (*ls)->dni = dni;
        (*ls)->sig = NULL;
    } else {
        appendUltimo( &((*ls)->sig), nombre, apellido, dni );
    }
}

void imprimirRecursivo(t_nodo ls) {
    if (ls != NULL) {
        printf("DNI: %d, Nombre: %s, Apellido: %s\n", ls->dni, ls->nombre, ls->apellido);
        printf("dirAct: <%p>, dirSig <%p>\n", ls, ls->sig);
        imprimirRecursivo( ls->sig );
    }
}

t_nodo eliminarPorPosicionEstructuraCompleja(t_nodo* ls, int pos) {
    t_nodo aux = NULL;
    t_nodo output = NULL;
    
    if (*ls != NULL) {
        if (pos == 0) {
            aux = (*ls);
            
            output = malloc(sizeof(struct s_nodo));
            output->nombre = malloc( strlen(aux->nombre) * sizeof(char));
            output->apellido = malloc( strlen(aux->apellido) * sizeof(char));
            
            strcpy(output->nombre, aux->nombre);
            strcpy(output->apellido, aux->apellido);
            output->dni = aux->dni;

            (*ls) = (*ls)->sig;
            free(aux);
        } else if (pos > 0) {
            output = eliminarPorPosicionEstructuraCompleja( &((*ls)->sig), pos-1);
        }
    }

    return output;
}

int main() {
    t_nodo ls = NULL;
    appendUltimo( &ls, "Joaquin", "Cam", 3451);
    appendUltimo( &ls, "Briana", "White", 12313);
    appendUltimo( &ls, "Pablo", "Dozocar", 9341);
    appendUltimo( &ls, "Manu", "Myto", 45764);
    imprimirRecursivo(ls);
    printf("\n");

    t_nodo eliminado = NULL;
    eliminado = eliminarPorPosicionEstructuraCompleja(&ls, 2);
    printf("Eliminado:\n");
    printf("DNI: %d, Nombre: %s, Apellido: %s\n\n", eliminado->dni, eliminado->nombre, eliminado->apellido);

    imprimirRecursivo(ls);

    return 0;
}
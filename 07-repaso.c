// ################### LISTAS ######################################################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct sNodo{
//     int valor;
//     struct sNodo* sig;
// };

// typedef struct sNodo* tNodo;

// // ------------------------

// void insertarEnListaPrimero(tNodo*, int);
// void insertarEnListaUltimo(tNodo*, int);
// void insertarEnListaPorPosicion(tNodo*, int, int);
// void insertarEnListaOrdenado(tNodo*, int);

// void eliminarEnListaPorValor(tNodo* nodo, int);
// int eliminarEnListaPorPosicion(tNodo* nodo, int);

// void imprimirListaI(tNodo);
// void imprimirListaR(tNodo);
// void imprimirListaInversaR(tNodo);

// int largoLista(tNodo);
// void eliminarlista(tNodo*);
// int esListaVacia(tNodo);

// // ------------------------

// int main() {
//     int n,c;
//     tNodo ls = NULL;

//     printf("-------------------------\n");

//     insertarEnListaUltimo(&ls, 10);
//     insertarEnListaUltimo(&ls, 20);
//     insertarEnListaUltimo(&ls, 30);
//     insertarEnListaUltimo(&ls, 114);
//     imprimirListaI(ls);

//     printf("\n-------------------------\n");

//     insertarEnListaPrimero(&ls, 114);
//     insertarEnListaPrimero(&ls, 7);
//     imprimirListaR(ls);

//     printf("\n-------------------------\n");

//     eliminarEnListaPorValor(&ls, 114);
//     imprimirListaR(ls);

//     printf("\n-------------------------\n");

//     insertarEnListaOrdenado(&ls, 22);
//     insertarEnListaOrdenado(&ls, 3);
//     imprimirListaR(ls);

//     printf("\n-------------------------\n");

//     int val = eliminarEnListaPorPosicion(&ls, 1);
//     printf("Se elimino de la lista: %d\n", val);
//     imprimirListaR(ls);

//     printf("\n-------------------------\n");

//     insertarEnListaPorPosicion(&ls, 111, 1);
//     imprimirListaR(ls);

//     printf("\n-------------------------\n");

//     printf("Inversa:\n");
//     imprimirListaInversaR(ls);

//     printf("\n-------------------------\n");

// }

// // ------------------------

// void insertarEnListaUltimo(tNodo* ls, int valor) {
//     if (*ls == NULL) {
//         *ls = malloc(sizeof(struct sNodo));
//         (*ls)->valor = valor;
//         (*ls)->sig = NULL;
//     } else {
//         insertarEnListaUltimo( &((*ls)->sig) , valor );
//     }
// }

// void imprimirListaR(tNodo ls) {
//     if (ls != NULL) {
//         printf("%d ", ls->valor);
//         imprimirListaR(ls->sig);
//     }
// }

// // ------------------------

// void insertarEnListaPrimero(tNodo* ls, int valor) {
//     tNodo aux = malloc(sizeof(struct sNodo));

//     aux->valor = valor;
//     aux->sig = *ls;

//     *ls = aux;
// }

// void imprimirListaI(tNodo ls) {
//     while (ls!=NULL) {
//         printf("%d ", ls->valor);
//         ls = ls->sig;
//     }
// }

// // ------------------------

// void eliminarEnListaPorValor(tNodo* ls, int valor) {
//     tNodo aux = NULL;

//     if (*ls!=NULL) {
//         if ( (*ls)->valor == valor ) {
//             aux = *ls;
//             *ls = (*ls)->sig;
//             free(aux);
//             eliminarEnListaPorValor( &(*ls), valor );
//         } else {
//             eliminarEnListaPorValor( &((*ls)->sig), valor );
//         }
//     }
// }

// // ------------------------

// void insertarEnListaOrdenado(tNodo* ls, int valor) {
//     tNodo aux = malloc(sizeof(struct sNodo));

//     if (*ls == NULL) {
//         *ls = malloc(sizeof(struct sNodo));
//         (*ls)->valor = valor;
//         (*ls)->sig = NULL;
//     } else {
//         if ( (*ls)->valor > valor ) {
//             aux->valor = valor;
//             aux->sig = (*ls);
//             (*ls) = aux;
//         } else {
//             insertarEnListaOrdenado( &((*ls)->sig), valor );
//         }
//     }
// }

// // ------------------------

// int eliminarEnListaPorPosicion(tNodo* ls, int pos) {
//     int eliminado = 0;
//     tNodo aux = NULL;

//     if ( *ls != NULL && pos == 0) {
//         aux = *ls;
//         eliminado = aux->valor;
//         *ls = (*ls)->sig;
//         free(aux);
//     } else {
//         eliminado = eliminarEnListaPorPosicion( &((*ls)->sig), pos-1);
//     }

//     return eliminado;
// }

// // ------------------------

// void insertarEnListaPorPosicion(tNodo* ls, int valor, int pos) {
//     tNodo aux = malloc(sizeof(struct sNodo));
//     if ( pos == 0 ) {
//         aux->valor = valor;
//         aux->sig = *ls;
//         *ls = aux;
//     } else {
//         insertarEnListaPorPosicion( &((*ls)->sig), valor, pos-1 );
//     }
// }

// // ------------------------

// void imprimirListaInversaR(tNodo ls) {
//     if (ls !=NULL) {
//         imprimirListaInversaR(ls->sig);
//         printf("%d ", ls->valor);
//     }
// }

// // ------------------------

// int largoLista(tNodo ls) {
//     int res = 0;
//     while (ls!=NULL) {
//         res++;
//         ls = ls->sig;
//     }

//     return res;
// }

// void eliminarLista(tNodo* ls) {
//     if (*ls != NULL) {
//         eliminarLista( &(*ls)->sig );
//         tNodo aux = *ls;
//         *ls = aux->sig;
//         free(aux);
//     }
// }

// int esListaVacio(tNodo ls) {
//     return ls==NULL;
// }

// ################### LISTAS CON ESTRUCTURAS ######################################################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct sContent {
//     char* producto;
//     float precio;
//     int codigo;
// };

// typedef struct sContent tContent;

// struct sContentAux {
//     char producto[50];
//     float precio;
//     int codigo;
// };

// typedef struct sContentAux tContentAux;

// struct sNodo {
//     tContent content;
//     struct sNodo* sig;
// };

// typedef struct sNodo* tNodo;

// void eliminarPorRangoDePrecios(tNodo* ls, float min, float max) {
//     if ( *ls != NULL ) {
//         if ( (*ls)->content.precio > min && (*ls)->content.precio < max ) {
//             tNodo aux = *ls;
//             *ls = (*ls)->sig;
//             free(aux);
//             eliminarPorRangoDePrecios( &(*ls), min, max );
//         } else {
//             eliminarPorRangoDePrecios( &((*ls)->sig), min, max );
//         }
//     }
// }

// void eliminarPorNombre( tNodo* ls, char* producto) {
//     if ( *ls != NULL ) {
//         if ( strcmp( (*ls)->content.producto, producto ) == 0 ) {
//             tNodo aux = *ls;
//             *ls = (*ls)->sig;
//             free(aux);
//             eliminarPorNombre( &(*ls), producto );
//         } else {
//             eliminarPorNombre( &((*ls)->sig), producto );
//         }
//     }
// }

// void eliminarPorCodigo( tNodo* ls, int codigo ) {
//     if (*ls != NULL) {
//         if ( (*ls)->content.codigo == codigo ) {
//             tNodo aux = *ls;
//             *ls = (*ls)->sig;
//             free(aux);
//             eliminarPorCodigo( &(*ls), codigo );
//         } else {
//             eliminarPorCodigo( &((*ls)->sig), codigo );
//         }
//     }
// }

// void cargarPrimero( tNodo* ls, tContentAux content ) {
//     tNodo aux = malloc(sizeof(struct sNodo));
//     aux->content.producto = malloc ( strlen (content.producto) + 1 );

//     aux->sig = (*ls);

//     strcpy(aux->content.producto, content.producto);
//     aux->content.precio = content.precio;
//     aux->content.codigo = content.codigo;

//     (*ls) = aux;

// }

// int criterioDeOrden( tContent lsContent, tContentAux content, int nCampo, int asc ) {
//     int res = 0;

//     if ( nCampo == 0 ) {
//         if (asc == 1) {
//             if ( strcmp(lsContent.producto, content.producto) > 0 ) {
//                 res = 1;
//             }
//         } else {
//             if ( strcmp(lsContent.producto, content.producto) < 0 ) {
//                 res = 1;
//             }
//         }
//     }
//     if ( nCampo == 1 ) {
//         if (asc == 1) {
//             if ( lsContent.precio > content.precio ) {
//                 res = 1;
//             }
//         } else {
//             if ( lsContent.precio < content.precio ) {
//                 res = 1;
//             }
//         }
//     }
//     if ( nCampo == 2 ) {
//         if (asc == 1) {
//             if ( lsContent.codigo > content.codigo ) {
//                 res = 1;
//             }
//         } else {
//             if ( lsContent.codigo < content.codigo ) {
//                 res = 1;
//             }
//         }
//     }

//     return res;
// }

// void cargarOrdenado(tNodo* ls, tContentAux content, int nCampo, int asc) {
//     if (*ls == NULL) {
//         *ls = malloc(sizeof(struct sNodo));
//         (*ls)->content.producto = malloc( strlen(content.producto) + 1 );
//         strcpy( (*ls)->content.producto, content.producto );
//         (*ls)->content.precio = content.precio;
//         (*ls)->content.codigo = content.codigo;
//         (*ls)->sig = NULL;
//     } else {
//         if ( criterioDeOrden((*ls)->content, content, nCampo, asc) ) {
//             tNodo aux = malloc(sizeof(struct sNodo));
//             aux->content.producto = malloc(strlen(content.producto) + 1);

//             aux->sig = (*ls);

//             strcpy(aux->content.producto, content.producto);
//             aux->content.precio = content.precio;
//             aux->content.codigo = content.codigo;

//             (*ls) = aux;
//         } else {
//             cargarOrdenado(&((*ls)->sig), content, nCampo, asc);
//         }
//     }
// }

// void imprimirListaR (tNodo ls) {
//     if (ls != NULL) {
//         printf("%-14s %7.1f %7d\n", ls->content.producto, ls->content.precio, ls->content.codigo);
//         imprimirListaR( ls->sig );
//     }
// }

// void cargarUltimo(tNodo* ls, tContentAux content) {
//     if (*ls == NULL) {
//         *ls = malloc(sizeof(struct sNodo));
//         (*ls)->content.producto = malloc( strlen(content.producto) + 1 );
//         strcpy( (*ls)->content.producto, content.producto );
//         (*ls)->content.precio = content.precio;
//         (*ls)->content.codigo = content.codigo;
//         (*ls)->sig = NULL;
//     } else {
//         cargarUltimo( &((*ls)->sig), content );
//     }
// }

// int cargarArchivoEnLista( tNodo* ls, char* nombreArch ) {
//     FILE* arch;
//     arch = fopen(nombreArch, "r");

//     if (arch == NULL) {
//         printf("error archivo");
//         return -1;
//     }

//     tContentAux content;
//     int r = fscanf(arch, "%[^,], %f, %d\n", content.producto, &content.precio, &content.codigo);
//     while (r!=EOF) {
//         // cargarUltimo(&(*ls), content); 
//         // cargarOrdenado( &(*ls), content, 0 , 0);
//         cargarPrimero( &(*ls), content );
//         r = fscanf(arch, "%[^,], %f, %d\n", content.producto, &content.precio, &content.codigo);
//     } 

//     return 0;
// }

// void busquedaPorCodigo(tNodo* ls, tNodo* resultado, int codigo) {
//     if (*ls != NULL) {
//         if ( (*ls)->content.codigo == codigo ) {

//             tContentAux contentAux;
//             strcpy( contentAux.producto, (*ls)->content.producto);
//             contentAux.precio = (*ls)->content.precio;
//             contentAux.codigo = (*ls)->content.codigo;

//             cargarUltimo( &(*resultado),  contentAux);
//             busquedaPorCodigo( &((*ls)->sig), &(*resultado), codigo );
//         } else {
//             busquedaPorCodigo( &((*ls)->sig), &(*resultado), codigo );
//         }
//     }
// }

// void busquedaPorRangoDePrecios (tNodo* ls, tNodo* resultado, float min, float max) {
//     if ( *ls != NULL ) {
//         if ( (*ls)->content.precio > min && (*ls)->content.precio < max ) {

//             tContentAux contentAux;
//             strcpy( contentAux.producto, (*ls)->content.producto );
//             contentAux.precio = (*ls)->content.precio;
//             contentAux.codigo = (*ls)->content.codigo;

//             cargarUltimo( &(*resultado), contentAux );
//             busquedaPorRangoDePrecios( &((*ls)->sig), &(*resultado), min, max );
//         } else {
//             busquedaPorRangoDePrecios( &((*ls)->sig), &(*resultado), min, max );
//         }
//     }
// }

// int esVocal ( char* txt ) {
//     if (*txt != '\0') {
//         int res = (*txt == 'a' || *txt == 'e' || *txt == 'i' ||
//                     *txt == 'o' || *txt == 'u' || *txt == 'A' ||
//                     *txt == 'E' || *txt == 'I' || *txt == 'O' ||
//                     *txt == 'U');
        
//         return res + esVocal ( txt+1 );
//     }
// }

// void busquedaPorCaracteristica (tNodo* ls, tNodo* resultado, int nVocales) {
//     if ( *ls != NULL ) {
//         if ( esVocal((*ls)->content.producto) == nVocales ) {

//             tContentAux contentAux;
//             strcpy( contentAux.producto, (*ls)->content.producto );
//             contentAux.precio = (*ls)->content.precio;
//             contentAux.codigo = (*ls)->content.codigo;

//             cargarUltimo( &(*resultado), contentAux );
//             busquedaPorCaracteristica( &((*ls)->sig), &(*resultado), nVocales );
//         } else {
//             busquedaPorCaracteristica( &((*ls)->sig), &(*resultado), nVocales );
//         }
//     }
// }

// int main () {
//     tNodo ls = NULL;

//     cargarArchivoEnLista(&ls, "07-repaso-datos.csv");
//     imprimirListaR(ls);

//     // printf("-------------------------\n");

//     // eliminarPorCodigo(&ls, 1024);
//     // imprimirListaR(ls);

//     // printf("-------------------------\n");

//     // eliminarPorNombre(&ls, "Escuadra 45");
//     // imprimirListaR(ls);

//     // printf("-------------------------\n");

//     // eliminarPorRangoDePrecios(&ls, 5, 20);
//     // imprimirListaR(ls);

//     tNodo resultado = NULL;
//     printf("------- Busqueda: -------\n");
//     // busquedaPorCodigo(&ls ,&resultado, 1848);
//     // imprimirListaR(resultado);

//     // busquedaPorRangoDePrecios(&ls, &resultado, 5, 20);
//     // imprimirListaR(resultado);

//     busquedaPorCaracteristica(&ls, &resultado, 2);
//     imprimirListaR(resultado);

//     // printf( "%d", esVocal("hola") );

//     return 0;
// }

// ################### PILAS ######################################################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct sNodo {
//     int valor;
//     struct sNodo* sig;
// };

// typedef struct sNodo* tNodo;

// void push( tNodo* pila, int valor ) {
//     tNodo aux = malloc(sizeof(struct sNodo));
//     aux->sig = (*pila);
//     aux->valor = valor;
//     (*pila) = aux;
// }

// int pop( tNodo* pila ) {
//     int res = 0;

//     tNodo aux = (*pila);
//     res = aux->valor;
//     (*pila) = (*pila)->sig;
//     free(aux);

//     return res;
// }

// int estaVacia(tNodo* pila) {
//     return *pila == NULL;
// }

// // void imprimirPilaR (tNodo pila) {
// //     if (pila!=NULL) {
// //         printf("%d ", pila->valor);
// //         imprimirPilaR( pila->sig );
// //     }
// // }

// void impresionConPop(tNodo* pila) {
//     while ( ! estaVacia( &(*pila) ) ) {
//         printf("%d ", pop( &(*pila) ) );
//     }
// }

// void busquedaPorRango(tNodo* pila, tNodo* resultado, int min, int max) {
//     int extraido;
//     tNodo pilaAux = NULL;

//     while ( ! estaVacia( &(*pila) ) ) {
//         extraido = pop( &(*pila) );

//         if ( extraido > min && extraido < max ) {
//             push(&(*resultado), extraido);
//         } else {
//             push(&pilaAux, extraido);
//         }
//     }

//     while( ! estaVacia( &pilaAux ) ) {
//         push( &(*pila), pop( &pilaAux ) );
//     }
// }

// int main () {
//     tNodo pila = NULL;

//     push(&pila, 10);
//     push(&pila, 140);
//     push(&pila, 18);
//     push(&pila, 3);

//     // imprimirPilaR(pila);

//     tNodo resultado = NULL;
//     busquedaPorRango(&pila, &resultado, 5, 20);
//     impresionConPop(&resultado);

//     printf("\n-------------------------\n");

//     impresionConPop(&pila);

//     return 0;
// }

// ################### COLAS ######################################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNodo {
    int valor;
    struct sNodo* sig;
};

typedef struct sNodo* tNodo;

struct sQueue {
    tNodo head;
    tNodo tail;
};

typedef struct sQueue tQueue;

void queue(tQueue* cola, int valor) {
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

int dequeue( tQueue* cola ) {
    int res;

    tNodo aux = cola->head;
    cola->head = cola->head->sig;
    res = aux->valor;
    free(aux);

    if (cola->head == NULL) {
        cola->tail == NULL;
    }

    return res;
}

int estaVacio ( tQueue* cola ) {
    return cola->head == NULL && cola->tail == NULL ;
}

void imprimirPorDequeue( tQueue* cola ) {
    while ( &(*cola) != NULL ) {
        printf("%d ", dequeue( &(*cola) ) );
    }
}

int main() {
    tQueue cola = {NULL,NULL};

    queue(&cola, 6);
    queue(&cola, 3);
    queue(&cola, 26);
    queue(&cola, 23);

    imprimirPorDequeue(&cola);

    return 0;
}
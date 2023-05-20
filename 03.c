// ############################# EJ 01 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// void intercambio(int *a, int *b) {
//     int temp = *a;
//     *a = 10;
//     *b = 20;
// }

// int main() {
//     int a = 1;
//     int b = 2;
//     printf("%d, %d\n", a, b);
//     intercambio(&a,&b);
//     printf("%d, %d", a, b);

//     return 0;
// }

// ############################# CLASE 08-05 #######################################################################################

// #include <string.h>

// char* dameMem(int tam){
//     char* res = malloc(tam);
//     return res;
// }

// void dameMem2(char** pptxt, int tam){ //al char ya tener * esta tiene que tener * del *
//     *pptxt = malloc(tam);
// }

// int main() {
//     char* txt=NULL;
//     // txt=dameMem(10);
//     dameMem2(&txt,10);
//     strcpy(txt,"hola");
//     printf("%s\n",txt);
//     return 0;
// }

// ############################# EJ 02 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// int* nMem(int *arrI, int num) {
//     return &arrI[num];
// }

// int main() {
//     int arrI[10] = {0,1,2,3,4};

//     printf("%p\n", nMem(arrI, 1));
//     printf("%p\n", arrI+1);

//     return 0;
// }

// ############################# EJ 03 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// int* nMem(int *arrI, int num) {
//     return &arrI[num];
// }

// int main() {
//     int arrI[10] = {0,1,2,3,4};

//     printf("%p\n", nMem(arrI, 1));
//     printf("%p\n", arrI+1);

//     return 0;
// }

// ############################# EJ 07 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// // void cargarStrDin(char txt[10]) {
// //     char c;
// //     int i = 0;
// //     while(((c = getchar())!='\n')){
// //         txt[i] = c;
// //         i++;
// //     } txt[i] = '\n';
// // }

// char* cargarStrDin() {
//     char c;
//     int i = 0;
//     char* txt = NULL;

//     txt = (char*) malloc(sizeof(char));
//     if (txt!=NULL) {
//         while(((c = getchar())!='\n') && txt != NULL){
//             txt[i] = c;
//             i++;
//             txt=(char *) realloc(txt,(i+1)*sizeof(char)); /** Ampliar memoria*/
//         } txt[i] = '\n';            
//     }

//     return txt;
// }

// int main() {
//     char* txt = NULL;
//     // char txt[10];
//     // cargarStrDin(txt);
//     txt = cargarStrDin();
//     printf("%s", txt);
//     return 0;
// }

// ############################# EJ EJEMPLO #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct s_punto {
//     int x, y;
//     char* nom;
// };

// typedef struct s_punto t_punto;

// int main() {
//     t_punto* arrP = NULL;
//     arrP = malloc(sizeof(struct s_punto));
//     (*(arrP+0)).x = 10;
//     (*(arrP+0)).y = 20;
//     (*(arrP+0)).nom = malloc(sizeof(char)*10);
//     strcpy((*(arrP+0)).nom, "juancito");
//     printf("%d, %d, %s\n", (*(arrP+0)).x, (*(arrP+0)).y, (*(arrP+0)).nom);
//     printf("%s\n", (*(arrP+0)).nom);
//     printf("%s\n", (arrP+0)->nom);
//     printf("%c\n", (arrP+0)->nom[0]);

//     return 0;
// }


// ########## A ############

#include <stdio.h>
#include <stdlib.h>

struct s_nodo {
    int val;
    struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;

void append(t_nodo* nodo,int val){// agregar a lo ultimo
    if (*nodo == NULL){
        // crear el nodo
        *nodo =  malloc(sizeof(struct s_nodo));
        (*nodo)->val=val;           // cargar el contenido
        (*nodo)->sig=NULL;          //colocar null al puntero
    }    
    else{
        append( &((*nodo)->sig), val);
    }
        
}

void imprimirListaR(t_nodo ls){
    // Imprimir Recursivo
    if(ls!=NULL){
        printf("\n valor=%4d, dirNodo:<%p>, dirSig:<%p>",(ls)->val,ls,ls->sig);
        imprimirListaR(ls->sig);
    }
}

int main() {
    t_nodo ls = NULL;
    append(&ls, 10);
    append(&ls, 20);
    append(&ls, 30);
    imprimirListaR(ls);
    return 0;
}
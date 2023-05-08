// ############################# EJ 01 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// void intercambio(int* a, int* b) {
//     a = 10;
//     b = 20;
// }

// int main() {
//     int a = 1;
//     int b = 2;
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_punto {
    int x, y;
    char* nom;
};

typedef struct s_punto t_punto;

int main() {
    t_punto* arrP = NULL;
    arrP = malloc(sizeof(struct s_punto));
    (*(arrP+0)).x = 10;
    (*(arrP+0)).y = 20;
    (*(arrP+0)).nom = malloc(sizeof(char)*10);
    strcpy((*(arrP+0)).nom, "juancito");
    printf("%d, %d, %s\n", (*(arrP+0)).x, (*(arrP+0)).y, (*(arrP+0)).nom);
    printf("%s\n", (*(arrP+0)).nom);
    printf("%s\n", (arrP+0)->nom);
    printf("%c\n", (arrP+0)->nom[0]);

    return 0;
}



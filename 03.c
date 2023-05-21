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

// void redondeo(double *num) {
//     printf("%.0f\n", *num);
// }

// int main() {
//     double num = 3.7;

//     printf("%f\n", num);
//     redondeo(&num);

//     return 0;
// }

// ############################# EJ 03 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// struct s_carta {
// int numero, valor;
// char palo;
// };

// typedef struct s_carta t_carta;
// void asignarValor(t_carta *c) {
//     switch (c->numero) {
//         case 1: // Ases
//             if (c->palo == 'E') { // As de espadas
//                 c->valor = 14;
//             } else if (c->palo == 'B') { // As de bastos
//                 c->valor = 13;
//             } else { // Ases falsos
//                 c->valor = 8;
//             }
//             break;
//         case 7: // Sietes
//             if (c->palo == 'E') { // Siete de espadas
//                 c->valor = 12;
//             } else if (c->palo == 'O') { // Siete de oros
//                 c->valor = 11;
//             } else { // Sietes falsos
//                 c->valor = 4;
//             }
//             break;
//         case 3: // Treses
//             c->valor = 10;
//             break;
//         case 2: // Doses
//             c->valor = 9;
//             break;
//         case 12: // Reyes
//             c->valor = 7;
//             break;
//         case 11: // Caballos
//             c->valor = 6;
//             break;
//         case 10: // Sotas
//             c->valor = 5;
//             break;
//         case 6: // Seises
//             c->valor = 3;
//             break;
//         case 5: // Cincos
//             c->valor = 2;
//             break;
//         case 4: // Cuatros
//             c->valor = 1;
//             break;
//         default:
//             printf("Error: carta inválida\n");
//             exit(1);
//     }
// }

// void imprimir(t_carta c) {
//     printf("%d%c\n", c.numero, c.palo);
// }

// void imprimir3(t_carta c1, t_carta c2, t_carta c3) {
//     imprimir(c1);
//     imprimir(c2);
//     imprimir(c3);
//     printf("\n");
// }

// void swap(t_carta *a, t_carta *b) {
//     t_carta temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void ordenar(t_carta *c1, t_carta *c2, t_carta *c3) {
//     if (c1->valor < c2->valor) {
//         swap(c1, c2);
//     } 
//     if (c2->valor < c3->valor) {
//         swap(c2, c3);
//     }
//     if (c1->valor < c2->valor) {
//         swap(c1, c2);
//     } 
// }

// int main() {
//     t_carta carta1, carta2, carta3;

//     carta1.numero = 7;
//     carta1.palo = 'O';

//     carta2.numero = 4;
//     carta2.palo = 'C';

//     carta3.numero = 11;
//     carta3.palo = 'B';

//     asignarValor(&carta1);
//     asignarValor(&carta2);
//     asignarValor(&carta2);

//     imprimir3(carta1, carta2, carta3);

//     ordenar(&carta1, &carta2, &carta3);

//     imprimir3(carta1, carta2, carta3);

//     return 0;
// }

// ############################# EJ 05 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int a, b, c;
// } t_tres;

// void imprimir(t_tres *arr) {
//     printf("%d, %d, %d\n", arr->a, arr->b, arr->c);
// }

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void ordenar(t_tres *arr) {
//     if (arr->a > arr->b) {
//         swap(&arr->a,&arr->b);
//     }
//     if (arr->b > arr->c) {
//         swap(&arr->b,&arr->c);
//     }
//     if (arr->a > arr->b) {
//         swap(&arr->a,&arr->b);
//     }
// }

// int main() {
//     t_tres arr1 = {2, 3, 1};

//     imprimir(&arr1);
//     ordenar(&arr1);
//     imprimir(&arr1);

//     return 0;
// }

// ############################# EJ 06 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int n, o , p;
//     char p1[26], p2[50];
//     double a, b, c;
// } t_varios;

// void imprimir(t_varios *var) {
//     printf("var: %d %d %d %s %s %.2f %.2f %.2f\n", var->n, var->o, var->p, var->p1, var->p2, var->a, var->b, var->c);
// }

// void intercambiar(t_varios *var1, t_varios *var2) {
//     t_varios temp = *var1;
//     *var1 = *var2;
//     *var2 = temp;
// }

// int main() {
//     t_varios var1 = {1, 2, 3, "Hola", "Mundo", 1.23, 4.56, 7.89};
//     t_varios var2 = {4, 5, 6, "Adios", "Bing", 9.87, 6.54, 3.21};

//     imprimir(&var1);
//     imprimir(&var2);

//     intercambiar(&var1, &var2);

//     printf("------------------------------------\n");

//     imprimir(&var1);
//     imprimir(&var2);
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

// ############################# EJ 08 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// char* cargarStrDin1() {
//     char c;
//     int i = 0;
//     char* txt = NULL;
//     txt = (char*) malloc(sizeof(char));

//     if (txt!=NULL) {
//         while( ((c=getchar())!='\n') && txt != NULL ) {
//             txt[i] = c;
//             i++;
//             txt = (char*) realloc(txt, (i+1)*sizeof(char));
//         } txt[i] = '\0';
//     }

//     return txt;
// }

// void cargarStrDin2 (char** pTxt) {
//     char c;
//     int i = 0;
//     *pTxt = (char*) malloc(sizeof(char));
//     // (*pTxt)[i] = 'a';
//     // (*pTxt)[i+1] = '\0';
//     if (*pTxt != NULL) {
//         while ( ( (c=getchar())!='\n' ) && *pTxt!=NULL ) {
//             (*pTxt)[i] = c;
//             i++;
//             *pTxt = (char*) realloc (*pTxt, (i+1)*sizeof(char));
//         } (*pTxt)[i] = '\0';
//     }
// }

// void escribirArch(char * nomArch, char * txt) {
//     FILE* arch;
//     arch = fopen(nomArch, "w");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//     }

//     fprintf(arch, "%s\n", txt);
//     fclose(arch);
// }

// void imprimirArch(char * nomArch) {
//     FILE* arch;
//     arch = fopen(nomArch, "r");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//     }

//     char c;
//     while((c = fgetc(arch)) != EOF) {
//         printf("%c", c);
//     }

//     fclose(arch);
// }

// int main() {
//     char* str = NULL;
//     // str = cargarStrDin1();
//     cargarStrDin2(&str);
//     escribirArch("03-08-frase.txt", str);
//     imprimirArch("03-08-frase.txt");
//     // printf("%s\n", str);
//     free(str);
// }

// ############################# EJ 09 #######################################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* leerArch(char * nomArch) {
    FILE* arch;
    arch = fopen(nomArch, "r");

    if (arch == NULL){
        printf("Error al abrir el archivo");
    }

    char* str = NULL;
    str = (char*) malloc(sizeof(char));

    char c;
    int i = 0;
    while ( (c=fgetc(arch)) != EOF ) {
        str[i] = c;
        i++;
        str = (char*) realloc(str, (i+1)*sizeof(char));
    }

    return str;
}

char* subcadena (char* str, int i, int n) {
    // printf("%s", *str);
    char* subStr = NULL;
    subStr = malloc(sizeof(char));

    int x = 0;
    int count = 0;
    int countrev = -n;
    int rev = 0;
    
    if (n<0) {
        subStr = realloc(subStr, (countrev+1)*sizeof(char));
    } else if (n==0) {
        subStr[0] = '\0';
    }

    while (x<strlen(str)) {
        // printf("%c", str[x]);
        if (n<0) {
            if ( x >= (i-countrev) && countrev > 0) {
                // printf("%c", str[x]);
                subStr[rev] = str[x];
                rev++;
                countrev--;    
            } subStr[rev] = '\0';  
        } else if (n>0) {
            if (x >= i && count < n) {
            subStr = realloc(subStr, (count+1)*sizeof(char));
            // printf("%c", str[x]);
            subStr[count] = str[x];
            count++;
            } subStr[count] = '\0';    
        }
        x++;
    }

    return subStr;
}

int main() {
    char* str = NULL;
    char* subStr = NULL;
    int i = 8, n = 5;
    str = leerArch("03-08-frase.txt");
    subStr = subcadena (str, 8, 5);
    // SI COLOCAS UN NUMERO MENOR A i SE ROMPE
    printf("%s", subStr);
}

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


// ############################# CLASE 1-05 #######################################################################################

// #include <stdio.h>
// #include <stdlib.h>

// struct s_nodo {
//     int val;
//     struct s_nodo* sig;
// };

// typedef struct s_nodo* t_nodo;

// void append(t_nodo* nodo,int val){// agregar a lo ultimo
//     if (*nodo == NULL){
//         // crear el nodo
//         *nodo =  malloc(sizeof(struct s_nodo));
//         (*nodo)->val=val;           // cargar el contenido
//         (*nodo)->sig=NULL;          //colocar null al puntero
//     }    
//     else{
//         append( &((*nodo)->sig), val);
//     }
        
// }

// void imprimirListaR(t_nodo ls){
//     // Imprimir Recursivo
//     if(ls!=NULL){
//         printf("\n valor=%4d, dirNodo:<%p>, dirSig:<%p>",(ls)->val,ls,ls->sig);
//         imprimirListaR(ls->sig);
//     }
// }

// int main() {
//     t_nodo ls = NULL;
//     append(&ls, 10);
//     append(&ls, 20);
//     append(&ls, 30);
//     imprimirListaR(ls);
//     return 0;
// }

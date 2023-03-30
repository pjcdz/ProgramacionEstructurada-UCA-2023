#include <stdio.h>
#include <math.h>

// ############################# EJ 01 #######################################################################################

// int main() {
//     float num;
//     printf("Ingrese un numero real: "); 
//     scanf("%f", &num);

//     printf("Piso: %.0f\n", floor(num));
//     printf("Techo: %.0f\n", ceil(num));
//     printf("Redondeo: %.0f\n", num);

//     return 0;
// }

// TEST CON 8.6 PREGUNTAR POR EL PISO = 9

// ############################# EJ 02 #######################################################################################

// int suma(int num1, int num2) {
// 	return num1 + num2;
// }

// int resta(int num1, int num2) {
// 	return num1 - num2;
// }

// int multiplicacion(int num1, int num2) {
// 	return num1 * num2;
// }

// int division(int num1, int num2) {
// 	return num1 / num2;
// }

// int main() {
// 	int num1;
// 	int num2;
	
// 	printf("Ingrese primer numero: ");
// 	scanf("%d", &num1);
// 	printf("Ingrese segundo numero: ");
// 	scanf("%d", &num2);
	
// 	char op;
	
// 	printf("Ingrese operador [+ - * /]: ");
// 	scanf(" %c", &op);
	
// 	switch (op) {
// 	case '+': 
// 		printf("\n%d %c %d = %d", num1, op, num2, suma(num1, num2));
// 		break;
// 	case '-':
// 		printf("\n%d %c %d = %d", num1, op, num2, resta(num1, num2));
// 		break;
// 	case '*':
// 		printf("\n%d %c %d = %d", num1, op, num2, multiplicacion(num1, num2));
// 		break;
// 	case '/':
// 		printf("\n%d %c %d = %d", num1, op, num2, division(num1, num2));
// 		break;
// 	default:
// 		printf("Operador invalido\n");
// 		break;
// 	}
	
// 	return 0;
// }

// ############################# EJ 03 #######################################################################################


// char *leer() {
// 	char *texto = (char *) malloc(100); // Reservar memoria dinámica para el string
// 	printf("Ingrese texto: ");
// 	scanf("%s", texto);
	
// 	return texto;
// }

// int main() {
// 	char *temp = leer();
// 	char remplazar;
// 	printf("Ingrese caracter a remplazar: ");
// 	scanf(" %c", &remplazar);
	
// 	char reemplazo;
// 	printf("Ingrese caracter de reemplazo: ");
// 	scanf(" %c", &reemplazo);
	
// 	printf("%s", temp);
	
// 	free(temp); // Liberar memoria reservada
// 	return 0;
// }


// void leer(char texto[]) {
// 	printf("Ingrese texto: ");
// 	scanf("%s", texto);
// }

// void reemplazar(char texto[], char reemplazar, char reemplazo) {
// 	for (int i = 0; i < 100; i++) {
// 		if (texto[i] == reemplazar) {
// 			texto[i] = reemplazo;
// 		}
// 	}
// }

// int main() {
// 	char texto[100];
// 	leer(texto);
	
// 	char remplazar;
// 	printf("Ingrese caracter a remplazar: ");
// 	scanf(" %c", &remplazar);
	
// 	char reemplazo;
// 	printf("Ingrese caracter de reemplazo: ");
// 	scanf(" %c", &reemplazo);
	
// 	reemplazar(texto, remplazar, reemplazo);
	
// 	printf("Resultado: %s", texto);
	
// 	return 0;
// }

// ############################# EJ 04 #######################################################################################

// void cargaArr(int numeros[10]) {
//     int i = 0;
    
//     do {
//         printf("Ingresa un numero: ");    
//         scanf("%d", &numeros[i]);
//         i++;
//     } while (numeros[i-1] != 0 && i < 10);
// }

// void imprimirArr(int numeros[], int len) {
//     printf("El array ingresado es: [");
//     for (int j = 0; numeros[j] != 0 && j < len + 1; j++) {
// 		if (numeros[j+1] == 0 || j == 9) {
// 			printf("%d", numeros[j]);
// 		} else {
// 			printf("%d, ", numeros[j]);
// 		}
//     }
// 	printf("]\n");
// }

// void invertirArr(int numeros[], int len) {
//     int x = 0;
//     int y = (len-1);
//     while (x < (len-1)/2) {
//         int temp = numeros[x];
//         numeros[x] = numeros[y];
//         numeros[y] = temp;
//         x++;
//         y--;
//     }
// }

// int main() {
//     int numeros[10];
//     cargaArr(numeros);
//     // int numeros[10] = {5, 1, 3, 2, 4};

//     int len = 0;
//     for(int u = 0; numeros[u] != 0 && u < 10 ; u++) {
//         len++;
//     }    

//     // printf("\nEl numero de elementos en la array es: %d\n", len);

//     // printf("\n%d, %d", (len-1), numeros[len-1]);
//     // printf("\n%d, %d\n", (len-1)/2, numeros[(len-1)/2]);

//     invertirArr(numeros, len);

//     imprimirArr(numeros, len);

//     int numeros1[10];
//     cargaArr(numeros1);

//     int len1 = 0;
//     for(int j = 0; numeros1[j] != 0 && j < 10 ; j++) {
//         len1++;
//     }    

//     for(int x = 0; numeros1[x] != 0 && x < len1-1; x++) {
//         for(int y = x + 1; numeros1[y] != 0 && y < len1; y++) {
//             // printf("%d y %d\n", numeros[x], numeros[y]);
//             if(numeros1[x] > numeros1[y]) {
//                 int temp = numeros1[x];
//                 numeros1[x] = numeros1[y];
//                 numeros1[y] = temp;
//             }
//         }
//     }

//     imprimirArr(numeros1, len1);

//     return 0;
// }

// ############################# EJ 05 #######################################################################################

// void imprimirArr(int numeros[100]) {
//     printf("El array ingresado es: [");
//     for (int j = 0; numeros[j] != 0 && j < 100 + 1; j++) {
// 		if (numeros[j+1] == 0 || j == 99) {
// 			printf("%d", numeros[j]);
// 		} else {
// 			printf("%d, ", numeros[j]);
// 		}
//     }
// 	printf("]\n");
// }

// int estaEnArr(int numerostemp[100], int i) {
//     int rt = 0;

//     for(int u = 0; u < i; u++) { // Solo revisar hasta el último número ingresado
//         if (numerostemp[u] == numerostemp[i]) {
//             rt = 1;
//         }
//     }

//     return rt;
// }

// int esPos(int numerostemp[100], int i) {
//     int rt = 1;

//     if (numerostemp[i] < 0) {
//             rt = 0;
//     }

//     return rt;
// }

// void cargarArrPNR(int numeros[100], int numerostemp[100]) {
//     int i = 0;
//     int j = 0;
//     do {
//         printf("Ingrese un numero: ");
//         scanf("%d", &numerostemp[i]);

//         // imprimirArr(numerostemp);    
//         // printf("\nEl numero fue: %d, esta en arr? %d, es positivo? %d\n", numerostemp[i], estaEnArr(numerostemp, i), esPos(numerostemp, i));
//         if (estaEnArr(numerostemp, i) == 0 && esPos(numerostemp, i) == 1) {
//             numeros[j] = numerostemp[i];
//             // printf("yeiii\n");
//             j++;
//         }

//         i++;
//     } while(numerostemp[i-1] != 0 && i < 100);

//     // int numerostemp[10] = {1, -1, -1};
//     // printf("%d", esPos(numerostemp, 1));
// }

// int main() {
//     int numeros[100] = {0};
//     int numerostemp[100] = {0};

//     cargarArrPNR(numeros, numerostemp);

//     // imprimirArr(numerostemp);
//     imprimirArr(numeros);

//     return 0;
// }

// ############################# EJ 06 #######################################################################################

// void cargarTexto(char texto[100]) {
//     printf("Ingrese un texto: ");
    
//     int i = 0;
//     char aux;
//     if (i<100-1) {
//         aux = getchar();
//     }
//     while (aux!='\n' && i<100-1) {
//         texto[i] = aux;
//         i++;
//         if(i<100-1) {
//             aux = getchar();
//         }
//     }
//     texto[i] = '\0';
    
// }

// void imprimirTexto(char texto[100]) {
//     printf("El texto ingresado es: ");
//     for(int x = 0; texto[x] != '\0'; x++) {
//         printf("%c", texto[x]);
//     }
// }

// void normalizar(char texto[100], char normal[100]) {
//     if (texto[0] >= 'a' && texto[0] <= 'z') {
//         texto[0] = texto[0] - 32;
//     }

//     int y = 0;
//     for(int x = 0; texto[x] != '\0'; x++) {
//         if (texto[x] != ' ') {
//             normal[y] = texto[x];
//             y++;
//         } else if (texto[x-1] != ' ' && texto[x] == ' ') {
//             normal[y] = ' ';
//             y++;
//         }
        
//         if (texto[x+1] == '\0') {
//             // printf("\n%c\n", normal[y-2]);
//             normal[y] = '.';
//         }
//     }
// }


// int main() {
//     char texto[100];
//     char normal[100] = " ";

//     cargarTexto(texto);
//     imprimirTexto(texto);

//     normalizar(texto, normal);

//     imprimirTexto(normal);

//     return 0;
// }

// ############################# EJ 07 #######################################################################################

// #define F 3
// #define C 3

// void cargarMat(int mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             int num;
//             printf("Ingrese un numero en la posicion [%d][%d]: ", f, c);
//             scanf("%d", &num);
//             mat[f][c] = num;
//         }
//     }
// }

// void imprimirMat(int mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             printf("%4d", mat[f][c]);
//         }
//         printf("\n");
//     }
// }

// float promMat(int mat[F][C]) {
//     int f = 0, c = 0;
//     float prom = 0;
//     int cant = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             prom += mat[f][c];
//             cant++;
//         }
//     }

//     prom = prom / cant;
//     return prom;
// }

// int main() {
//     int mat[F][C] = {0};
//     cargarMat(mat);
//     printf("\n");
//     imprimirMat(mat);
//     printf("\n");
//     printf("El promedio de los valores de la matriz es de: %.2f",promMat(mat));

//     return 0;
// }

// ############################# EJ 08 #######################################################################################

// #define F 3
// #define C 3

// void cargarMat(int mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             int num;
//             printf("Ingrese un numero en la posicion [%d][%d]: ", f, c);
//             scanf("%d", &num);
//             mat[f][c] = num;
//         }
//     }
// }

// void imprimirMat(int mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             printf("%4d", mat[f][c]);
//         }
//         printf("\n");
//     }
// }

// void transponerMat(int mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=f; c<C; c++) {        
//             // printf("[%2d, %2d]", mat[f][c], mat[c][f]);
//             int aux = mat[f][c];
//             mat[f][c] = mat[c][f];
//             mat[c][f] = aux;
//         }
//         // printf("\n");
//     }
// }

// int main() {
//     int mat[F][C] = {0};
//     cargarMat(mat);
//     printf("\n");
//     imprimirMat(mat);
//     printf("\n");
//     transponerMat(mat);
//     imprimirMat(mat);

//     return 0;
// }

// ############################# EJ 09 #######################################################################################

// #include <string.h>
// #define F 3
// #define C 20

// void cargarMatText(char mat[F][C]) {
//     int f = 0, c = 0;

//     for (f=0; f<F; f++) {
//         char aux;
//         printf("Ingrese un texto: ");
//         if (c < C-1) {
//             aux = getchar();
//         }
//         while(aux != '\n' && c < C-1) {
//             mat[f][c] = aux;
//             c++;
//             if (c < C-1) {
//                 aux = getchar();
//             }
//         }
//         mat[f][c] = '\0';
//     }
// }

// void imprimirMatText(char mat[F][C]) {
//     int u = 0, i = 0;

//     for(u = 0; u < F; u++) {
//         for(i = 0; i < C; i++) {
//             printf("%c", mat[u][i]);
//         }
//         printf("\n");
//     }
// }

// void ordenarMatText(char mat[F][C]) {
//     int f = 0, i = 0;

//     for(f=0; f<F; f++) {
//         for(i=f; i<F; i++) {
//             // char aux1 = mat[f][0];
//             // char aux2 = mat[i][0];
//             // if(mat[f][0] >= 'a' && mat[f][0] <= 'z') {
//             //     aux1 = mat[F][0] + 32;
//             // }
//             // if(mat[i][0] >= 'a' && mat[i][0] <= 'z') {
//             //     aux2 = mat[F][0] + 32;
//             // }
//             // printf("%c, %c\n", mat[f][0], mat[i][0]);
//             // printf("%c, %c\n", aux1, aux2);
//             if (mat[f][0] > mat[i][0]) {
//                 char tmp[C];
//                 strcpy(tmp, mat[f]);
//                 strcpy(mat[f], mat[i]);
//                 strcpy(mat[i], tmp);
//             }
//         }
//     }
// }

// int main() {
//     char matText[F][C] = {{'m', 'u', 'n', 'd', 'o', '\0'}, {'h', 'o', 'l', 'a', '\0'}, {'c', 'o', 'm', 'o', '\0'}};
//     // cargarMatText(matText);
//     imprimirMatText(matText);
//     ordenarMatText(matText);
//     imprimirMatText(matText);

//     return 0;
// }

// ############################# EJ 10 #######################################################################################

// #define F 5
// #define C 15

// void cargarMatTexDeArch(char mat[F][C]) {
//     int f = 0, c = 0;
//     int car = 0;

//     FILE * arch;
//     arch = fopen("01-10.txt", "r");

//     if (arch != NULL) {
//         while ((car = fgetc(arch)) != EOF) {
//             if (car != '\n') {
//                 mat[f][c] = car;
//                 c++;
//             } else {
//                 mat[f][c] = '\0';
//                 f++;
//                 c = 0;
//             }
//         }
//         fclose(arch);
//     } else {
//         printf("No se pudo abrir el archivo");
//     }
// }

// void imprimirMat(char mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             printf("%c", mat[f][c]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     char mat[F][C] = {0};
//     cargarMatTexDeArch(mat);
//     imprimirMat(mat);
//     return 0;
// }

// ############################# EJ 11 #######################################################################################

// #include <string.h>
// #define F 5
// #define C 15

// void cargarMatTexDeArch(char mat[F][C]) {
//     int f = 0, c = 0;
//     int car = 0;

//     FILE * arch;
//     arch = fopen("01-10.txt", "r");

//     if (arch != NULL) {
//         while ((car = fgetc(arch)) != EOF) {
//             if (car != '\n') {
//                 mat[f][c] = car;
//                 c++;
//             } else {
//                 mat[f][c] = '\0';
//                 f++;
//                 c = 0;
//             }
//         }
//         fclose(arch);
//     } else {
//         printf("No se pudo abrir el archivo");
//     }
// }

// void imprimirMat(char mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             printf("%c", mat[f][c]);
//         }
//         printf("\n");
//     }
// }

// void ordenarTexto(char mat[F][C]) {
//     int f = 0, i = 0;
//     for (f = 0; f < F; f++) {
//         for (i = f + 1; i < F; i++) {
//             if (strcmp(mat[f], mat[i]) > 0) {
//                 char tmp[C];
//                 strcpy(tmp, mat[f]);
//                 strcpy(mat[f], mat[i]);
//                 strcpy(mat[i], tmp);
//             }
//         }
//     }
// }

// int main() {
//     char mat[F][C] = {0};
//     cargarMatTexDeArch(mat);
//     imprimirMat(mat);
//     printf("\n");
//     ordenarTexto(mat);
//     imprimirMat(mat);

//     return 0;
// }

// ############################# EJ 12 #######################################################################################

// #define F 5
// #define C 8

// int cargaMatInt(int mat[F][C]) {
//     int pts, pj, pg, pe, pp, gf, gc, dif;
//     int r;

//     FILE* arch;
//     arch = fopen("01-11.txt", "r");

//     if(arch==NULL) {
//         return -1;
//     }
//     int f = 0;
//     r = fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &pts, &pj, &pg, &pe, &pp, &gf, &gc, &dif);
//     while(r != EOF) {
//         int lst[8] = {pts, pj, pg, pe, pp, gf, gc, dif};
//         int i = 0;
//         int c = 0;
//         while(i<8) {
//             // printf("%-5d", lst[i]);
//             mat[f][c] = lst[i];
//             // printf("[%-2d, %d;%d]", mat[f][c], f, c);
//             c++;
//             i++;
//         }
//         // printf("\n");
//         // printf("%d;%d", f, c);
//         // printf("\n");
//         f++;

//         r = fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &pts, &pj, &pg, &pe, &pp, &gf, &gc, &dif);
//     }

//     fclose(arch);

//     return 0;
// }

// void imprimirMatInt(int mat[F][C]) {
//     int f = 0, c = 0;

//     for(f=0; f<F; f++) {
//         for(c=0; c<C; c++) {
//             printf("%-5d", mat[f][c]);
//         }
//         printf("\n");
//     }
// }

// int cargaMatCab(char mat[F][C])

// int main() {
//     int mat[F][C] = {0};
//     cargaMatInt(mat);
//     imprimirMatInt(mat);
    
//     return 0;
// }


// ############################# EJ 13 #######################################################################################

#include <string.h>
#define F 9
#define C 40

int cargaMatInt(int mat[F][C]) {
    int pts, pj, pg, pe, pp, gf, gc, dif;
    int r;

    FILE* arch;
    arch = fopen("01-11.txt", "r");

    if(arch==NULL) {
        return -1;
    }
    int f = 0;
    r = fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &pts, &pj, &pg, &pe, &pp, &gf, &gc, &dif);
    while(r != EOF) {
        int lst[8] = {pts, pj, pg, pe, pp, gf, gc, dif};
        int i = 0;
        int c = 0;
        while(i<8) {
            // printf("%-5d", lst[i]);
            mat[f][c] = lst[i];
            // printf("[%-2d, %d;%d]", mat[f][c], f, c);
            c++;
            i++;
        }
        // printf("\n");
        // printf("%d;%d", f, c);
        // printf("\n");
        f++;

        r = fscanf(arch, "%d, %d, %d, %d, %d, %d, %d, %d\n", &pts, &pj, &pg, &pe, &pp, &gf, &gc, &dif);
    }

    fclose(arch);

    return 0;
}

void imprimirMatInt(int mat[F][C]) {
    int f = 0, c = 0;

    for(f=0; f<5; f++) {
        for(c=0; c<8; c++) {
            printf("%-5d", mat[f][c]);
        }
        printf("\n");
    }
}

int cargaMatCar(char archivo[30], char mat[F][C]) {
    FILE* arch;
    arch = fopen(archivo, "r");

    if(arch==NULL) {
        return -1;
    }

    int f = 0, c = 0;
    char car;

    while ((car = fgetc(arch)) != EOF) {
        if (car != '\n') {
            mat[f][c] = car;
            c++;
        } else {
            mat[f][c] = '\0';
            f++;
            c = 0;
        }
    }
    fclose(arch);


    return 0;
}

void imprimirMatCabecera(char mat[F][C]) {
    int f = 0, c = 0;

    for(f=0; f<F; f++) {
        if (f == 0) {
            printf("%-15s", mat[f]);
        } else { 
            printf("%-5s", mat[f]);
        }
    }
    printf("\n-----------------------------------------------------\n");
}

void imprimirMatItems(char mat[F][C]) {
    int f = 0, c = 0;

    for(f=0; f<F &&  mat[f][c] != '\0'; f++) {
        printf("%-15s", mat[f]);
        printf("\n");
    }
}

void ordenarTabla(int matInt[F][C], char matItems[F][C], int colum, int orden) {
    int f = 0, c = 0;

    for(f=0; f<5; f++) {
        for(int g = f+1; g<5; g++) {
            if (orden==0) {
                // printf("%d:%d \n", matInt[f][colum], matInt[f+1][colum]);
                if (matInt[f][colum] > matInt[g][colum]) {
                    int aux[C] = {0};
                    for(int u = 0; u<8; u++) {
                        aux[u] = matInt[f][u];
                    }
                    for(int i = 0; i<8; i++) {
                        matInt[f][i] = matInt[g][i];
                    }
                    for(int o = 0; o<8; o++) {
                        matInt[g][o] = aux[o];
                    }

                    char aux2[C] = {0};
                    strcpy(aux2, matItems[f]);
                    strcpy(matItems[f], matItems[g]);
                    strcpy(matItems[g], aux2);
                }
            }
        }
    }
}

void imprimirTabla(int matInt[F][C], char matItems[F][C], char matCabecera[F][C]) {
    int f = 0, c = 0;

    for(f=0; f<F; f++) {
        if (f == 0) {
            printf("%-15s", matCabecera[f]);
        } else { 
            printf("%-5s", matCabecera[f]);
        }
    }
    printf("\n-----------------------------------------------------\n");
    
    f = 0;
    c = 0;

    for(f=0; f<5; f++) {
        printf("%-15s", matItems[f]);
        for(c=0; c<8; c++) {
            printf("%-5d", matInt[f][c]);
        }
        printf("\n");
    }
}

int main() {
    int matInt[F][C] = {0};
    char matCabecera[F][C] = {0};
    char matItems[F][C] = {0};
    // char merge[F][C] = {0};

    cargaMatInt(matInt);
    // imprimirMatInt(matInt);
    char archivoCabeceras[30] = "01-13-cabeceras.txt";
    char archivoItems[30] = "01-13-items.txt";
    cargaMatCar(archivoCabeceras, matCabecera);
    cargaMatCar(archivoItems, matItems);

    // imprimirMatCabecera(matCabecera);
    // imprimirMatItems(matItems);

    // imprimirMatInt(matInt);
    imprimirTabla(matInt, matItems, matCabecera);
    ordenarTabla(matInt, matItems, 0, 0);
    printf("\n");
    imprimirTabla(matInt, matItems, matCabecera);
    // imprimirMatItems(matItems);
    // imprimirMatInt(matInt);

    return 0;
}



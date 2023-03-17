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

#include <stdio.h>

void cargaArr(int numeros[10]) {
    int i = 0;
    
    do {
        printf("Ingresa un numero: ");    
        scanf("%d", &numeros[i]);
        i++;
    } while (numeros[i-1] != 0 && i < 10);
}

void imprimirArr(int numeros[], int len) {
    printf("El array ingresado es: [");
    for (int j = 0; numeros[j] != 0 && j < len + 1; j++) {
		if (numeros[j+1] == 0 || j == 9) {
			printf("%d", numeros[j]);
		} else {
			printf("%d, ", numeros[j]);
		}
    }
	printf("]");
}

void invertirArr(int numeros[], int len) {
    int x = 0;
    int y = (len-1);
    while (x < (len-1)/2) {
        int temp = numeros[x];
        numeros[x] = numeros[y];
        numeros[y] = temp;
        x++;
        y--;
    }
}

int main() {
    // int numeros[10];
    // cargaArr(numeros);
    int numeros[10] = {5, 1, 3, 2, 4};

    int len = 0;
    for(int u = 0; numeros[u] != 0 && u < 10 ; u++) {
        len++;
    }    

    imprimirArr(numeros, len);


    // printf("\nEl numero de elementos en la array es: %d\n", len);

    // printf("\n%d, %d", (len-1), numeros[len-1]);
    // printf("\n%d, %d\n", (len-1)/2, numeros[(len-1)/2]);

    for(int x = 0; numeros[x] != 0 && x < len-1; x++) {
        for(int y = x + 1; numeros[y] != 0 && y < len; y++) {
            // printf("%d y %d\n", numeros[x], numeros[y]);
            if(numeros[x] > numeros[y]) {
                int temp = numeros[x];
                numeros[x] = numeros[y];
                numeros[y] = temp;
            }
        }
    }

    // invertirArr(numeros, len);

    imprimirArr(numeros, len);

    return 0;
}


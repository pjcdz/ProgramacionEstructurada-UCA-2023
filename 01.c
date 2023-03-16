#include <stdio.h>
#include <math.h>

// ############################# EJ 01 #######################################################################################

int main() {
    float num;
    printf("Ingrese un numero real: "); 
    scanf("%f", &num);

    printf("Piso: %.0f\n", floor(num));
    printf("Techo: %.0f\n", ceil(num));
    printf("Redondeo: %.0f\n", num);

    return 0;
}

// TEST CON 8.6 PREGUNTAR POR EL PISO = 9

// ############################# EJ 02 #######################################################################################

int suma(int num1, int num2) {
	return num1 + num2;
}

int resta(int num1, int num2) {
	return num1 - num2;
}

int multiplicacion(int num1, int num2) {
	return num1 * num2;
}

int division(int num1, int num2) {
	return num1 / num2;
}

int main() {
	int num1;
	int num2;
	
	printf("Ingrese primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese segundo numero: ");
	scanf("%d", &num2);
	
	char op;
	
	printf("Ingrese operador [+ - * /]: ");
	scanf(" %c", &op);
	
	switch (op) {
	case '+': 
		printf("\n%d %c %d = %d", num1, op, num2, suma(num1, num2));
		break;
	case '-':
		printf("\n%d %c %d = %d", num1, op, num2, resta(num1, num2));
		break;
	case '*':
		printf("\n%d %c %d = %d", num1, op, num2, multiplicacion(num1, num2));
		break;
	case '/':
		printf("\n%d %c %d = %d", num1, op, num2, division(num1, num2));
		break;
	default:
		printf("Operador invalido\n");
		break;
	}
	
	return 0;
}

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

void leer(char texto[]) {
	printf("Ingrese texto: ");
	scanf("%s", texto);
}

void reemplazar(char texto[], char reemplazar, char reemplazo) {
	for (int i = 0; i < 100; i++) {
		if (texto[i] == reemplazar) {
			texto[i] = reemplazo;
		}
	}
}

int main() {
	char texto[100];
	leer(texto);
	
	char remplazar;
	printf("Ingrese caracter a remplazar: ");
	scanf(" %c", &remplazar);
	
	char reemplazo;
	printf("Ingrese caracter de reemplazo: ");
	scanf(" %c", &reemplazo);
	
	reemplazar(texto, remplazar, reemplazo);
	
	printf("Resultado: %s", texto);
	
	return 0;
}

// ############################# EJ 04 #######################################################################################


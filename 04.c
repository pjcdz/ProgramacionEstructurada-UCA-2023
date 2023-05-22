#include <stdio.h>
#include <stdlib.h>

// ############################# EJ 01 #######################################################################################

// int multiplicacion(int a, int b) {
//     int num = 0;
//     if ( b==0 ) {
//         num = 0;
//     } else if ( b>0 ) {
//         // printf("%d, %d\n", a, b);
//         num = a + multiplicacion(a,b-1);  
//     } else if ( b<0 ) {
//         // printf("%d, %d\n", a, b);
//         num = a + multiplicacion(a,b+1);  
//     } 
//     return num;
// }

// int main() {
//     int num = multiplicacion(2, 3);
//     printf("%d", num);

//     return 0;
// }

// ############################# EJ 02 #######################################################################################

// int cociente(int a, int b) {
//     int num = 0;
//     if (a >= b) {
//         num = 1 + cociente(a-b, b);
//     } else {
//         num = 0;
//     }
//     return num;
// }

// int main() {
//     int num = cociente(9, 3);
//     printf("%d", num);

//     return 0;
// }

// ############################# EJ 03 #######################################################################################

// int resto(int a, int b) {
//     int num = 0;
//     if ( a>=b ) {
//         num = resto(a-b, b);
//     } else {
//         num = a;
//     } return num;
// }

// // int resto(10, 3) {
// //     if (10>3) {
// //         return 1 + resto(7, 3);
// //     }
// // }

// // int resto(7, 3) {
// //     if (7>3) {
// //         return 1 + resto(4, 3);
// //     }
// // }

// // int resto(4, 3) {
// //     if (4>3) {
// //         return 1 + resto(1, 3);
// //     }
// // }

// // num = 3

// // int resto(1, 3) {
// //     if (1>3) {
// //         no
// //     } else {
// //         num = 1
// //     }
// // }

// int main() {
//     int num = resto(10, 3);
//     printf("%d", num);

//     return 0;
// }

// ############################# EJ 04 #######################################################################################

void imprimirArr(int* arr, int cant) {
    for (int x = 0; x < cant; x++) {
        printf("%d, ", arr[x]);
    } printf("\n");
}

void invertir(int* arr, int num) {
    // printf("%d\n", *(arr));
    if (num > 0) {
        // printf("%d\n", *(arr+(num-1)));
        // printf("%d\n", *(arr+1));
        // printf("%d\n", *(arr+1+(num-2-1)));
        int temp = *(arr+(num-1));
        *(arr+(num-1)) = *(arr);
        *(arr) = temp;
        invertir(arr+1, num-2);
    }
}

int main() {
    int* arr = NULL;
    arr = malloc(5 * sizeof(int));
    arr[0] = 6;
    arr[1] = 2;
    arr[2] = 7;
    arr[3] = 1;
    arr[4] = 8;

    // printf("%d, ", *(arr+0));
    imprimirArr(arr, 5);
    invertir(arr, 5);
    imprimirArr(arr, 5);

    return 0;
}

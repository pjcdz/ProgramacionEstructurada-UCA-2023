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

int resto(int a, int b) {
    int num = 0;
    if ( a>=b ) {
        num = resto(a-b, b);
    } else {
        num = a;
    } return num;
}

// int resto(10, 3) {
//     if (10>3) {
//         return 1 + resto(7, 3);
//     }
// }

// int resto(7, 3) {
//     if (7>3) {
//         return 1 + resto(4, 3);
//     }
// }

// int resto(4, 3) {
//     if (4>3) {
//         return 1 + resto(1, 3);
//     }
// }

// num = 3

// int resto(1, 3) {
//     if (1>3) {
//         no
//     } else {
//         num = 1
//     }
// }

int main() {
    int num = resto(10, 3);
    printf("%d", num);

    return 0;
}
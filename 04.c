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

int cociente(int a, int b) {
    int num = 0;
    if (a >= b) {
        num = 1 + cociente(a-b, b);
    } else {
        num = 0;
    }
    return num;
}

int main() {
    int num = cociente(9, 3);
    printf("%d", num);

    return 0;
}
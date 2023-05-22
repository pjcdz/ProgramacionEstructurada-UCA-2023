#include <stdio.h>
#include <stdlib.h>

int multiplicacion(int a, int b) {
    int num = 0;
    if ( b==0 ) {
        num = 0;
    } else if ( b>0 ) {
        // printf("%d, %d\n", a, b);
        num = a + multiplicacion(a,b-1);  
    } else if ( b<0 ) {
        // printf("%d, %d\n", a, b);
        num = a + multiplicacion(a,b+1);  
    } 
    return num;
}

int main() {
    int num = multiplicacion(2, 3);
    printf("%d", num);

    return 0;
}
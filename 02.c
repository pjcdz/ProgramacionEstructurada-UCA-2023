#include <stdio.h>

// ############################# EJ 01 #######################################################################################

#include <math.h>

struct punto {
    float x;
    float y;
};

int main() {
    struct punto p1, p2;
    float distancia1, distancia2;

    printf("Ingrese las coordenadas del punto 1: ");
    scanf("%f %f", &p1.x, &p1.y);    

    printf("Ingrese las coordenadas del punto 2: ");
    scanf("%f %f", &p2.x, &p2.y);

    distancia1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
    distancia2 = sqrt(pow(p2.x, 2) + pow(p2.y, 2));

    if (distancia1 > distancia2) {
        printf("El punto 1 esta mas lejos que el 2do");
    } else if (distancia1 < distancia2) {
        printf("El punto 2 esta mas lejos que el 1ro");
    } else {
        printf("Ambos puntos estan a la misma distancia");
    }

    return 0;
}
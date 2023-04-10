#include <stdio.h>

// ############################# EJ 01 #######################################################################################

// #include <math.h>

// struct punto {
//     float x;
//     float y;
// };

// int main() {
//     struct punto p1, p2;
//     float distancia1, distancia2;

//     printf("Ingrese las coordenadas del punto 1: ");
//     scanf("%f %f", &p1.x, &p1.y);    

//     printf("Ingrese las coordenadas del punto 2: ");
//     scanf("%f %f", &p2.x, &p2.y);

//     distancia1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
//     distancia2 = sqrt(pow(p2.x, 2) + pow(p2.y, 2));

//     if (distancia1 > distancia2) {
//         printf("El punto 1 esta mas lejos que el 2do");
//     } else if (distancia1 < distancia2) {
//         printf("El punto 2 esta mas lejos que el 1ro");
//     } else {
//         printf("Ambos puntos estan a la misma distancia");
//     }

//     return 0;
// }

// ############################# EJ 02 #######################################################################################

#include <math.h>
#define F 10
#define C 2

struct punto {
    float x;
    float y;
};

void leerPuntos(float puntos[F][C]) {
    FILE* arch;
    arch = fopen("02-02.csv", "r");

    int f = 1;
    fscanf(arch, "%f,%f,", &puntos[0][0], &puntos[0][1]);
    while (f<F) {
        fscanf(arch, "%f,%f,", &puntos[f][0], &puntos[f][1]);
        f++;
    }

    fclose(arch);

    for(int x = 0; x<F; x++) {
        printf("%.1f %.1f - ", puntos[x][0], puntos[x][1]);
    }
    
}

float distanciaMin(float p1x, float p1y, float p2x, float p2y) {
    float distancia;

    // d = √((x2 - x1)^2 + (y2 - y1)^2)
    distancia = sqrt(pow(p2x - p1x, 2) + pow(p2y - p1y, 2));
    return distancia;
}

int main() {
    float puntos[F][C];
    leerPuntos(puntos);

    float minCons = 999, minSeg = 999;

    int i = 0, j = 0, x = 0;
    for(int i = 0; i<F; i++) {
        int u = i + 1;

        float dist = 0;

        dist = distanciaMin(puntos[i][0], puntos[i][1], puntos[u][0], puntos[u][1]);

        if(dist < minCons) {
            minCons = dist;
            printf("0");
        }
    }

    printf("\n%.1f\n", minCons);

    for(int j = 0; j<F; j++) {
        for(int x = j+1; x<F-1; x++) {
            float dist = 0;

            dist = distanciaMin(puntos[j][0], puntos[j][1], puntos[x][0], puntos[x][1]);

            if (dist < minSeg) {
                minSeg = dist;
                printf("1");
            }
        }
    }
    
    printf("\n%.1f\n", minSeg);

    return 0;
}


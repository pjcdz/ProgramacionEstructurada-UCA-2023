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

// #include <math.h>
// #define F 10
// #define C 2

// struct punto {
//     float x;
//     float y;
// };

// void leerPuntos(float puntos[F][C]) {
//     FILE* arch;
//     arch = fopen("02-02.csv", "r");

//     int f = 1;
//     fscanf(arch, "%f,%f,", &puntos[0][0], &puntos[0][1]);
//     while (f<F) {
//         fscanf(arch, "%f,%f,", &puntos[f][0], &puntos[f][1]);
//         f++;
//     }

//     fclose(arch);

//     for(int x = 0; x<F; x++) {
//         printf("%.1f %.1f - ", puntos[x][0], puntos[x][1]);
//     }
    
// }

// float distanciaMin(float p1x, float p1y, float p2x, float p2y) {
//     float distancia;

//     // d = √((x2 - x1)^2 + (y2 - y1)^2)
//     distancia = sqrt(pow(p2x - p1x, 2) + pow(p2y - p1y, 2));
//     return distancia;
// }

// int main() {
//     float puntos[F][C];
//     leerPuntos(puntos);

//     float minCons = 999, minSeg = 999;

//     int i = 0, j = 0, x = 0;
//     for(int i = 0; i<F; i++) {
//         int u = i + 1;

//         float dist = 0;

//         dist = distanciaMin(puntos[i][0], puntos[i][1], puntos[u][0], puntos[u][1]);

//         if(dist < minCons) {
//             minCons = dist;
//             printf("0");
//         }
//     }

//     printf("\n%.1f\n", minCons);

//     for(int j = 0; j<F; j++) {
//         for(int x = j+1; x<F-1; x++) {
//             float dist = 0;

//             dist = distanciaMin(puntos[j][0], puntos[j][1], puntos[x][0], puntos[x][1]);

//             if (dist < minSeg) {
//                 minSeg = dist;
//                 printf("1");
//             }
//         }
//     }
    
//     printf("\n%.1f\n", minSeg);

//     return 0;
// }

// ############################# EJ 03 #######################################################################################

// #define F 5
// #define C 5

// struct dataEquipos {
//     char equipo[30];
//     int pg;
//     int pe;
//     int pp;
//     int gf;
//     int gc;
// };

// typedef struct dataEquipos dataEquipos;

// int func(char archItems[30], char archDatos[30], dataEquipos arrE[F]) {
//     FILE * arch1;
//     arch1 = fopen("02-03-items.txt", "r");

//     if (arch1 == NULL) {
//         printf("Error al abrir el archivo arch1");
//         return -1;
//     }

//     int f = 0, c = 0;
//     char car;

//     while ((car = fgetc(arch1)) != EOF) {
//         if (car != '\n') {
//             arrE[f].equipo[c] = car;
//             c++;
//         } else {
//             arrE[f].equipo[c] = '\0';
//             f++;
//             c = 0;
//         }
//     }

//     fclose(arch1);


//     FILE * arch2;
//     arch2 = fopen("02-03-datos.txt", "r");

//     f = 0;

//     if (arch2 == NULL) {
//         printf("Error al abrir el archivo arch2");
//         return -1;
//     }

//     fscanf(arch2, "%d, %d, %d, %d, %d", &arrE[f].pg, &arrE[f].pe, &arrE[f].pp, &arrE[f].gf, &arrE[f].gc);
//     f++;

//     while (f<F) {
//         fscanf(arch2, "%d, %d, %d, %d, %d", &arrE[f].pg, &arrE[f].pe, &arrE[f].pp, &arrE[f].gf, &arrE[f].gc);
//         f++;
//     }

//     return 0;
// }

// // #include <string.h>

// int order(char archCabecera[30], dataEquipos arrE[F]) {
//     FILE * arch;
//     arch = fopen(archCabecera, "r");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int f = 0, c = 0;

//     char cabecera[10][10] = {};
//     char car;

//     while((car = fgetc(arch)) != EOF) {
//         if(car!='\n') {
//             cabecera[f][c] = car;
//             c++;
//         } else {
//             cabecera[f][c] = '\0';
//             f++;
//             c = 0;
//         }
//     }

//     int i = 0;
//     printf("%-15s ", cabecera[i]);
//     for (i = 1; i < 6; i++) {
//         printf("%5s ", cabecera[i]);
//     }
//     printf("\n---------------------------------------------\n");
    

//     return 0;
// }

// int main() {
//     dataEquipos arrE[F];
//     func("02-03-items.txt", "02-03-datos.txt", arrE);
//     order("02-03-cabeceras.txt", arrE);

//     // strcpy(arrE[0].equipo, " ");
//     // arrE[0].equipo[0] = 'a';
//     // arrE[0].equipo[1] = '\0';
//     // arrE[0].equipo[2] = 'c';
//     // arrE[0].equipo[3] = '\0';
//     // printf("%s", arrE[0].equipo);

//     for(int x = 0; x<F; x++) {
//         printf("%-15s %5d %5d %5d %5d %5d\n", arrE[x].equipo, arrE[x].pg, arrE[x].pe, arrE[x].pp, arrE[x].gf, arrE[x].gc);
//     }

//     return 0;
// }

// ############################# EJ 04 #######################################################################################

#define F 5
#define C 30

struct dataPersonas {
    int dni;
    char nombre[30];
    char pais[30];
};

typedef struct dataPersonas dataPersonas;

int ingreso(dataPersonas arrP[F]) {
    int dniTemp;
    scanf("%d", &dniTemp);

    arrP[0].dni = 0;
    if (dniTemp < 100000000 && dniTemp != 0) {
        arrP[0].dni = dniTemp;
    }

    printf("%d", arrP[0].dni);

    return 0;
}

int main() {
    dataPersonas arrP[F];
    ingreso(arrP);

    return 0;
}
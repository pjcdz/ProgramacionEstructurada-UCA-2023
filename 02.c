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

// #define F 5
// #define C 30

// struct dataPersonas {
//     int dni;
//     char nombre[30];
//     char pais[30];
// };

// typedef struct dataPersonas dataPersonas;

// void ingreso(dataPersonas arrP[F]) {
//     FILE *arch;

//     arch=fopen("02-03-personas.csv", "a");

//     printf("Ingrese el DNI: ");
//     int dniTemp;
//     scanf("%d", &dniTemp);

//     for(int f = 0; dniTemp != 0 && f<F; f++) {
//         arrP[0].dni = 1;
//         if (dniTemp < 100000000 && dniTemp != 0) {
//             arrP[f].dni = dniTemp;
//         }

//         // printf("%d", arrP[f].dni);
//         char buffer = getchar();

//         printf("Ingrese el nombre: ");
        
//         int i = 0;
//         char aux;
//         if (i<100-1) {
//             aux = getchar();
//         }
//         while (aux!='\n' && i<100-1) {
//             arrP[f].nombre[i] = aux;
//             i++;
//             if(i<100-1) {
//                 aux = getchar();
//             }
//         }
//         arrP[f].nombre[i] = '\0';

//         printf("Ingrese el pais: ");
        
//         i = 0;
//         if (i<100-1) {
//             aux = getchar();
//         }
//         while (aux!='\n' && i<100-1) {
//             arrP[f].pais[i] = aux;
//             i++;
//             if(i<100-1) {
//                 aux = getchar();
//             }
//         }
//         arrP[f].pais[i] = '\0';

//         fprintf(arch ,"%d,%s,%s\n", arrP[f].dni, arrP[f].nombre, arrP[f].pais);

//         printf("---------------------------------------------\n");

//         printf("Ingrese el DNI: ");
//         scanf("%d", &dniTemp);
//     }

//     fclose(arch);
// }

// int main() {
//     dataPersonas arrP[F];
//     ingreso(arrP);

//     return 0;
// }

// ############################# EJ 05 #######################################################################################

// #define F 5
// #define C 30

// struct dataPersonas {
//     int dni;
//     char nombre[30];
//     char pais[30];
// };

// typedef struct dataPersonas dataPersonas;

// int impresion(dataPersonas arrP[F]) {
//     FILE *arch;

//     arch = fopen("02-03-personas.csv", "r");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     printf("%-15s %-15s %-15s\n", "Documento", "Nombre", "Pais");
//     printf("---------------------------------------------\n");

//     int r;
//     int f = 0;
//     r = fscanf(arch, "%d, %[^,], %s", &arrP[f].dni, arrP[f].nombre, arrP[f].pais);		
//     while(r!=EOF){
//         printf("%-15d %-15s %-15s\n", arrP[f].dni, arrP[f].nombre, arrP[f].pais);  
//         f++;
//         r = fscanf(arch, "%d, %[^,], %s", &arrP[f].dni, arrP[f].nombre, arrP[f].pais);	
//     }	

//     fclose(arch);

//     return 0;
// }

// int main() {
//     dataPersonas arrP[F];
//     impresion(arrP);
//     return 0;
// }

// ############################# EJ 06 #######################################################################################

// #define F 3
// #define C 30

// struct dataPersonas {
//     int dni;
//     char nombre[30];
//     char pais[30];
// };

// typedef struct dataPersonas dataPersonas;

// int cargar(dataPersonas arrP[F]) {
//     FILE *arch;

//     arch = fopen("02-03-personas.csv", "r");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int r;
//     int f = 0;
//     r = fscanf(arch, "%d, %[^,], %s", &arrP[f].dni, arrP[f].nombre, arrP[f].pais);		
//     while(r!=EOF){
//         f++;
//         r = fscanf(arch, "%d, %[^,], %s", &arrP[f].dni, arrP[f].nombre, arrP[f].pais);	
//     }	

//     fclose(arch);

//     return 0;
// }

// #include <string.h>

// void ordenarNombre(dataPersonas arrP[F]) {
//     dataPersonas aux;

//     for(int x = 0; x<F-1; x++) {
//         for(int u = x + 1; u<F; u++) {
//             if (strcmp(arrP[x].nombre, arrP[u].nombre) > 0) {
//                 aux = arrP[x];
//                 arrP[x] = arrP[u];
//                 arrP[u] = aux;
//             }
//         }
//     }
// }

// void ordenarDocumento(dataPersonas arrP[F]) {
//     dataPersonas aux;

//     for(int x = 0; x<F-1; x++) {
//         for(int u = x + 1; u<F; u++) {
//             if (arrP[x].dni > arrP[u].dni) {
//                 aux = arrP[x];
//                 arrP[x] = arrP[u];
//                 arrP[u] = aux;
//             }
//         }
//     }
// }

// void ordenarPais(dataPersonas arrP[F]) {
//     dataPersonas aux;

//     for(int x = 0; x<F-1; x++) {
//         for(int u = x + 1; u<F; u++) {
//             if (strcmp(arrP[x].pais, arrP[u].pais) > 0) {
//                 aux = arrP[x];
//                 arrP[x] = arrP[u];
//                 arrP[u] = aux;
//             }
//         }
//     }
// }

// void imprimir(dataPersonas arrP[F]) {
//     printf("%-15s %-15s %-15s\n", "Documento", "Nombre", "Pais");
//     printf("---------------------------------------------\n");

//     for(int f = 0; f<F; f++) {
//         printf("%-15d %-15s %-15s\n", arrP[f].dni, arrP[f].nombre, arrP[f].pais);  
//     }
// }

// int main() {
//     dataPersonas arrP[F];
//     cargar(arrP);
//     imprimir(arrP);

//     printf("1- Ver listado ordenado por nombre\n");
//     printf("2- Ver listado ordenado por documento\n");
//     printf("3- Ver listado ordenado por pais\n");
//     printf("4- Salir del programa\n");

//     int opcion;
//     printf("Seleccion: ");
//     scanf("%d", &opcion);
//     if (opcion == 1) {
//         ordenarNombre(arrP);
//         imprimir(arrP);
//     } else if (opcion == 2) {
//         ordenarDocumento(arrP);
//         imprimir(arrP);
//     } else if (opcion == 3) {
//         ordenarPais(arrP);
//         imprimir(arrP);
//     } else if (opcion == 4) {
//         printf("Saliendo del programa");
//     } else {
//         printf("Opcion incorrecta");
//     }

//     return 0;
// }

// ############################# EJ 07 #######################################################################################

// typedef struct
// {
// char nombre[100];
// int legajo, materias[30];
// }
// t_alumno;

// typedef struct
// {
// char nombre[100];
// int codigo;
// }
// t_materia;

// typedef struct
// {
// int legajo_alumno;
// int cod_materia,nota;
// }
// t_nota;

// #define MAX_ALUMNOS 3
// #define MAX_MATERIAS 4

// int ingresoAlumnos(int num_mat[MAX_MATERIAS]) {
//     FILE *arch;
//     arch = fopen("02-07-alumnos.csv", "a");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int legajo;
//     printf("Ingrese el legajo del alumno: ");
//     scanf("%d", &legajo);
//     int num_alumnos = 0;
//     int q = 0;

//     while (legajo != 0 && num_alumnos < MAX_ALUMNOS) {
//         char buffer = getchar();
//         char nombre[100];
//         printf("Ingrese el nombre del alumno: ");
        
//         char c;
//         int i = 0;
//         while((c = getchar()) != '\n' && i < 99) {
//             nombre[i] = c;
//             i++;
//         } nombre[i] = '\0';

//         int materias[30];
//         int num_materias = 0;
//         int cod_materia;
//         int u = 0;
//         do { 
//             printf("Ingrese las materias del alumno: ");
//             scanf("%d", &cod_materia);
            
//             if (cod_materia != 0) {
//                 materias[u] = cod_materia;
//                 num_materias++;
//                 u++;
//             }
//         } while (cod_materia != 0 && u < 30 && num_materias < MAX_MATERIAS);

//         num_mat[q] = num_materias;
//         q++;

//         fprintf(arch, "%d,%s,", legajo, nombre);
//         for (int x = 0; x < num_materias; x++) {
//             if (x == num_materias - 1) {
//                 fprintf(arch, "%d", materias[x]);
//             } else {
//                 fprintf(arch, "%d,", materias[x]);
//             }
//         }
//         fprintf(arch, "\n");

//         printf("---------------------------------------------\n");
//         printf("Ingrese el legajo del alumno: ");
//         scanf("%d", &legajo);

//         num_alumnos++;
//     }

//     fclose(arch);   
//     return 0;
// }

// int ingresoMaterias() {
//     FILE *arch;
//     arch = fopen("02-07-materias.csv", "a");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int cod_materia;
//     printf("Ingrese el codigo de la materia: ");
//     scanf("%d", &cod_materia);
//     int num_materias = 0;

//     while (cod_materia != 0 && num_materias < MAX_MATERIAS) {
//         char buffer = getchar();
//         char nombre_materia[100];
//         printf("Ingrese el nombre de la materia: ");
        
//         char c;
//         int i = 0;
//         while((c = getchar()) != '\n' && i < 99) {
//             nombre_materia[i] = c;
//             i++;
//         } nombre_materia[i] = '\0';

//         fprintf(arch, "%d,%s\n", cod_materia, nombre_materia);

//         printf("---------------------------------------------\n");
//         printf("Ingrese el codigo de la materia: ");
//         scanf("%d", &cod_materia);

//         num_materias++;
//     }

//     fclose(arch);   
//     return 0;
// }

// int cargarAlumnos(t_alumno arrAlumnos[MAX_ALUMNOS]) {
//     FILE *arch;
//     arch = fopen("02-07-alumnos.csv", "r");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int r;
//     int f = 0;

//     r = fscanf(arch, "%d,%[^,]", &arrAlumnos[f].legajo, arrAlumnos[f].nombre);
//     r = fscanf(arch, ",%d", &arrAlumnos[f].materias[0]);
//     for(int x = 1; x < MAX_MATERIAS; x++) {
//         r = fscanf(arch, ",%d", &arrAlumnos[f].materias[x]);
//     }

//     while (r != EOF && f < MAX_ALUMNOS) {
//         // printf("%d,%s", arrAlumnos[f].legajo, arrAlumnos[f].nombre);
//         // for(int u = 0; u < MAX_MATERIAS; u++) {
//         //     printf(",%d", arrAlumnos[f].materias[u]);
//         // } printf("\n");

//         f++;

//         r = fscanf(arch, "%d,%[^,]", &arrAlumnos[f].legajo, arrAlumnos[f].nombre);
//         r = fscanf(arch, ",%d", &arrAlumnos[f].materias[0]);
//         for(int x = 1; x < MAX_MATERIAS; x++) {
//             r = fscanf(arch, ",%d", &arrAlumnos[f].materias[x]);
//         }
//     }

//     fclose(arch);   
//     return 0;
// }

// int cargarMaterias(t_materia arrMaterias[MAX_MATERIAS]) {
//     FILE *arch;
//     arch = fopen("02-07-materias.csv", "r");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int r;
    
//     int f = 0;
//     r = fscanf(arch, "%d,%[^\n]", &arrMaterias[f].codigo, arrMaterias[f].nombre);
//     while (r != EOF && f < MAX_ALUMNOS) {
//         // printf("%d,%s\n", arrMaterias[f].codigo, arrMaterias[f].nombre);
//         f++;
//         r = fscanf(arch, "%d,%[^\n]", &arrMaterias[f].codigo, arrMaterias[f].nombre);
//     }

//     fclose(arch);   
//     return 0;
// }

// int ingresoNotas(t_alumno arrAlumnos[MAX_ALUMNOS], t_materia arrMaterias[MAX_MATERIAS]) {
//     FILE *arch;
//     arch = fopen("02-07-notas.csv", "a");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int legajo_alumno;
//     int cod_materia,nota;

//     for (int i = 0; i < MAX_ALUMNOS; i++) {
//         printf("El alumno: %s, de legajo: %d\n", arrAlumnos[i].nombre, arrAlumnos[i].legajo);
//         for(int u = 0; u < MAX_MATERIAS; u++) {
//             printf("Cursa la materia: %s, con codigo: %d\n", arrMaterias[u].nombre, arrMaterias[u].codigo);

//             int nota;
//             printf("Ingrese la nota: ");
//             scanf("%d", &nota);

//             fprintf(arch, "%d,%d,%d\n", arrAlumnos[i].legajo, arrMaterias[u].codigo, nota);
//         }
//     }
    
//     return 0;
// }

// int cargarNotas(t_nota arrNotas[MAX_ALUMNOS*MAX_MATERIAS]) {
//     FILE *arch;
//     arch = fopen("02-07-notas.csv", "r");

//     if (arch == NULL) {
//         printf("Error al abrir el archivo");
//         return -1;
//     }

//     int f = 0;
//     int r = fscanf(arch, "%d,%d,%d", &arrNotas[f].legajo_alumno, &arrNotas[f].cod_materia, &arrNotas[f].nota);
//     while (r != EOF && f < MAX_ALUMNOS*MAX_MATERIAS) {
//         // printf("%d,%d,%d\n", arrNotas[f].legajo_alumno, arrNotas[f].cod_materia, arrNotas[f].nota);
//         f++;
//         r = fscanf(arch, "%d,%d,%d", &arrNotas[f].legajo_alumno, &arrNotas[f].cod_materia, &arrNotas[f].nota);
//     }

//     return 0;
// }

// void notasAlumno(t_alumno arrAlumnos[MAX_ALUMNOS], t_materia arrMaterias[MAX_MATERIAS], t_nota arrNotas[MAX_ALUMNOS*MAX_MATERIAS]) {
//     int legajo_sel;
//     printf("Ingrese el legajo del alumno: ");
//     scanf("%d", &legajo_sel);

//     for(int i = 0; i < MAX_ALUMNOS; i++) {
//         if (arrAlumnos[i].legajo == legajo_sel) {
//             printf("El alumno: %s, de legajo: %d\n", arrAlumnos[i].nombre, arrAlumnos[i].legajo);
//             printf("Cursa las siguientes materias:\n");
//             for(int u = 0; u < MAX_MATERIAS; u++) {
//                 if (arrAlumnos[i].materias[u] == arrMaterias[u].codigo) {
//                     printf("Materia: %s, con codigo: %d\n", arrMaterias[u].nombre, arrMaterias[u].codigo);
//                     for(int x = 0; x < MAX_ALUMNOS*MAX_MATERIAS; x++) {
//                         if (arrNotas[x].legajo_alumno == arrAlumnos[i].legajo && arrNotas[x].cod_materia == arrMaterias[u].codigo) {
//                             printf("Nota: %d\n", arrNotas[x].nota);
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

// void notasMaterias(t_alumno arrAlumnos[MAX_ALUMNOS], t_materia arrMaterias[MAX_MATERIAS], t_nota arrNotas[MAX_ALUMNOS*MAX_MATERIAS]) {
//     int codigo_sel;
//     printf("Ingrese el codigo de la materia: ");
//     scanf("%d", &codigo_sel);

//     for(int i = 0; i < MAX_MATERIAS; i++) {
//         if(arrMaterias[i].codigo == codigo_sel) {
//             printf("La materia seleccionada es %s, de codigo %d\n", arrMaterias[i].nombre, arrMaterias[i].codigo);
//             printf("Los alumnos que tienen esta materia son:\n");
//             for(int u = 0; u < MAX_ALUMNOS; u++) {
//                 for(int x = 0; x < MAX_MATERIAS; x++) {
//                     if(arrAlumnos[u].materias[x] == arrMaterias[i].codigo) {
//                         printf("%s - ", arrAlumnos[u].nombre);
//                         for(int o = 0; o < MAX_ALUMNOS * MAX_MATERIAS; o++) {
//                             if(arrNotas[o].legajo_alumno == arrAlumnos[u].legajo && arrNotas[o].cod_materia == arrAlumnos[u].materias[x]) {
//                                 printf("Nota: %d\n", arrNotas[o].nota);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

// int main() {
//     // ingresoAlumnos(num_mat);
//     // ingresoMaterias();

//     t_alumno arrAlumnos[MAX_ALUMNOS];
//     cargarAlumnos(arrAlumnos);
//     t_materia arrMaterias[MAX_MATERIAS];
//     cargarMaterias(arrMaterias);
//     printf("\n");
//     // ingresoNotas(arrAlumnos, arrMaterias);
//     t_nota arrNotas[MAX_ALUMNOS*MAX_MATERIAS];
//     cargarNotas(arrNotas);
//     printf("\n");
//     // notasAlumno(arrAlumnos, arrMaterias, arrNotas);
//     notasMaterias(arrAlumnos, arrMaterias, arrNotas);

//     return 0;
// }

// ############################# EJ 08 #######################################################################################

// void code(unsigned char c) {
//     unsigned char mask = 1;
//     int i = 7;
//     while(i >= 0) {
//         if ((c&(mask<<i))!=0) {
//             printf("1");
//         } else {
//             printf("0");
//         }
//         i--;
//     }
// }

// int main() {
//     unsigned char c = 'a';
//     code(c);

//     return 0;
// }

// ############################# EJ 09 #######################################################################################

// void code(unsigned char c) {
//     unsigned char mask = 1;
//     int i = 7;
//     while(i>=0) {
//         if((c&(mask<<i)) != 0) {
//             printf("1");
//         } else {
//             printf("0");
//         }
//         i--;
//     }
// }

// int main() {
//     unsigned char c = 'a';
//     printf("El char es '%d', y su binario es: ", c);
//     code(c);
//     printf("\n");
//     c = c >> 3;
//     printf("El char es '%d', y su binario es: ", c);
//     code(c);
//     printf("\n");


//     return 0;
// }

// ############################# EJ 10 #######################################################################################

#include <math.h>

int main() {
    unsigned int num = 2023;
    unsigned int mask = 1;

    printf("El num es %d, y su binario: ", num);
    int i = 31;
    int count = 0;
    while(i>=0) {
        if ((num&(mask<<i)) != 0) {
            printf("1");
            count++;
        } else {
            printf("0");
        }
        i--;
    }
    printf("\nEl num de veces que aparecio el 1 fueron: %d", count);
    

    return 0;
}
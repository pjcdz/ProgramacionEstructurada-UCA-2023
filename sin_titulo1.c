#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_nodo {
	char* producto;
	float precio;
	int codigo;
	struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo;

struct s_nodoAux {
	char producto[50];
	float precio;
	int codigo;
};

typedef struct s_nodoAux t_nodoAux;

struct s_titulo {
	char tituloProducto[50];
	char tituloPrecio[50];
	char tituloCodigo[50];
};

typedef struct s_titulo t_titulo;


int leerArch(t_nodo* ls, char* archivo) {
	FILE* arch;
	arch = fopen(archivo, "r");
	
	if (arch == NULL) {
		printf("error");
		return -1;
	}
	
	t_titulo tittle;
	
	fscanf(arch, "%[^,], %[^,], %[^,\n]\n", tittle.tituloProducto, tittle.tituloPrecio, tittle.tituloCodigo);
	printf("%s, %s, %s", tittle.tituloProducto, tittle.tituloPrecio, tittle.tituloCodigo);
	
	fclose(arch);
	return 0;
}

int main() {
	t_nodo ls = NULL;
	
	leerArch(&ls, "06-parcial-datos.csv");
}

void escribirArch(char * nomArch, char* txt) {
    FILE* arch;
    arch = fopen(nomArch, "w");

    if (arch == NULL) {
        printf("Error al abrir el archivo");
    }

    fprintf("%s", txt);
    fclose(arch);
}

int main() {
    char* str = NULL;
    // str = cargarStrDin1();
    cargarStrDin2(&str);
    escribirArch("03-08-frase.txt", str);
    printf("%s", str);
}
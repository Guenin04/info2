#include <stdio.h>
#include <stdlib.h>

typedef struct measurement {
    __int32_t timestamp; // Epoch time in seconds
    char description[256];
    char data[]; // membre flexible car il n'a pas de taille définie à la compilation 
    // le membre flexible doit toujours être le dernier membre de la structure et il doit être précédé d'au moins un autre membre
} Measurement;

int main(){
    FILE *fp = fopen("data.bin", "rb");

    fseek(fp, 0, SEEK_END);
    const size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    Measurement *m = malloc(size); // Allocation de mémoire pour la structure et les données flexibles
    fread(m, size, 1, fp); // Lecture de la structure et des données flexibles à partir du fichier
    fclose(fp);

    printf("Description: %s\n", m -> description);
    printf("Timestamp: %d\n", m -> timestamp);

    const int n = (size - sizeof(Measurement)) / sizeof(m->data[0]); // Taille des données flexibles
    for(int i = 0; i < n; i++) {
        printf("Data[%d]: %hhd\n", i, m -> data[i]);
    }

}
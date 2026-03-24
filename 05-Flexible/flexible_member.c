#include <stdio.h>
#include <stdlib.h>

typedef struct measurement {
    __int32_t timestamp; // Epoch time in seconds
    char description[256];
    float data[]; // membre flexible car il n'a pas de taille définie à la compilation 
    // le membre flexible doit toujours être le dernier membre de la structure et il doit être précédé d'au moins un autre membre
} Measurement;

int main() {
    printf("%lu\n", sizeof(Measurement)); // Affiche la taille de la structure sans les données flexibles

    Measurement *m = malloc(sizeof(Measurement) + sizeof(float) * 256); // Allocation de mémoire pour la structure et les données flexibles (256 floats)
    m -> data[127] = 42; // *(int*)(m + 4 + 256 + 4*127) = 42; 
    
    printf("%lu\n", sizeof(*m)); // Affiche la taille de la structure sans les données flexibles
    return 0;
}
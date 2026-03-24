#include <stdio.h>

typedef struct measurement {
    __int32_t timestamp; // Epoch time in seconds
    char description[256];
    char data[]; // membre flexible car il n'a pas de taille définie à la compilation 
    // le membre flexible doit toujours être le dernier membre de la structure et il doit être précédé d'au moins un autre membre
} Measurement;

int main() {
    FILE *fp = fopen("data.bin", "wb");
    Measurement m = {
        .timestamp = 1625097600, // 1er juillet 2021
        .description = "Donnée Météo"
    };
    fwrite(&m, sizeof(m), 1, fp); // Écriture de la structure sans les données flexibles

    for(char i = 0; i < 120; i++) {
        fwrite(&i, sizeof(i), 1, fp); // Écriture des données flexibles
    }


    return 0;
}
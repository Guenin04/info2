#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct data{
    uint16_t year;
    uint8_t month;
    uint8_t temperature; // Offset -100°C
    uint16_t precipitation; 
} Data;

int main(int argc, char *argv[]){
    Data data = {
        .year = 2026,
        .month = 3,
        .temperature = 16 + 100, // Offset -100°C
        .precipitation = 5
    };
    char *p = (char*)&data;
    for (int i = 0; i < sizeof(Data); i++) {
        printf("%02hhX ", p[i]);
    }
    printf("\n%ld\n", sizeof(Data));

    FILE *fp = fopen("data.dat", "wb");
    fprintf(fp, "Weather\n");   //En-tête du fichier
    fwrite(&data, sizeof(Data), 1, fp); // Écriture de la structure dans le fichier
    fclose(fp);

    //lecture
    Data buffer;
    FILE *fp_in = fopen("data.dat", "rb");
    // Vérification de l'en-tête du fichier
    char magic[7];
    fread(magic, sizeof(char), 7, fp_in);
    if(strcmp(magic, "Weather") != 0){
        fprintf(stderr, "Invalid file format\n");
        fclose(fp_in);
        return 1;
    }

    // Lecture de la structure à partir du fichier
    fread(&buffer, sizeof(data), 1, fp_in);
    fclose(fp_in);
    const char *months[]  = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("Year: %hu\n", data.year);
    printf("Month: %s\n", months[(data.month - 1)%12]);
    printf("Temperature: %hhu°C\n", data.temperature - 100); // Offset -100°C
    printf("Precipitation: %humm\n", data.precipitation);

    return 0;
}
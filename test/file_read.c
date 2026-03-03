#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    //Variables declaration and initialisation 
    double temps = 0;
    double sum = 0;
    char line[255] = {0};
    char buffer[255] = {0};
    unsigned int count = 0;
    unsigned int i = 0;
    unsigned int j = 0;

    //open the temp file for reading and check for errors
    FILE *fp = fopen("temperatures.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Erreur lors de la lecture du fichier des temperatures\n");
        return 1;
    }

    //read each line of the file until the function throws a null
    while (fgets(line, sizeof(line), fp) != NULL) {
        i = 0; //to read new lines
        while (line[i] != '\0') {
            //if a separator is found advance in the line
            if (line[i] == ' ' || line[i] == ',') {
                i++;
                continue;
            }
            j = 0;
            //while reading the current data is not finished, save the value in a buffer
            while (line[i] != '\0' && line[i] != ' ' && line[i] != ',') {
                buffer[j++] = line[i++];
            }
            //add the end of string char
            buffer[j] = '\0';
            //if there has been any value read convert it and add it to the sum
            if (j > 0) {
                temps = atof(buffer);
                sum += temps;
                count++;
            }
        }
    }

    //Close file and chech for error while closing
    int close_ctrl = fclose(fp);
    if (close_ctrl != 0) {
        fprintf(stderr, "Erreur lors de la fermeture du fichier des temperatures\n");
        return 1;
    }

    //Stop division by 0
    if (count > 0) {
        printf("Moyenne : %.2lf°C\n", sum / count);
    } else {
        fprintf(stderr, "Erreur, aucune valeur dans le fichier des temperatures\n");
        return 1;
    }
    
    return 0;
}

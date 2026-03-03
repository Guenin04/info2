#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    char line[256] = {0};
    char *token = 0;

    //open the temp file for reading and check for errors
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Erreur lors de la lecture du fichier des temperatures\n");
        return 1;
    }
    
    //Read a line of the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        //Read the first token and print it 
        token = strtok(line," ");
        printf("%s\n", token);
        //while there are tokens
        while(token != NULL){
            //read the line and tokenize it
            token = strtok(NULL," ");
            //if there was a token print it
            if(token != NULL){
                printf("%s\n", token);
            }
        }
    }

    //Close file and chech for error while closing
    int close_ctrl = fclose(fp);
    if (close_ctrl != 0) {
        fprintf(stderr, "Erreur lors de la fermeture du fichier des temperatures\n");
        return 1;
    }
    return 0;

}
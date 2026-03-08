#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    //create file and check if an error has occured
    FILE *fp = fopen("text.txt","r");
    if(fp == NULL){
        fprintf(stderr, "Erreur lors de l'ouverture du fichier '\n");
        return 1;
    }
    unsigned int words = 0;
    int prev_char = '\0'; 
    int current_char;

    while ((current_char = fgetc(fp)) != EOF) {
        if (ispunct(current_char) || isblank(current_char) || current_char == '\n') {
            if (isalpha(prev_char)) {
                words++;
            }
        }
        prev_char = current_char;
    }
    
    if(current_char == EOF){
        words++;
    }
    //Close file and chech for error while closing
    int close_ctrl = fclose(fp);
    if (close_ctrl != 0) {
        fprintf(stderr, "Erreur lors de la fermeture du fichier des temperatures\n");
        return 1;
    }
    printf("%u mot%c dans les paroles\n",words,words == 1 ? '\0':'s');
}
#include <stdio.h>


int main(){
    FILE* fp = fopen("test.txt","w+");
    if(fp == NULL){
        fprintf(stderr, "Erreur, impossible de créer le fichier !");
    }
    fprintf(fp,"super nickel !!");
    if(fclose(fp)!= 0){
        fprintf(stderr, "Erreur, impossible de fermer le fichier !");
    }
}
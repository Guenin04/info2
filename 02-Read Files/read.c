#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    //create file and check if an error has occured
    FILE *fp = fopen("text.txt","r");
    if(fp == NULL)return 1;

    //declare the vowel dictionnary
    const char *letters = "aeiouy";
    //
    const size_t size = strlen(letters);
    size_t counts[size];
    //initialize the memory zone with zeros 
    memset(counts,0,size*sizeof(counts[0]));

    char c;
    while((c = fgetc(fp)) && c != EOF){
        for(int i = 0; i<size;i++){
            counts[i] += tolower(c) == letters[i];
        }
    }
    for(int i = 0;i < size ;i++){
        printf("Nombre de %c: %ld\n",letters[i],counts[i]);
    }
    fclose(fp);
}
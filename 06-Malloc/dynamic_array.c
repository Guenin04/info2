#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector{
    size_t elements; //Nombre d'éléments dans le tableau
    size_t capacity; //Taille de l'espace mémoire 
    int *data;
} Vector;

typedef struct options {
    char *in_filename;   // NULL if reading from STDIN, or the filename
    char *out_filename;  // NULL if writing to STDOUT, or the filename
    bool binary_output;  // Binary output flag
} Options;

int vector_get(const Vector *v, size_t i){
    return v->data[i];
}

int vector_push_back(Vector *v, int value){
    v->elements++;
    if(v->elements > v->capacity){
        v->capacity *= 2;   //Facteur de croissance
        v->data = realloc(v->data, v->capacity*sizeof(int));
    }
    v->data[v->elements-1] = value;
}

int vector_pop_back(Vector *v){
    v->elements--;
    return v->data[v->elements];
}

int vector_pop_front(Vector *v){
    int x = v->data[0];
    for(size_t i = 0; i < v->elements - 1; i++){
        v->data[i] = v->data[i+1];
    }
    v->elements--;
    return x;
}

void vector_push_front(Vector *v, int value){
    v->elements++;
    if(v->elements > v->capacity){
        v->capacity *= 2;   //Facteur de croissance
        v->data = realloc(v->data, v->capacity*sizeof(int));
    }
    for(size_t i = v->elements - 1; i > 1; i--){
        v->data[i] = v->data[i-1];
    }
    v->data[0] = value;
}


int main() { 
    Vector v;
    vector_push_back(&v,42);
    vector_push_front(&v,24);
    int x = vector_pop_back(&v);
    int w = vector_pop_front(&v);
    printf("Valeur: %d\n",vector_get(&v,0));

}
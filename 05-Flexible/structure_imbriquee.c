#include <stdio.h>

typedef struct student{
    char name[64];         // Nom complet de l'étudiant
    float note;            // Note de l'étudiant
} Student;

typedef struct filiere{
    char name[64];          // Nom complet de la filière
    Student students[20];   // Tableau de 20 étudiants dans la filière
} Filiere;

typedef struct departement{
    char name[64];          // Nom complet du département
    char acronyme[10];      // Nom court du département
    Filiere filieres[5]; 
} Departement;


int main() {
    Departement tin;
    tin.filieres[2].students[5].note = 3.74;
    printf("%lu\n", sizeof(Departement)); // Affiche la taille de la structure Departement
}
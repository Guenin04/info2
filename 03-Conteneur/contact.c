#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char first_name[128];
    char last_name[128];
    int age;
    int icq;
    char phone[30];
} Contact;

void display_contact(const Contact *c);

int main(int argc, char *argv[]){

    Contact contacts[10] = {
        {"Noé", "Guenin",21,22133431,"+41764200529"},
        {"Jean", "Dupont", 30, 12345678, "+33123456789"},
        {"Alice", "Smith", 25, 87654321, "+44123456789"},
        {"Bob", "Johnson", 28, 13579246, "+55123456789"},
        {"Charlie", "Brown", 22, 24681357, "+61123456789"},
        {"David", "Wilson", 35, 98765432, "+81123456789"},
        {"Eve", "Davis", 27, 54321678, "+91123456789"},
        {"Frank", "Miller", 31, 67890123, "+12123456789"},
        {"Charlie", "Kirk", 29, 32165498, "+13123456789"},
        {"Jeffrey", "Epstein", 66, 12345678, "+14123456789"}
    };

    for(int i = 0; i<10;i++){
        display_contact(contacts + i);
    }

}

void display_contact(const Contact *c){
    printf("First Name: %s\n", c -> first_name);
    printf("Last Name: %s\n", c -> last_name);
    printf("Age: %d\n", c -> age);
    printf("ICQ: %d\n", c -> icq);
    printf("Phone: %s\n", c -> phone);
    printf("\n");
}
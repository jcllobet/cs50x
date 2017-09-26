#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"
//constant STUDENTS fixed to 3
#define STUDENTS 3

int main(void){
    //type, name array, constant
    student students[STUDENTS];

    for(int i = 0; i < STUDENTS; i++) {
        printf("name: ");
        students[i].name = get_string();

        printf("dorm: ");
        students[i].dorm = get_string();

    }

    FILE *file = fopen("students.csv", "w");
    if (file != NULL){
        for (int i = 0; i < STUDENTS; i++){
            //printing strings into a file
            fprintf(file, "%s,%s\n", students[i].name, students[i].dorm);
        }
        fclose(file);
    }

}

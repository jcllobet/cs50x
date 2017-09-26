#include <stdio.h>
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

    for (int i = 0; i < STUDENTS; i++){
        printf("%s is in %s.\n", students[i].name, students[i].dorm);
    }
}

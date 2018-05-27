#include <stdio.h>
#include <string.h>

typedef struct student{
    int num;
    char name[10];
    float score[3];
}Student;



void print(Student *);

int main(){
    Student stu;

    stu.num = 1;
    /* Can't use stu.name = "Alex", because stu.name is just a pointer, and it's an array name, which is not a modifiable value*/
    strcpy(stu.name, "Alex");
    stu.score[0] = 90.0;
    stu.score[1] = 85.0;
    stu.score[2] = 80.0;

    Student* tmp = &stu;
    print(tmp);
}


void print(Student *stu){
    printf("Name is %s\tNum is %d\n", stu->name, stu->num);
    printf("Score1 is %f\tScore2 is %f\tScore3 is %f\n", stu->score[0], stu->score[1], stu->score[2]);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct str{
    int len;
    char s[0];
}Str;


void make(Str tmp){
    tmp.len = 2;
}

//This is not allowed in C
/*
void make_ptr(str &tmp){
    tmp.len = 3;
}
*/

void make_ptr2(Str *tmp){
    tmp->len = 4;
}

int main(){
    Str tmp;
    //tmp is a struct variable

    tmp.len = 1;
    printf("original: tmp.len = %d\n", tmp.len);
    
    make(tmp);
    printf("make: tmp.len = %d\n", tmp.len);

    make_ptr2(&tmp);
    //Need to get the address of tmp if want to use pointer
    printf("make_ptr2: tmp.len = %d\n", tmp.len);

    return 0;
}




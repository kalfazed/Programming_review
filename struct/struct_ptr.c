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


void make_ptr2(Str *tmp){
    tmp->len = 4;
}

int main(){
    Str* tmp;
    //tmp is a pointer

    tmp->len = 1;
    printf("original: tmp.len = %d\n", tmp->len);
    
    make(*tmp);
    //If want to use it as a struct, need to get the entity of it
    printf("make: tmp.len = %d\n", tmp->len);

    make_ptr2(tmp);
    printf("make_ptr2: tmp.len = %d\n", tmp->len);

    return 0;
}




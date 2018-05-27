#include <stdio.h>

struct stud{
    long int num;
    float score;
};


void funvr(struct stud t){
    t.num = 2000101;
    t.score = 71.0;
}


void funar(struct stud t){
    t[0].num = 3000101;
    t[0].score = 81.0;
    t[1].num = 3000102;
    t[1].score = 82.0
}


void funpt(struct stud *t){
    t->num = 4000101;
    (*t).score = 92.0;
}



void main()
{
    struct stud a[2]={
        {1000101, 61.0},
        {1000102, 62.0}
    };
    
    struct stud b = a[0], *p;

    printf("old b: b.num: %ld\tb.score: %f\n", b.num, b.score);
    
    //It won't change the content
    funvr(b);
    printf("Call funvr, new b: b.num: %ld\tb.score: %f\n", b.num, b.score);


    //data will be changed
    funpr(&b);
    printf("Call funpr, new b: b.num: %ld\tb.score: %f\n", b.num, b.score);
    printf("old a: a[0].num: %ld\ta[0].score: %f\n", a[0].num, a[0].score);
    printf("old a: a[1].num: %ld\ta[1].score: %f\n", a[1].num, a[1].score);



    //data will be changed
    funar(a);
    printf("new a: a[0].num: %ld\ta[0].score: %f\n", a[0].num, a[0].score);
    printf("new a: a[1].num: %ld\ta[1].score: %f\n", a[1].num, a[1].score);


}

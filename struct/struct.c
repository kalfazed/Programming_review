#include <stdio.h>

struct stud{
    long int num;
    float score;
};


void funvr(struct stud t){
    t.num = 2000101;
    t.score = 71.0;
}


void funar(struct stud t[]){
    t[0].num = 3000101;
    t[0].score = 81.0;
    t[1].num = 3000102;
    t[1].score = 82.0;
}


void funpr(struct stud *t){
    t->num = 4000101;
    (*t).score = 92.0;
}



int main()
{
    struct stud a[2]={
        {1000101, 61.0},
        {1000102, 62.0}
    };
    
    struct stud b = a[0];
    struct stud* c = &a[0];

    printf("old b: b.num: %ld\tb.score: %f\n", b.num, b.score);
    
    //It won't change the content
    funvr(b);
    printf("Call funvr, new b: b.num: %ld\tb.score: %f\n", b.num, b.score);
    printf("\n");


    //data will be changed
    funpr(&b);
    printf("Call funpr with '&', new b: b.num: %ld\tb.score: %f\n", b.num, b.score);
    printf("Data is not changed, old a: a[0].num: %ld\ta[0].score: %f\n", a[0].num, a[0].score);
    printf("\n");

    funpr(c);
    printf("Call funpr with '*', new c: c.num: %ld\tc.score: %f\n", c->num, c->score);
    printf("Data is changed, old a: a[0].num: %ld\ta[0].score: %f\n", a[0].num, a[0].score);
    printf("\n");



    //data will be changed
    printf("old a: a[0].num: %ld\ta[0].score: %f\n", a[0].num, a[0].score);
    printf("old a: a[1].num: %ld\ta[1].score: %f\n", a[1].num, a[1].score);
    funar(a);
    printf("new a: a[0].num: %ld\ta[0].score: %f\n", a[0].num, a[0].score);
    printf("new a: a[1].num: %ld\ta[1].score: %f\n", a[1].num, a[1].score);


    return 1;
}

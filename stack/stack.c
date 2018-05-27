#include <stdio.h>


typedef struct _tag_stack_
{
    int a[20];
    int top;
}Sqstack;


Sqstack* InitStack(){
    Sqstack *ret = NULL;
    ret = (Sqstack*)malloc(sizeof(Sqstack));
    if(ret)
        ret ->top = 0;
    return ret;
}


int Push(Sqstack* stack, int data){
    stack->a[stack->top] = data;
    stack->top++;
    return 1;
}

void Play(Sqstack* stack){
    int i;
    if (stack->top == 0)
        printf("Empty stack\n");

    for(i = 0; i < stack->top; i++){
        printf("The data is %d\n", stack->a[i]);
    }
}

int Pop(Sqstack* stack, int* data){
    if (stack->top == 0)
        printf("Nothing to pop\n");
    else{
        stack->top --;
        *data = stack->a[stack->top];
    }
    return 1;
}


int main(){
    int i, data;
    Sqstack* stack;
    stack = InitStack();
    for(i = 0; i<5; i++)
        Push(stack, i);
    while(stack->top > 0) {
        Pop(stack, &data);
        printf("The pop data is %d\n", data);
    }
    return 1;
}

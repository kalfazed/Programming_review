#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int element;

typedef struct node{
    element data;
    struct node *pNext;
}Node, *pNode;

typedef struct stack{
    pNode pTop;
    pNode pBottom;
}Stack, *pStack;


void InitStack(pStack);
void PushStack(pStack, int);
bool IsEmpty(pStack);
void PopStack(pStack, int*);
void TraverseStack(pStack);
void ClearStack(pStack);




int main()
{
    pStack stack;
    InitStack(stack);
    int i, u;
    for(i = 0; i<10; i++)
        PushStack(stack, i);
    //TraverseStack(stack);
    while(!IsEmpty(stack)){
        PopStack(stack, &u);
        printf("The pop data is %d\n", u);
    }
    TraverseStack(stack);
    return 1;
}



void InitStack(pStack s){
    s->pBottom = (Node*)malloc(sizeof(Node));
    if (!s->pBottom)
        printf("Error in allocating the memory to the stack\n");
    s->pTop = s->pBottom;
    s->pTop->data = 0;
    s->pTop->pNext = NULL;
}


void PushStack(pStack s, int val){
    pNode p = (Node*)malloc(sizeof(Node));
    if(!p)
        printf("Error in allocating the memory to the node\n");
    p->data = val;
    p->pNext = s->pTop;
    s->pTop = p;
}


bool IsEmpty(pStack s){
    return (s->pTop == s->pBottom);
}


void TraverseStack(pStack s){
    if (IsEmpty(s))
        printf("The stack is empty\n");
    else{
        pNode p = s->pTop;
        while(p!=s->pBottom){
            printf("The data is %d\n", p->data);
            p = p->pNext;
        }
    }
}

void PopStack(pStack s, int *val){
    if (IsEmpty(s))
        printf("The stack is empty\n");
    else{
        pNode p = s->pTop;
        *val = p->data;
        s->pTop = s->pTop->pNext;
        /* Release the memory pointed by p */
        free(p);
        p = NULL;
    }
}


void ClearStack(pStack s){
    if (IsEmpty(s))
        printf("The stack is empty\n");
    else{
        pNode p = NULL;
        while(!IsEmpty(s)){
            p = s->pTop;
            s->pTop = s->pTop->pNext;
            free(p);
            p = NULL;
        }
    }
}



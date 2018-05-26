#include <stdio.h>
#include <stdlib.h>

#define STACKINITSIZE 100
#define STACKINCREASESIZE 20

typedef char ElemType;

typedef struct tree{
    ElemType data;
    struct tree* lchild;
    struct tree* rchild;
    unsigned int isOut;
}TreeNode, *Tree;

typedef struct stack{
    Tree* base;
    Tree* top;
    int stacksize;
}Sqstack;



/* Initialization of stack*/
void InitStack(Sqstack &s);
void Push(Sqstack &s, Tree e);
void Pop(Sqstack &s);
int StackEmpty(Sqstack s);


/* Initialization of tree*/
void CreateTree(Tree &t);
void PreOrder(Tree t);
void PreOrder_no_recursive(Tree t);
void InOrder(Tree t);
void InOrder_no_recursive(Tree t);
void PostOrder(Tree t);
void PostOrder_no_recursive(Tree t);



/* Implementation of stack*/
void InitStack(Sqstack &s){
    s.base = (Tree*)malloc(STACKINITSIZE*sizeof(Tree));
    if (!s.base)
        printf("Error in allocating memory to stack!");
    s.top = s.base;
    s.stacksize = STACKINITSIZE;
}

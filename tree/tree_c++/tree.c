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
void GetTop(Sqstack &s, Tree e);
void Pop(Sqstack &s, Tree e);
int StackEmpty(Sqstack s);


/* Initialization of tree*/
void CreateTree(Tree &t);
void PreOrder(Tree t);
void PreOrder_no_recursive(Tree t);
void InOrder(Tree t);
void InOrder_no_recursive(Tree t);
void PostOrder(Tree t);
void PostOrder_no_recursive(Tree t);



int main(){
    Tree T;
    printf("\nPlease input the tree with PreOrder, end with '#'");
    CreateTree(T);

    printf("\nThe result of PreOrder is: ");
    PreOrder(T);

    printf("\nThe result of InOrder is: ");
    InOrder(T);

    printf("\nThe result of PostOrder is: ");
    PostOrder(T);

    printf("\n");

}




/* Implementation of stack*/
void InitStack(Sqstack &s){
    s.base = (Tree*)malloc(STACKINITSIZE*sizeof(Tree));
    if (!s.base)
        printf("Error in allocating memory to stack!\n");
    s.top = s.base;
    s.stacksize = STACKINITSIZE;
}


void Push(Sqstack &s, Tree e){
    if(s.top - s.base >= STACKINITSIZE){
        s.base = (Tree*)realloc(s.base, (s.stacksize+STACKINITSIZE)*sizeof(Tree));

        if(!s.base){
            printf("Error in allocating memory to stack!\n");
        }

        s.top = s.base + s.stacksize;
        s.stacksize += STACKINITSIZE;
    }
    e->isOut = 0;
    *s.top++ = e;
}

void GetTop(Sqstack &s, Tree e){
    e = *(s.top-1);
}

void Pop(Sqstack &s, Tree e){
    if(s.top == s.base)
        printf("Stask is null\n");
    e = *(--s.top);
}


int StackEmpty(Sqstack &s){
    return (s.top == s.base);
}



/* Implementation of tree*/

void CreateTree(Tree &t){
    char ch;
    scanf ("%c", &ch);
    if (ch == '#')
        t = NULL;
    else{
        t = (Tree)malloc(sizeof(TreeNode));
        if (!t){
            printf("Error in allocating memory to tree!\n");
            return;
        }
        t->data = ch;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}


/* Implementation of PreOrder */
void PreOrder(Tree e){
    if(e){
        printf("%c", e->data);
        PreOrder(e->lchild);
        PreOrder(e->rchild);
    }
}


/* Implementation of InOrder */
void InOrder(Tree e){
    if(e){
        PreOrder(e->lchild);
        printf("%c", e->data);
        PreOrder(e->rchild);
    }
}


/* Implementation of PostOrder */
void PostOrder(Tree e){
    if(e){
        PreOrder(e->lchild);
        PreOrder(e->rchild);
        printf("%c", e->data);
    }
}

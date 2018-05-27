#include <stdio.h>
#include <stdlib.h>

typedef char TypeData;

typedef struct tree{
    TypeData data;
    struct tree *lchild;
    struct tree *rchild;
}Tree;

Tree* CreateTree();
void PreOrder(Tree*);
void InOrder(Tree*);
void PostOrder(Tree*);



int main(){


    printf("\nPlease input the tree, end with '#':");
    Tree* t;
    t = CreateTree();

    printf("\nThe result of PreOrder is:");
    PreOrder(t);
    printf("\nThe result of InOrder is:");
    InOrder(t);
    printf("\nThe result of PostOrder is:");
    PostOrder(t);
    printf("\n");
}
    


Tree* CreateTree(){
    Tree* t = NULL;
    char ch = 0;


    scanf("%c", &ch);
    if(ch == '#')
        t = NULL;
    else{
        t = (Tree*)malloc(sizeof(Tree)+1);
        if (!t){
            printf("There is an error in allocating memory to tree!\n");
            return 0;
        }
        t->data = ch;
        t->lchild = CreateTree();
        t->rchild = CreateTree();
    }
    return t;
}


void PreOrder(Tree* t){
    if (t){
        printf("%c", t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void InOrder(Tree* t){
    if (t){
        InOrder(t->lchild);
        printf("%c", t->data);
        InOrder(t->rchild);
    }
}

void PostOrder(Tree* t){
    if (t){
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        printf("%c", t->data);
    }
}


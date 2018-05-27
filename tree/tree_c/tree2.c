#include <stdio.h>
#include <stdlib.h>


typedef struct tree{
    char data;
    struct Tree* lchild;
    struct Tree* rchild;
}Tree;


void CreateTree(Tree &t);
void PreOrder(Tree*);
void InOrder(Tree*);
void PostOrder(Tree*);


int main(){
    Tree t;
    printf("\nPlease input the tree, end with '#': ");
    CreateTree(t);
    printf("\nThe result of PreOrder is: ");
    PreOrder(t);
    printf("\nThe result of InOrder is: ");
    InOrder(t);
    printf("\nThe result of PostOrder is: ");
    PostOrder(t);

}


void CreateTree(Tree &t){
    char input;
    scanf("%c", &input);
    if (input == '#')
        t = NULL;
    else{
        t = (Tree*)malloc(sizeof(Tree)+1);
        t->data = input;
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}


void PreOrder(Tree* t){
    if(t){
        printf("%c", t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}


void InOrder(Tree* t){
    if(t){
        InOrder(t->lchild);
        printf("%c", t->data);
        InOrder(t->rchild);
    }
}


void PostOrder(Tree* t){
    if(t){
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        printf("%c", t->data);
    }
}

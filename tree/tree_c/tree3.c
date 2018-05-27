#include <stdio.h>
#include <stdlib.h>


typedef struct tree{
    char data;
    struct Tree* lchild;
    struct Tree* rchild;
}Tree;



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

int main(){
    Tree t;
    printf("\nPlease input the tree, end with '#': ");
    CreateTree(t);

}


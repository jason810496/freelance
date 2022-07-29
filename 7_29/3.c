#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int val;
    struct node*L, *R;
};

void UI(){
    printf("Enter data to be inserted or type -1 for no insertion : ");
}
void UI_L(int v){
    printf("Enter left child of : %d\n" ,v);
}
void UI_R(int v){
    printf("Enter right child of : %d\n" ,v);
}

node *newNode(int v){
    node *ret = (node*)malloc(sizeof(node));
    ret->val =v;
    return ret;
}
void build(node **root){
    (*root)->val = 10;
    (*root)->L = newNode(11);
    (*root)->L->L = newNode(7);
    (*root)->R = newNode(9);
    (*root)->R->L = newNode(15);
    (*root)->R->R = newNode(8);
}

int insert(node **root , int v){
    if( !(*root)->L ){
        (*root)->L = newNode(v);
        return 1;
    }
    if( !(*root)->R ){
        (*root)->R = newNode(v);
        return 1;
    }

    if( insert(&(*root)->L,v) ) return 1;
    if( insert(&(*root)->R,v) ) return 1;
}

void inorder(node *root){
    if( !root ) return;

    inorder( root->L );
    printf("%d " , root->val );
    inorder( root->R );
}

int main(){

    
    node *root;

    build(&root); 
    printf("before insertion : ");
    inorder(root);

    insert(&root , 12 );
    printf("\nafter insertion : ");
    inorder(root);

    return 0;
}
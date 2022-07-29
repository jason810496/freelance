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

void build(node **root){
    UI();
    int v;
    scanf("%d" , &v );
    (*root)->val = v;
    if( v==-1 ) return ;
    
    (*root)->L = (node*)malloc(sizeof(node));
    (*root)->R = (node*)malloc(sizeof(node));
    
    UI_L( v );
    build(&(*root)->L);

    UI_R( v );
    build(&(*root)->R);
}

void inorder(node *root){
    if( !root || root->val==-1 ) return;

    inorder( root->L );
    printf("%d " , root->val );
    inorder( root->R );
}

void preorder(node *root){
    if( !root || root->val == -1 ) return ;

    printf("%d " , root->val );
    preorder( root->L );
    preorder( root->R ); 
}

int main(){

    int flag = 1 ;
    node *root;

    build(&root); 

    printf("inorder traversal:\n");
    inorder(root); 

    // P2 
    printf("\npreorder traversal:\n");
    preorder(root);

    return 0;
}
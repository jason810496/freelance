#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* newNode(int value){
    Node *temp = malloc( sizeof( Node) ) ;
    temp->data = value;
    return temp;
}


typedef struct LinkedList{
    Node *head , *tail;
    int size;


}LinkedList;

void Init(LinkedList *list){
    list->head = malloc(sizeof(Node));
    list->tail = malloc(sizeof(Node));
    list->size = 0;
}

void push_back(LinkedList *list,int value){;
    if( (*list).size==0 ){
        (*list).head = (*list).tail = newNode( value );
        (*list).size++;
        return ;
    }

    (*list).size++;

    Node *temp = list->tail;
    temp->next = newNode( value );
    list->tail = temp->next;
}

void push_front(LinkedList *list , int value ){

    if( (*list).size==0 ){
        (*list).head = (*list).tail = newNode( value );
        (*list).size++;
        return ;
    }

    Node *temp = newNode( value );
    temp->next = list->head;
    list->head = temp ;
}

void delete(LinkedList *list , int value ){
    Node *temp = list->head;

    while( temp->next && temp->next->data != value){
        temp = temp->next;
    }

    temp->next = temp->next->next;
}

void reverse(LinkedList *list ){
    Node *pre=NULL ,  *nxt=NULL , *cur=list->head;
    
    while( cur ){
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    list->head = pre;
}

void P3_even_and_odd(LinkedList *list){
    LinkedList odd , even;
    Init(&odd);
    Init(&even);
    Node *temp = list->head;

    for(int flag=1 ; temp ; flag=!flag){
        if( flag ){
            push_back( &odd , temp->data );
        }
        else{
            push_back( &even , temp->data );
        }
        temp = temp->next;
    }

    Init(list);

    temp = odd.head;
    while( temp ){
        push_back( list, temp->data );
        temp = temp->next;
    }
    temp = even.head;
    while( temp ){
        push_back( list , temp->data );
        temp = temp->next;
    }   
}

int P4_is_palindrome(LinkedList *list){
   int arr[list->size];
   Node *temp = list->head;
   for( int i=0; temp ; i++){
        arr[i] = temp->data;
        temp = temp->next;
   }

   for(int i=0;i<= list->size/2 ;i++){
        if( arr[i]!=arr[list->size-i-1] ) return 0;
   }

   return 1;
}

void P5(LinkedList *list){
    Node *temp = list->head , *even=NULL;
    // delete odd 

    while( temp->next ){
        if( temp->next->data&1 ){
            even = temp->next->next;

            while( even && even->data&1 ){
                even = even->next;
            }
            temp->next = even;
        }
        temp = temp->next;
    }

    reverse(list);
}

void printList(LinkedList *list ){
    Node *temp = list->head ; 
    printf("[ ");
    while( temp ){
        printf("%d" , temp->data );
        temp = temp->next ;
        if( temp ) printf(" , ");
    }
    printf(" ]\n");
}

int main(){

    // LinkedList list;
    // Init(&list);
    // // list.head->data = 1;
    // // printf( "%d" , list.head->data );

    // for(int i=0;i<10;i++){
    //     push_back(&list , i );
    // }

    // for(int i=0;i<10;i++){
    //     push_front(&list,-i);
    // }

    // Node *temp = list.head;

    // while( temp ){
    //     printf( "%d " ,temp->data  );
    //     temp = temp->next ;
    // }

    // temp = list.tail;

    // while( temp ){
    //     printf( "%d " ,temp->data  );
    //     temp = temp->next ;
    // }

    // printf("\n\n");

    // delete(&list,6);

    // printList(&list);

    // push_front(&list , 100 );

    // reverse(&list);

    // printList(&list);


    int arr[8] = {78 , 56 , 47 ,13 ,12 ,4};
    LinkedList list;
    Init(&list);
    for(int i=0;i<6;i++){
        push_back( &list ,  arr[i] );
    }

    // printList(&list);
    // P3_even_and_odd(&list);
    // printList(&list);

    // int res = P4_is_palindrome(&list);
    // printf( "%d \n" , res );

    P5(&list);
    printList(&list);

    return 0;
}
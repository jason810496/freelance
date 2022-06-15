#include "Queue.h"
#include<iostream>
#include<stdexcept>


// Desc:  Constructor
Queue::Queue() : size(0), front(0) , back(0) , capacity(INITIAL_SIZE){
    arr = new int[capacity];
} // constructor


// Desc:  Destructor
Queue::~Queue() {
    delete [] arr;
} // destructor

// Double Capcity when the array is full 
void Queue::DoubleCapcity(){
    int *temp = new int[capacity*2];

    for(int i=1 , j=front ; i<=size ; i++){
        temp[i] = arr[ ++j%capacity ];
    }

    back = size;
    front = 0;
    capacity*=2;

    delete [] arr;
    arr = temp;

    //std::cout<<"Double cap check\n";
}


// Halve Capcity when size < capcity/4 and min capcity > INITIAL_SIZE
void Queue::HalveCapcity(){
    int *temp = new int[capacity/2];

    for(int i=1 , j=front ; i<=size ; i++){
        temp[i] = arr[ ++j%capacity ];
    }

    back = size;
    front = 0;
    capacity/=2;

    delete [] arr;
    arr = temp;

    //std::cout<<"Halve cap check\n";
}

// Desc:  Copy Constructor
Queue::Queue(const Queue &other) {
    capacity = other.capacity;
    arr = new int[capacity];

    for(int i=0;i<other.capacity;i++){
        arr[i]=other.arr[i];
    }
    front = other.front;
    back = other.back;
    size = other.size;
    

    std::cout<<" copy \n";

} // copy constructor


// Desc:  Assignment operator
Queue & Queue::operator=(const Queue &rhs) {
    if (this != &rhs) {

        delete [] arr;
        capacity = rhs.capacity;
        arr = new int[ capacity ];
        size = rhs.size;
        front = rhs.front;
        back = rhs.back;

        for(int i=0;i<capacity;i++){
            arr[i] = rhs.arr[i];
        }

    }

    // std::cout<<" = oper \n";
    return *this;
} // lhs = rhs


// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
    if( isFull() ){
        DoubleCapcity();
    }
    back = (back+1)%capacity;
    arr[ back ] = x;
    size++;
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    if( isEmpty() ){ // Queue is empty
        // throw error
        throw std::logic_error("Queue is empty");
    }
    
    front = ( front+1)%capacity;
    size--;

    if( size< capacity/4 && capacity/2 > INITIAL_SIZE ){
        HalveCapcity();
    }
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    if( isEmpty() ){ // Queue is empty
        throw std::logic_error("Queue is empty");
    }
    
    return arr[ (front+1)%capacity ];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return (back==front);
} // isempty

bool Queue::isFull() const {
    return ((back+1)%capacity==front);
}
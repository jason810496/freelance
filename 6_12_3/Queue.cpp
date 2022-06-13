#include "Queue.h"
#include<stdexcept>


// Desc:  Constructor
Queue::Queue() : size(0), capacity(INITIAL_SIZE){
    capacity = INITIAL_SIZE;
    arr = new int[capacity];
} // constructor


// Desc:  Destructor
Queue::~Queue() {
    delete arr;
} // destructor


// Desc:  Copy Constructor
Queue::Queue(const Queue &other) {
    if (this != &other) {
        if( capacity < other.size ){ // deal with case that out of range 
            arr = new int[ other.capacity ];
            capacity = other.capacity;
        }
        size = other.size;

        for (unsigned i = 0; i < size ; i++) {
            arr[i] = other.arr[i];
        }
    }
} // copy constructor


// Desc:  Assignment operator
Queue & Queue::operator=(const Queue &rhs) {
    if (this != &rhs) {
        if( capacity < rhs.size ){ // deal with case that out of range 
            arr = new int[ rhs.capacity ];
            capacity = rhs.capacity;
        }
        size = rhs.size;

        for (unsigned i = 0; i < size ; i++) {
            arr[i] = rhs.arr[i];
        }
    }
    return *this;
} // lhs = rhs


// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
    if( size == capacity ){
        capacity*=2; // double capcity ;

        int dump[size]; // dump array that store original data
        for(int i=0;i<size;i++){ // copy data 
            dump[i] = arr[i];
        }
        arr = new int[capacity]; // new
        for(int i=0;i<size;i++){ //copy back to new array
            arr[i] = dump[i];
        }

    }
    arr[size++] = x;
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    if( size==0 ){ // Queue is empty
        // throw error
        throw std::logic_error("Queue is empty");
    }
    size--;
    
    if( size < capacity/4 ){ // array is less than 1/4 full 
        // new capacity that no less than INITIAL_SIZE
        capacity = ( INITIAL_SIZE > capacity/4 ? INITIAL_SIZE:capacity/4 );
        int dump[size];
        for(int i=0;i<size;i++){ //copy data 
            dump[i]=arr[i];
        }
        arr = new int[capacity];
        for(int i=0;i<size;i++){ // copy back 
            arr[i]=dump[i];
        }
    }
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    if( size==0 ){ // Queue is empty
        throw std::logic_error("Queue is empty");
    }
    return arr[size-1];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return size == 0;
} // isempty
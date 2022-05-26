#include<bits/stdc++.h>

namespace CS52 {

    class Container {

    public :
        Container (); // default constructor
        Container ( int size , int initial_value ); // overloaded constructor
        Container ( const Container & ); // copy constructor
        ~ Container (); // Destructor

        // Returns a reference to the element at location i in an Container .
        int& at ( int i ) const ;// throws an std :: string exception

        // Returns the allocated storage for an Container .
        int capacity () const ;

        // Erases the elements of an Container but does not change capacity .
        void clear ();

        // Returns pointer to the first element in an Container .
        int* data () const ;

        // If Container is empty return true , else false .
        bool empty () const ;

        // Deletes the element at the end of an Container .
        void pop_back ();

        void allocation(int n);
        // Add an element to the end of the Container .
        void push_back ( int element );

        // Returns a reference to the first element in an Container .
        int& front () const ; // throws an std :: out_of_range exception

        // Returns a reference to the last element in an Container .
        int& back () const ; // throws an std :: out_of_range

        // Returns the number of elements in the Container .
        int size () const ;

        // Search for a key in Container
        // return index of key or - if not found
        int find (int key );

        // Overloaded operators
        int& operator [] ( int i ); // [] array syntax
        Container & operator =( const Container & ); // copy assignment

        // Overloaded stream insertion operator
        friend std :: ostream & operator <<( std :: ostream & , Container &);

    private :
        int _size = 0;
        int _capacity = 0;
        int* _data = nullptr ;

    }; // Container
}// namespace

CS52::Container::Container(){
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

CS52::Container::Container( int size , int initial_value ){
    _capacity = size;
    _size = size;
    _data = new int[size];
    
    for(int i=0;i<size;i++){
        _data[i] = initial_value;
    }
}

CS52::Container::Container ( const Container & other){
    _data = new int[ other.size() ];
    for(int i=0;i< other.size() ;i++){
        _data[i] = other.at(i);
    }
    _size = other.size() ; 
}

CS52::Container::~ Container (){
    delete[] _data;
}

int& CS52::Container::at( int i ) const{

    if (i < 0 || _size <= i) throw std::out_of_range("Out of Range!");
    return _data[ i ];
}

int CS52::Container::capacity() const{
    return _capacity;
}

void CS52::Container::clear(){
    _size = 0;
}

int* CS52::Container::data() const{
    return _data;
}

bool CS52::Container::empty() const{
    return _size==0;
}

void CS52::Container::pop_back() {
    if ( _size<=0) throw std::out_of_range("Out of Range!");
    _size--;
}

void CS52::Container::allocation(int n){
    if( n<=_capacity ) return ;

    int *temp = new int [ n ];
    _capacity = n;

    for(int i=0;i<_size ; i++ ){
        temp[i] = _data[i];
    }

    delete [] _data;
    _data = temp ;
}

void CS52::Container::push_back(int element) {
    if( _size+1 >= _capacity ){
        allocation( _capacity*2+10 );
    }

    _data[ ++_size-1 ] = element; 
}

int& CS52::Container::front() const{
    return _data[0];
}

int& CS52::Container::back() const{
    return _data[ _size-1 ];
}

int CS52::Container::size() const{
    return _size;
}

int CS52::Container::find( int key ){
    for(int i=0;i< _size ;i++){
        if( _data[i]==key ) return i;
    }

    return -1;
}

int& CS52::Container::operator[](int i ){
    if( i<0 || i>=_size ) throw std::out_of_range("Out of Range!");
    return _data[ i ];
}

CS52::Container& CS52::Container::operator=( const Container & other ){
    this->_data = other.data();
    this->_capacity = other.capacity();
    this->_size = other.size();
}

std :: ostream & operator <<( std :: ostream & ,CS52::Container &other){
    for(int i=0;i<other.size() ; i++){
        std::cout<<other[i]<<' ';
    }
}
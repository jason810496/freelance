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

        // Add an element to the end of the Container .
        void push_back ( int element );

        // Returns a reference to the first element in an Container .
        int& front () const ; // throws an std :: out_of_range exception

        // Returns a reference to the last element in an Container .
        int& back () const // throws an std :: out_of_range

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
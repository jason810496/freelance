#include <vector>
#include <iostream>
#include "AVLTree.h"
using namespace std;

int main(){

    AVLTree<int,int> T;
    T.insert( 1,1);
    T.insert( 2,2);
    T.insert( 3,3);
    T.insert( 4,4);
    T.insert( -1 ,-1);
    T.insert( -5,-5);


    cout<<T.search(4)<<"\n";

    T.inorder();

    cout<<T.remove( 1 )<<"\n";

    T.inorder();

    cout<<T.search( 2 )<<"\n";

    try
    {
        cout<<T.search( 1 )<<"\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout<<T.search( 2 );

    AVLTree<int,int> T2( T );

    T2.inorder();

    T.remove( 3 );
    T.inorder();
    cout<<"\n";
    T2.inorder();
    cout<<"\n";

    cout<<T2.remove(-6)<<"\n";
    cout<<T2.search(-1)<<"\n";
    cout<<T2.insert( -1 ,-1 )<<"\n";
    T2.inorder();
    cout<<T2.insert(-10,-10)<<"\n";

    AVLTree<int,int> T3;
    T3 = T;
    T.inorder();
    T3.inorder();
    T.insert( 8,8);
    T3.insert( 9,9);
    T.inorder();
    T3.inorder();
    
    return 0;
}
// Basic test program for AVL Tree
// Author: John Edgar
// Date: July 2022

#include <vector>
#include <iostream>
#include "AVLTree.h"
using std::cout;
using std::endl;
using std::vector;


/*void a4marking();
template <class K, class V>
bool checkAVLTree(const AVLTree<K, V>& tree);*/


int main()
{
    //a4marking();
  /*int key_arr[]={3,5,6,4,2,1};
  int value_arr[]={0,0,1,0,0,0};
  AVLTree<int,int> tree_orig;
  for(int i=0; i<6; i++){
    tree_orig.insert(key_arr[i],value_arr[i]);
  }
  tree_orig.print2D();
  AVLTree<int, int> tree_cpy=tree_orig;
  tree_cpy.print2D();
  cout<<"size="<<tree_cpy.getsize()<<endl;
  for(int i=0; i<6; i++){
    cout<<tree_cpy.keys()[i];
  }
  cout<<"\n";
  if(tree_cpy.search(6)==1){
    cout<<"search 1 test passed";
  }
  if(tree_cpy.search(9)==false){
    cout<<"search 2 test passed";
  }*/
  
  cout<<"===================check avl tree(insert)====================\n";
  int key_arr1[]={2,1,7,5,8,9,0,3,6,4};
  int val_arr1[]={1,2,3,4,5,6,7,8,9,10};
  AVLTree<int,int> avltreetest=AVLTree<int,int>();
  for(int i=0; i<10; i++){
    //cout<<"inserted value="<<key_arr1[i]<<endl;
    avltreetest.insert(key_arr1[i],val_arr1[i]);
    //avltreetest.print2D();
    //avltreetest.inorder_print();
    //cout<<"------------------------------------"<<endl;
  }
  //cout<<"for-loop complated"<<endl;
//   avltreetest.print2D();
  //avltreetest.inorder_print();

  /*cout<<"======================getHeight test=======================\n";
  int key_arr2[]={10,11,20,12,16,17,14,13,9,8,3,2,1,6,5,4};
  int val_arr2[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  AVLTree<int,int> height_tree=AVLTree<int,int>();
  for(int i=0; i<16; i++){
    height_tree.insert(key_arr2[i],val_arr2[i]);
  }
  height_tree.print2D();*/
  cout<<"========================AVLTree remove test========================\n";
  AVLTree<int,int>cpy1;
  
  cpy1 = avltreetest;
//   cpy1.print2D();
  // cpy1.remove(6);
  avltreetest.remove( 6 );
//   cpy1.print2D();
    cout << endl;
}

/*void a4marking()
{
    AVLTree<int, int> aspen;
    checkAVLTree<int, int>(aspen);

    // Method return values
    bool success = aspen.insert(1, 2);
    success = aspen.remove(1);
    int result = aspen.search(1);
    vector<int> v2 = aspen.values();
    vector<int> k1 = aspen.keys();
    AVLTree<int, int> larch(aspen);
    aspen = larch;

    cout << endl << "end a4 test" << endl;
}*/

template <class K, class V>
bool checkAVLTree(const AVLTree<K, V>& tree)
{
    AVLTreeNode<int, int>* nd = (AVLTreeNode<int, int>*)tree.getRoot();
    cout << "height = " << nd->height << endl;

    return false;
}


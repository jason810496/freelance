# include <iostream>
# include <vector>
using namespace std;
// AVL Node Clas
template<class T, class S>
class AVLTreeNode {
public:
	// Should have attributes named:
	// parent - pointer to parent
	// left - pointer to left child
	// right - pointer to right child
	// key - node's key ( balance factor )
	// value - node's value
	// height - node's height
  AVLTreeNode*parent;
  AVLTreeNode*left;
  AVLTreeNode*right;
  T key;
  S value;
  unsigned int height;
	// Constructors ...
  AVLTreeNode(){
    key=0;
    value=0;
    height=0;
    parent=NULL;
    left=NULL;
    right=NULL;
  }
  AVLTreeNode(T key1, S value1){
    key=key1;
    value=value1;
    height=0;
    parent=NULL;
    left=NULL;
    right=NULL;
  }
};

// AVL Tree class
// T : key
// S : value
template<class T, class S>
class AVLTree
{
private:
  AVLTreeNode<T,S>*root;
  unsigned int Size;
  void leftRotate(AVLTreeNode<T,S>* node);
  void rightRotate(AVLTreeNode<T,S>* node);
  void updateTreeBalance(AVLTreeNode<T,S> *node);
  void updateHeight(AVLTreeNode<T,S> *node);
  inline int getHeight(AVLTreeNode<T,S> *node ){ return (node ? node->height: -1 ); }
  inline int getKey(AVLTreeNode<T,S> *node){ return (node ? getHeight(node->left)-getHeight(node->right):0); }
	// Tree attributes go here
	// Your tree MUST have a root node named root
  // helper function recomended 
  S search(S val , AVLTreeNode<T,S> *node);
  bool insert(S val , AVLTreeNode<T,S> *node);
  bool remove(S val , AVLTreeNode<T,S> *node);
public:
  AVLTree();
  AVLTree(const AVLTree &other);
	AVLTree &operator=(const AVLTree &other);
  ~AVLTree();
  bool insert(S val);
  bool remove(S val);
  S search(S val);
  vector<S> values();
  vector<T> keys();
  unsigned int size();
	void* getRoot() const { return root; }; // DO NOT REMOVE
};

// AVL Tree Methods go here


// private 
template<class T, class S> void AVLTree<T,S>::leftRotate(AVLTreeNode<T,S>* node){

}

template<class T, class S> void AVLTree<T,S>::rightRotate(AVLTreeNode<T,S>* node){
  AVLTreeNode<T,S> leftChild = node->left;
  AVLTreeNode<T,S> temp = node->right;

  node->left = temp;
  leftChild->right = node;

}
template<class T,class S> void AVLTree<T,S>::updateTreeBalance(AVLTreeNode<T,S> *node){

}

template<class T,class S> void AVLTree<T,S>::updateHeight(AVLTreeNode<T,S> *node){
  if( !node ) return;

  node->height = max( getHeight(node->left) , getHeight(node->right) )+1;
}

// public 
template<class T, class S> AVLTree<T,S>::AVLTree(){
  root = nullptr;
  Size = 0;
}

template<class T, class S> AVLTree<T,S>::AVLTree(const AVLTree &other){
  
}


template<class T, class S>bool AVLTree<T,S>::insert(S val){
  if( !root ) root = new AVLTreeNode( 0 , val );
  else{
    root = insert( val , getRoot() );
  }
}

template<class T, class S>bool AVLTree<T,S>::insert(S val , AVLTreeNode<T,S> *node){
  if( !node ){
    return new AVLTreeNode(val);
  }

  if( node->value < val ){
    node->riht = insert( val , node->right );
  }
  else{
    node->left = insert( val , node->left );
  }

}

template<class T, class S>bool AVLTree<T,S>::remove(S val){

}

template<class T, class S>S AVLTree<T,S>::search(S val){
  if( !getRoot() ) return nullptr;

  return search(val , getRoot() );
}
template<class T,class S>S AVLTree<T,S>::search(S val , AVLTreeNode<T,S> *node){
  if( !node ) return nullptr;

  if( node->value < val ){
    return search( val , node->right );
  }
  else if( node->value > val ){
    return serach( val , node->left );
  }
  else return node;
}



template<class T, class S>unsigned int AVLTree<T,S>::size(){
  return Size;
}

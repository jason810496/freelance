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
  AVLTreeNode<T,S>* leftRotate(AVLTreeNode<T,S>* node);
  AVLTreeNode<T,S>* rightRotate(AVLTreeNode<T,S>* node);
  AVLTreeNode<T,S>* updateTreeBalance(AVLTreeNode<T,S> *node);
  AVLTreeNode<T,S>* maxValueNode(AVLTreeNode<T,S>* node);
  void updateHeight(AVLTreeNode<T,S> *node);
  inline int getHeight(AVLTreeNode<T,S> *node ){ return (node ? node->height: -1 ); }
  inline int getFactor(AVLTreeNode<T,S> *node){ return (node ? getHeight(node->left)-getHeight(node->right):0); }
	// Tree attributes go here
	// Your tree MUST have a root node named root
  // helper function recomended 
  AVLTreeNode<T,S>* insert(T key1, S value1, AVLTreeNode<T,S> *node , bool &flag);
  AVLTreeNode<T,S>* remove(T key1, AVLTreeNode<T,S> *node , bool &flag );

  AVLTreeNode<T,S>* CopyTree(AVLTreeNode<T,S>* orig);
  void buildKeys(vector<T> &keys , AVLTreeNode<T,S> *node);
  void buildValues(vector<S> &values , AVLTreeNode<T,S> *node);

  void deleteTree(AVLTreeNode<T,S> *node);
  void DFS(AVLTreeNode<T,S> *node);

public:
  AVLTree();
  AVLTree(const AVLTree &other);
	AVLTree &operator=(const AVLTree &other);
  ~AVLTree();
  bool insert(T key1, S value1);
  bool remove(T key1);
  S search(T key1);
  vector<S> values();
  vector<T> keys();
  inline unsigned int size(){ return Size; };
	void* getRoot() const { return root; }; // DO NOT REMOVE
  void inorder();
};

// AVL Tree Methods go here


// private 
template<class T, class S> 
AVLTreeNode<T,S>* AVLTree<T,S>::leftRotate(AVLTreeNode<T,S>* node){
  AVLTreeNode<T,S> *rightChild = node->right;
  AVLTreeNode<T,S> *temp = ( rightChild ? rightChild->left : nullptr );

  node->right = temp;
  rightChild->left = node;

  updateHeight( node );
  updateHeight( rightChild );

  return rightChild;
}

template<class T, class S> 
AVLTreeNode<T,S>* AVLTree<T,S>::rightRotate(AVLTreeNode<T,S>* node){
  AVLTreeNode<T,S> *leftChild = node->left;
  AVLTreeNode<T,S> *temp = ( leftChild ? leftChild->right: nullptr);

  node->left = temp;
  leftChild->right = node;

  updateHeight( node );
  updateHeight(leftChild);

  return leftChild;
}
template<class T,class S> 
AVLTreeNode<T,S>* AVLTree<T,S>::updateTreeBalance(AVLTreeNode<T,S> *node){
  int factor = getFactor( node );
  if( factor > 1 ){

    if( getFactor(node->left) == 1 ){ // LL case
      return rightRotate( node );
    }
    else {  // LR case
      node->left = leftRotate( node->left );
      return rightRotate( node );
    }
  }
  else if( factor < -1 ){

    if( getFactor(node->right) == -1 ){ // RR case
      return leftRotate( node );
    }
    else{
      node->right = rightRotate( node->right );
      return leftRotate( node );
    }
  }

  return node;
}

template<class T,class S> 
AVLTreeNode<T,S>* AVLTree<T,S>::maxValueNode(AVLTreeNode<T,S> *node){
  if( !node ) return nullptr;
  if( node->right ) return maxValueNode( node->right );
  return node;
}

template<class T,class S> 
void AVLTree<T,S>::updateHeight(AVLTreeNode<T,S> *node){
  if( !node ) return;
  node->height = max( getHeight(node->left) , getHeight(node->right) )+1;
}

// public 
template<class T, class S>
AVLTree<T,S>::AVLTree(){
  root = nullptr;
  Size = 0;
}

template<class T, class S>
AVLTree<T,S>::AVLTree(const AVLTree<T,S> &other){
  if( root!=other.root ){
    root = CopyTree( other.root );
    Size = other.Size;
  }
}

template<class T, class S>
AVLTree<T,S> &AVLTree<T,S>::operator=(const AVLTree<T,S> &other){
  if( root!=other.root ){
    root=CopyTree( other.root );
    Size = other.Size;
  }
  return *this;
}

template<class T,class S>
void AVLTree<T,S>::deleteTree(AVLTreeNode<T,S> *node){
  if( node ){
    deleteTree( node->left );
    deleteTree( node->right );
    delete node;
  }
}

template<class T,class S>
AVLTree<T,S>::~AVLTree(){
  deleteTree( root );
}


template<class T, class S>
bool AVLTree<T,S>::insert(T key1, S value1){
  if( !getRoot() ){
    root = new AVLTreeNode<T,S>( key1 , value1);
    return true;
  }
  else{
    bool flag = false;
    root = insert(  key1 , value1 , root  ,flag );
    return flag;
  }
}

template<class T, class S>
AVLTreeNode<T,S>* AVLTree<T,S>::insert(T key1 ,S value1, AVLTreeNode<T,S> *node,bool &flag){
  if( !node ){
    flag = true;
    return new AVLTreeNode<T,S>( key1 ,value1 );
  }

  if( node->key < key1 ){
    node->right = insert( key1 , value1 , node->right , flag );
  }
  else if( node->key > key1 ){
    node->left = insert( key1 , value1 , node->left  , flag );
  }
  else{ // same key
    flag = false;
    return node;
  }


  updateHeight( node );
  node = updateTreeBalance( node );

  return node;
}

template<class T, class S>
bool AVLTree<T,S>::remove(T key1){
  if( !getRoot() ){
    return false;
  }

  bool flag = false;
  root=remove( key1 , root , flag );

  return flag;
}
template<class T, class S>
AVLTreeNode<T,S>* AVLTree<T,S>::remove(T key1, AVLTreeNode<T,S> *node , bool &flag ){
  if( !node ){
    return nullptr;
  }

  if( node->key > key1 ){
    node->left = remove(key1,node->left,flag);
  }
  else if( node->key < key1 ){
    node->right = remove(key1,node->right,flag);
  }
  else{
    flag = true;

    if( !node->left && !node->right ) return nullptr;
    else if( ! node->left ) return node->right;
    else if( !node->right ) return node->left;
    else{
      AVLTreeNode<T,S> *leftMax = maxValueNode( node->left );

      AVLTreeNode<T,S> *temp = node;
      // swap data
      node->value = leftMax->value;
      node->key = leftMax->value;

      leftMax->value = temp->value;
      leftMax->key = temp->key;

      node-> left = remove( key1 , node->left  , flag );
    }

    updateHeight( node );
    return updateTreeBalance( node );
  }
}

template<class T, class S>
S AVLTree<T,S>::search(T key1){
  AVLTreeNode<T,S>* cur=root;
  while(cur!=NULL){
    if(key1==cur->key){
      return cur->value;
    }
    if(key1<cur->key){
      cur=cur->left;
    }
    else{
      cur=cur->right;
    }
  }
  throw runtime_error("key is not found");
}

template<class T,class S>
AVLTreeNode<T,S>* AVLTree<T,S>::CopyTree(AVLTreeNode<T,S> *orig){
  if( ! orig ) return nullptr;

  AVLTreeNode<T,S> *node = new AVLTreeNode<T,S>( orig->key , orig->value );
  node->height = orig->height;
  node->left = CopyTree( orig->left );
  node->right= CopyTree( orig->right );
  return node;
}


template<class T,class S>
vector<T> AVLTree<T,S>::keys(){
  vector<T> result;
  buildKeys( result , root );
  return result;
}
template<class T,class S>
void AVLTree<T,S>::buildKeys( vector<T> &keys , AVLTreeNode<T,S> *node){
  if( node ){
    buildKeys( keys , node->left );
    keys.push_back( node->key );
    buildKeys( keys , node->right);
  }
}

template<class T,class S>
vector<S> AVLTree<T,S>::values(){
  vector<S> result;
  buildValues( result , root );
  return result;
}
template<class T,class S>
void AVLTree<T,S>::buildValues( vector<S> &values, AVLTreeNode<T,S> *node){
  if( node ){
    buildKeys( values , node->left );
    values.push_back( node->value );
    buildKeys( values , node->right);
  }
}

template<class T,class S>
void AVLTree<T,S>::inorder(){
  DFS( root );
  cout<<"\n";
}

template<class T , class S>
void AVLTree<T,S>::DFS(AVLTreeNode<T,S> *node){
  if( !node ) return;
  DFS( node->left );
  cout<<" ( "<<node->key<<" , "<<node->value<<" ) ";
  DFS( node->right);
}


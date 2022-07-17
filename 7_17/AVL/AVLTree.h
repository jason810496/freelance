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
	// key - node's key
	// value - node's value
	// height - node's height
  AVLTreeNode*parent;
  AVLTreeNode*left;
  AVLTreeNode*right;
  T key;
  S value;
  unsigned int height;
	// Constructors ...
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
template<class T, class S>
class AVLTree
{
private:
  AVLTreeNode<T,S>*root;
  unsigned int size;
  void left_rotate(AVLTreeNode<T,S>* node);
  void right_rotate(AVLTreeNode<T,S>* node);
	// Tree attributes go here
	// Your tree MUST have a root node named root
  // helper function recomended 

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
  unsigned int size();
	void* getRoot() const { return root; }; // DO NOT REMOVE
};

// AVL Tree Methods go here
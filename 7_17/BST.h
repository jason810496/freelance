# include <iostream>
# include <vector>
#define COUNT 10


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
  AVLTreeNode<T,S>* copy_helper(AVLTreeNode<T,S>* orig){
    if(orig!=NULL){
      AVLTreeNode<T,S>* newNode=new AVLTreeNode<T,S>(orig->key, orig->value);
      newNode->height=orig->height;
      newNode->left=copy_helper(orig->left);
      if(newNode->left!=NULL){
        newNode->left->parent=newNode;
      }
      newNode->right=copy_helper(orig->right);
      if(newNode->right!=NULL){
        newNode->right->parent=newNode;
      }
      return newNode;
    }
    return NULL;
  }
  void delete_tree_helper(AVLTreeNode<T,S>*root){
    if(root!=NULL){
      delete_tree_helper(root->left);
      delete_tree_helper(root->right);
      delete root;
    }
  }
  void values_helper(vector<S> &vec,AVLTreeNode<T,S>*root){
    if(root!=NULL){
      values_helper(vec,root->left);
      vec.push_back(root->value);
      values_helper(vec.root->right);
    }
  }

  void keys_helper(vector<T> &vec, AVLTreeNode<T,S>*root){
    if(root!=NULL){
      keys_helper(vec, root->left);
      vec.push_back(root->key);
      keys_helper(vec, root->right);
    }
  }
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
  unsigned int getsize(){return size;};
	void* getRoot() const { return root; }; // DO NOT REMOVE
  void inorder_print();
  void print2D();
};

// AVL Tree Methods go here
template<class T, class S>
AVLTree<T,S>::AVLTree(){
  root=NULL;
  size=0;
}

template<class T, class S>
AVLTree<T,S>::AVLTree(const AVLTree &other){
  if(root!=other.root){
    root=copy_helper(other.root);
    size=other.size;
  }
}

template<class T, class S>
AVLTree<T,S> &AVLTree<T,S>::operator=(const AVLTree &other){
  if(root!=other.root){
    root=copy_helper(other.root);
    size=other.size;
  }
  return *this;
}

template<class T, class S>
bool AVLTree<T,S>::insert(T key1, S value1){
  AVLTreeNode<T,S>* cur=root;
  AVLTreeNode<T,S>* cur_parent;
  if(root==NULL){
    root=new AVLTreeNode<T,S>(key1, value1);
    return true;
  }
  while(cur!=NULL){
    if(key1==cur->key){
      return false;
    }
    if(key1>cur->key){
      cur_parent=cur;
      cur=cur->right;
    }
    else{
      cur_parent=cur;

      cur=cur->left;
    }
  }
  if(key1<cur_parent->key){
    cur_parent->left=new AVLTreeNode<T,S>(key1, value1);
  }
  else{
    //cout<<key1<<">"<<cur_parent->key<<endl;
    cur_parent->right=new AVLTreeNode<T,S>(key1, value1);
  }
  size++;
  return true;
}

template<class T, class S>
bool AVLTree<T,S>::remove(T key1){
  AVLTreeNode<T,S>* cur=root;
  while(cur->key!=key1){
    if(cur==NULL){
      return false;
    }
    if(key1>cur->key){
      cur=cur->right;
    }
    else{
      cur=cur->left;
    }
  }
  if(cur->right==NULL&cur->left==NULL){
    if(cur==root){
      root=NULL;
      delete cur;
    }
    else{
      if(cur==cur->parent->right){
        cur->parent->right=NULL;
        delete cur;
      }
      else{
        cur->parent->left=NULL;
        delete cur;
      }
    }
  }
  else{
    if(cur->right!=NULL){
      while(cur->right!=NULL){
        cur->key=cur->right->key;
        cur->value=cur->right->value;
        cur=cur->right;
      }
      cur->parent->right=NULL;
      delete cur;
    }
    else{
      while(cur->left!=NULL){
        cur->key=cur->left->key;
        cur->value=cur->left->value;
        cur=cur->left;
      }
      cur->parent->left=NULL;
      delete cur;
    }
  }
  return true;
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

template<class T, class S>
AVLTree<T,S>::~AVLTree(){
  delete root;
}

template<class T, class S>
void inorder_helper(AVLTreeNode<T,S>* root){
  if(root){
    inorder_helper(root->left);
    cout<<root->key;
    inorder_helper(root->right);
  }
}

template<class T, class S>
void AVLTree<T,S>::inorder_print(){
  inorder_helper(root);
}


template<class T, class S>
vector<S> AVLTree<T,S>::values(){
  vector<S> vec;
  if(root!=NULL){
    values_helper(vec, root);
  }
  return vec;
}

template<class T, class S>
vector<T> AVLTree<T,S>::keys(){
  vector<T> vec;
  if(root!=NULL){
    keys_helper(vec, root);
  }
  return vec;
}




template<class T, class S>
void print2DUtil(AVLTreeNode<T,S> *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}

template<class T, class S>
void AVLTree<T,S>:: print2D()
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm> // For Test
// #include <random>    // For Test


#include<bits/stdc++.h>
struct IStringDatabase {
    virtual void Add(const std::string&) = 0;
    virtual bool Remove(const std::string&) = 0;
    virtual std::vector<std::string> StartsWith(const std::string& prefix) = 0;
    virtual ~IStringDatabase() {}
};

// [YOUR CODE WILL BE PLACED HERE] 



// [YOUR CODE WILL BE PLACED HERE]
#include<bits/stdc++.h>
#define UMap std::unordered_map
#define F first 
#define S second
#define AAA 65
/*
    Trie: Prefix Tree
    Application : words auto-complete using Trie
*/
struct node{
    bool isEnd = false;
    // node *child[Alphabet_Size];
    UMap<int,node*> child;
    node(){
        isEnd = false;
        // for(int i=0;i<Alphabet_Size;i++) child[i]=nullptr;
    };
};

class StringDatabase : public IStringDatabase
{

    node *root = new node();

public :
	void Add(const std::string&) ;
	bool Remove(const std::string&) ;
	std::vector<std::string> StartsWith(const std::string& prefix) ;
	~StringDatabase();

    // void Insert(node *rt,const std::string &str);
    // std::vector< std::string> Search(node *rt,const std::string &str);

    // bool check(const std::string&){};
};




void Insert(node *rt,const std::string &str){
    node *temp = rt;

    for(char ch :str ){
        int index= ch-AAA;

        if(temp->child[index]==nullptr){
            temp->child[index]=new node;
        }

        temp= temp->child[index];
    }

    temp->isEnd = true;

    // std::cout<<"Insert\n";
}

void DFS(node *rt, std::string &cur, std::vector< std::string> &ans){
    // std::cout<<"dd\n";
    
    if( rt==nullptr ) return;
    if( rt->isEnd ){
        ans.push_back( cur );
        // std::cout<<cur<<'\n';
        // return ;
    }

    // for(int i=0;i<Alphabet_Size;i++){
    for(auto &it:rt->child){
        if( it.S ){
            // cur.push_back( char(i) );
            cur+=char(it.F+AAA);
            DFS( it.S ,cur,ans );
            cur.pop_back();
        }
    }
    
}


bool check(node *root,const std::string &word){
    node *temp= root;

    for(char ch: word){
        int index=ch-AAA;

        if(temp->child[index]==nullptr) return false;

        temp= temp->child[index];
    }

    return temp->isEnd;
}

std::vector<std::string> Search(node *rt,const std::string &str){

    std::vector< std::string > ans;

    node *temp= rt;

    for(char ch: str){
        int index=ch-AAA;

        if(temp->child[index]==nullptr) return ans;

        temp= temp->child[index];
    }

    std::string word =str;

    DFS( temp ,word,ans);

    return ans ;
}

void StringDatabase::Add(const std::string& a ){
    // if( check(root,a) ) return;

    Insert(root,a);
}

bool isEmpty(node *rt){
    return rt->child.empty();
}

node* Delete(node *root , const std::string &str,int dep=0){
    if( !root ) return nullptr;
    if( dep == str.size() ){

        if( root->isEnd) root->isEnd=false;
        if( isEmpty( root ) ){
            delete root;
            root=nullptr;
        }

        return root;
    }

    int idx = str[ dep ]-AAA;

    root->child[ idx ] = Delete( root->child[ idx ] , str , dep+1 );

    if( isEmpty(root) && !root->isEnd ){
        delete root;
        root = nullptr;
    }

    return root;
}

bool StringDatabase::Remove(const std::string& a )
{
	root=Delete(root,a);
}

std::vector<std::string> StringDatabase::StartsWith(const std::string& prefix){
    return Search(root,prefix);
}

StringDatabase::~StringDatabase()
{
}



// [YOUR CODE WILL BE PLACED HERE] 

void Test1(); // Sample1
void Test2(); // Add, StartsWith
void Test3(); // Add, StartsWith
void Test4(); // Add, StartsWith
void Test5(); // All
void Test6(); // All
void Test7(); // All

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int id;
    std::cin >> id;
    void (*f[])() = { Test1, Test2, Test3, Test4, Test5, Test6, Test7};
    f[id-1]();
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << '[';
    if (v.size() > 0) {
        os << v[0];
        for (size_t i = 1; i < v.size(); ++i) {
            os << ", " << v[i];
        }
    }
    return os << ']';
}

namespace Feis {}

void Test1() {
    IStringDatabase&& db = StringDatabase();
    db.Add("Helloworld");
    db.Add("HelloWorld");
    db.Add("Hello");
    db.Add("Helloworld");
    db.Add("Hello");
    db.Add("Hi");

    std::cout << "01) " << db.StartsWith("Hello") << std::endl;
    std::cout << "02) " << db.StartsWith("hello") << std::endl;
    std::cout << "03) " << db.StartsWith("H") << std::endl;

    db.Remove("Helloworld");
    db.Remove("Hi");
    std::cout << "04) " << db.StartsWith("H") << std::endl;
}

void Test2() {
    IStringDatabase&& db = StringDatabase();
    db.Add("add");
    db.Add("aabb");
    db.Add("akeee");
    db.Add("aabbccccccc");
    db.Add("aabbccc");
    db.Add("aa");

    std::cout << "01) " << db.StartsWith("aa") << std::endl;
    std::cout << "02) " << db.StartsWith("aab") << std::endl;
    std::cout << "03) " << db.StartsWith("aabbcccc") << std::endl;

    db.Remove("aa");
    db.Remove("add");
    std::cout << "04) " << db.StartsWith("a") << std::endl;

}
void Test3() {}
void Test4() {}
void Test5() {}
void Test6() {}
void Test7() {}
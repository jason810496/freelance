


// ----------------------------------------------
#include<bits/stdc++.h>

struct IStringDatabase {
    virtual void Add(const std::string&) = 0;
    virtual bool Remove(const std::string&) = 0;
    virtual std::vector<std::string> StartsWith(const std::string& prefix) = 0;
    virtual ~IStringDatabase() {}
};

// ---------------------------------------------

// [YOUR CODE WILL BE PLACED HERE]
#define Alphabet_Size 60
/*
    Trie: Prefix Tree
    Application : words auto-complete using Trie
*/
struct node{
    bool is_end;
    int cnt;
    node *child[Alphabet_Size];
    node(){
        is_end=false;
        cnt=0;
        for(int i=0;i<Alphabet_Size;i++) child[i]=nullptr;
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

    void Insert(node *rt,const std::string &str);
    std::vector< std::string> Search(node *rt,const std::string &str);

};



// ----------------------------------------

void Insert(node *rt,const std::string &str){
    node *temp = rt;

    for(char ch :str ){
        int index= ch-'a';

        if(temp->child[index]==nullptr){
            temp->child[index]=new node;
        }

        temp= temp->child[index];
    }

    temp->is_end= true;
}

void DFS(node *rt, std::string &cur, std::vector< std::string> &ans){
    if( rt->is_end ){
        ans.push_back( cur );
    }

    for(int i=0;i<Alphabet_Size;i++){
        if( rt->child[i] ){
            cur.push_back( char(i) );
            DFS(rt->child[i] ,cur,ans );
            cur.pop_back();
        }
    }

}

std::vector<std::string> Search(node *rt,const std::string &str){
    node *temp = rt;

    bool flag = true ; 
    for(char ch:str){
        int idx = ch='a';
        if( temp->child[ idx ]==nullptr ){
            flag = false;
        }
        temp = temp->child[ idx ];
    }

    

    std::vector< std::string > ans;

    if( !flag ) return ans ;

    std::string word = str;

    DFS(temp,word,ans);

    return ans ;
}

void StringDatabase::Add(const std::string& a ){
    Insert(root,a);
}

bool StringDatabase::Remove(const std::string& a )
{
	
}

std::vector<std::string> StringDatabase::StartsWith(const std::string& prefix){
    return Search(root,prefix);
}

StringDatabase::~StringDatabase()
{
}



// =============================


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

int main(){

    StringDatabase db;
    db.Add("Helloworld");
    db.Add("HelloWorld");
    db.Add("Hello");
    db.Add("Helloworld");
    db.Add("Hello");
    db.Add("Hi");

    std::cout << "01) " << db.StartsWith("Hello") << std::endl;
    std::cout << "02) " << db.StartsWith("hello") << std::endl;
    std::cout << "03) " << db.StartsWith("H") << std::endl;

    return 0;
}
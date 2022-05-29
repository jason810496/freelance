


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

    // void Insert(node *rt,const std::string &str);
    // std::vector< std::string> Search(node *rt,const std::string &str);

    // bool check(const std::string&){};
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

    // std::cout<<"Insert\n";
}

void DFS(node *rt, std::string &cur, std::vector< std::string> &ans){
    std::cout<<"dd\n";
    
    if( rt==nullptr ) return;
    if( rt->is_end ){
        ans.push_back( cur );
        std::cout<<cur<<'\n';
        // return ;
    }

    for(int i=0;i<Alphabet_Size;i++){
        if( rt->child[i] ){
            // cur.push_back( char(i) );
            cur+=char(i);
            DFS(rt->child[i] ,cur,ans );
            cur.pop_back();
        }
    }
    
}


bool check(node *root,const std::string &word){
    node *temp= root;

    for(char ch: word){
        int index=ch-'a';

        if(temp->child[index]==nullptr) return false;

        temp= temp->child[index];
    }

    return temp->is_end;
}

node *check2(node *root,const std::string &word){
    node *temp= root;

    for(char ch: word){
        int index=ch-'a';

        if(temp->child[index]==nullptr) return nullptr;

        temp= temp->child[index];
    }

    return temp;
}

std::vector<std::string> Search(node *rt,const std::string &str){
    node *temp = rt;

    std::cout<<"s "<<str<<"\n";

    std::cout<<"search"<<( check(temp,str) ? " YES \n": "NO\n");
    // std::cout<<"search"<<( check(temp,str) ? " YES \n": "NO\n");

    // bool flag = false ; 
    // for(char ch:str){
    //     int idx = ch='a';
    //     if( temp->child[ idx ]==nullptr ){
    //         flag = true;
    //         break;
    //     }
    //     temp = temp->child[ idx ];
    // }

    // std::cout<<"ss "<<flag<<"\n";

    std::vector< std::string > ans;

    // if( flag ) return ans ;

    // if( temp ) std::cout<<"OK\n";

    std::cout<<"aa\n";

    std::string word = str;

    DFS( check2( rt , str ) ,word,ans);

    return ans ;
}

void StringDatabase::Add(const std::string& a ){
    if( check(root,a) ) return;
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
    db.Add("adb");
    db.Add("akc");
    db.Add("arr");
    db.Add("a");
    db.Add("add");

    // std::cout << "01) " << db.StartsWith("Hello") << std::endl;
    // std::cout << "02) " << db.StartsWith("hello") << std::endl;
    // std::cout << "03) " << db.StartsWith("H") << std::endl;

    std::cout << "01) " << db.StartsWith("Hello") << std::endl;
    std::cout << "02) " << db.StartsWith("hello") << std::endl;
    std::cout << "03) " << db.StartsWith("H") << std::endl;
    std::cout << "03) " << db.StartsWith("add") << std::endl;
    std::cout << "03) " << db.StartsWith("arr") << std::endl;
    std::cout << "03) " << db.StartsWith("akc") << std::endl;
    std::cout << "03) " << db.StartsWith("a") << std::endl;

    return 0;
}
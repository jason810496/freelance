


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

struct Node{
    Node *child[100];
    bool isEnd = false;
};

struct Node *NewNode(){
    struct Node *ret = new Node;
    ret->isEnd = false;

    for(int i=0;i<100;i++){
        ret->child[i]= nullptr;
    }
    return ret;
}

class StringDatabase : public IStringDatabase
{
	//std::list<std::string> _list ;
	// std::vector<std::string> _vec ;

    Node *root = NewNode();


public :
	void Add(const std::string&) ;
	bool Remove(const std::string&) ;
	std::vector<std::string> StartsWith(const std::string& prefix) ;
	~StringDatabase();

    void Insert(struct Node*rt ,const std::string &str);
};



// ----------------------------------------

void Insert(struct Node*rt ,const std::string &str){
    struct Node *temp = rt;

    for(char c : str){
        int idx = c-'a';
        if( !temp->child[ idx ] ) temp->child[ idx ] = NewNode();
        
        temp = temp->child[ idx ];
    }

    temp->isEnd = true;

}

std::vector<std::string> Search( struct Node*rt ,const std::string &str){
    struct Node *temp = rt;

    for(char c : str){
        int idx = c-'a';
        if( !temp->child[ idx ] ) temp->child[ idx ] = NewNode();
        
        temp = temp->child[ idx ];
    }

    temp->isEnd = true;
}

void StringDatabase::Add(const std::string& a )
{
	Insert( root , a);

}

bool StringDatabase::Remove(const std::string& a )
{
	// 是否重複
	int left , ret ;
	ret = binary_search( _vec , 0 , _vec.size() - 1 , a , left );
	if( ret == -1 )
		return 0 ;
	_vec.erase(  _vec.begin() + ret );
	return 1 ;
}

std::vector<std::string> StringDatabase::StartsWith(const std::string& prefix)
{
	std::vector<std::string> ret ;
	// 是否重複
	int left  ;
	int k ; 
	binary_search( _vec , 0 , _vec.size() - 1 , prefix , left );
	for( ; left < _vec.size() ; ++left )
	{
		const std::string &ss = _vec[left] ;

		if( strstr( ss.c_str() , prefix.c_str() ) != NULL )
			ret.push_back( ss );
		else
			break ;

		
	}

	return ret ; 


}

StringDatabase::~StringDatabase()
{
}

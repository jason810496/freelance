


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

    std::vector< Node > Child(60);
    bool isEnd=false , has=false;

    Node(){
        Child.resize(60);
        isEnd = false;
        has = false;
    }
}

class StringDatabase : public IStringDatabase
{
	//std::list<std::string> _list ;
	// std::vector<std::string> _vec ;

    Node root;

public :
	void Add(const std::string&) ;
	bool Remove(const std::string&) ;
	std::vector<std::string> StartsWith(const std::string& prefix) ;
	~StringDatabase();

    void Insert(struct Node*rt ,const std::string &str);
};



// ----------------------------------------



std::vector<std::string> Search( struct Node*rt ,const std::string &str){
    struct Node *temp = rt;

    
}

void StringDatabase::Add(const std::string& a )
{
   

}

bool StringDatabase::Remove(const std::string& a )
{
	
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

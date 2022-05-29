
// [YOUR CODE WILL BE PLACED HERE] 
// --------------------------------------------------------------------------------------------
#include <list>
class Node ;

class Node
{
public :
	int _isRun ;
	std::string _name ;
	std::list<Node*> _to ;
	Node * _from ;
public :
	// add
	void addNode( Node *node );
	bool find(Node* node) const ;
	Node( const std::string &name );
	//
	bool IsConnected( Node* to )const ;

	void insert(  Node * node );


};

bool Node::find(Node* node) const
{
	std::list<Node*>::const_iterator it ;
	for( it = _to.begin() ; it != _to.end() ; it ++ )
		if( (*it) == node )
			return 1 ;
	return 0 ;

}

void Node::insert(  Node * node )
{
	const std::string &name = node->_name ;
	std::list<Node*>::const_iterator it ;
	for( it = _to.begin() ; it != _to.end() ; it ++ )
	{
		if( (*it)->_name > name )
		{
			_to.insert( it , node );
			return ;
		}
	}
	_to.push_back( node );
}
//
bool Node::IsConnected( Node* to )const
{
	for( const Node* d : _to )
		if( to == d )
			return true ;
	return false; 
}

Node::Node( const std::string &name )
{
	_name = name ;
}

void Node::addNode( Node *node )
{
	insert( node );
}

class Metro : public IMetro
{
private :
	std::list<Node*> _node ;
	int _count ;
private :
	Node* findAndNew( const std::string name );
public:
	void AddConnection(std::string station_name_a, std::string station_name_b) override;
	bool IsConnected(std::string station_name_a, std::string station_name_b) override;
	bool HasPath(std::string station_name_a, std::string station_name_b) override;
	std::vector<std::string> ShortestPath(std::string station_name_a, std::string station_name_b) override;
	~Metro() override;
	Metro();

};
Metro::Metro()
{
	_count = 0 ;
}
Node* Metro::findAndNew( const std::string name )
{
	std::list<Node*>::const_iterator it ;
	for( it = _node.begin() ; it != _node.end() ; it ++ )
		if( (*it)->_name == name )
			return (*it);
	Node* nn = new Node( name );
	_node.push_back( nn );
	_count ++ ; 
	return nn ; 

}

void Metro::AddConnection(std::string station_name_a, std::string station_name_b)
{
	Node *a = findAndNew( station_name_a );
	Node *b = findAndNew( station_name_b );
	if( a->find( b ))
		return ;
	a->addNode( b );
	b->addNode( a );
}

bool Metro::IsConnected(std::string station_name_a, std::string station_name_b)
{
	Node *a = findAndNew( station_name_a );
	if( a == NULL ) return false ; 
	Node *b = findAndNew( station_name_b );
	if( b == NULL ) return false ; 
	return a->IsConnected( b );
	/*
	std::list<Node*>::iterator it ;
	for( it = _node.begin() ; it != _node.end() ; it ++ )
		(*it)->_isRun = 0 ;*/


}


bool BFS( Node *from , Node *to , std::vector<std::string> *out )
{
	int i , k ;
	Node * findNode ;
	Node * nn = NULL ;
	std::vector<Node*> buf ;
	buf.push_back( to );
	to->_isRun = 1 ;
	to->_from = NULL ;

	if( to == from )
	{
		if( out != NULL )
			out->push_back( to->_name );
		return true ;
	}
	
	findNode = 0 ;
	for( i = 0 ; i < buf.size() ; ++i )
	{
		nn = buf[i] ;
		for( Node *next : nn->_to )
		{
			if( next->_isRun == 0 )
			{
				next->_isRun = 1 ;
				next->_from = nn ;
				buf.push_back( next );
				if( from == next )
				{
					findNode = next ;
					break ;
				}
			}
		}
		if( findNode != NULL ) break ;

	}
	if( findNode == NULL  )
		return 0 ;
	//
	if( out != NULL )
	{
		nn = findNode ;
		while( nn != NULL )
		{
			out->push_back( nn->_name );
			nn = nn->_from ;
		}

	}

	return 1 ; 
	
}



bool Metro::HasPath(std::string station_name_a, std::string station_name_b)
{
	Node *a = findAndNew( station_name_a );
	if( a == NULL ) return false ; 
	Node *b = findAndNew( station_name_b );
	if( b == NULL ) return false ; 

	std::list<Node*>::iterator it ;
	for( it = _node.begin() ; it != _node.end() ; it ++ )
		(*it)->_isRun = 0 ;

	return BFS( a , b , NULL );
}

std::vector<std::string> Metro::ShortestPath(std::string station_name_a, std::string station_name_b)
{
	std::vector<std::string> ret ; 
	Node *a = findAndNew( station_name_a );
	if( a == NULL ) return ret ; 
	Node *b = findAndNew( station_name_b );
	if( b == NULL ) return ret ;


	std::list<Node*>::iterator it ;
	for( it = _node.begin() ; it != _node.end() ; it ++ )
		(*it)->_isRun = 0 ;


	BFS( a , b , &ret );
	return ret ;

}

Metro::~Metro()
{
}
// --------------------------------------------------------------------------------------------

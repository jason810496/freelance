
// [YOUR CODE WILL BE PLACED HERE]

#include <string.h>
#include <list>
class StringDatabase : public IStringDatabase
{
	//std::list<std::string> _list ;
	std::vector<std::string> _vec ;
public :
	void Add(const std::string&) ;
	bool Remove(const std::string&) ;
	std::vector<std::string> StartsWith(const std::string& prefix) ;
	~StringDatabase();
};



// ----------------------------------------
// 二次
int binary_search(const std::vector<std::string> & arr , int start, int end, const std::string & key , int &outLeft  )
{
	int ret = -1;  

	int mid = 0 ;
	while (start <= end) 
	{
		mid = start + (end - start) / 2; 
		if ( (arr[mid] )< key)
			start = mid + 1;
		else if ((arr[mid] )> key)
			end = mid - 1;
		else { 
			ret = mid;  
			break;
		}
	}

	outLeft = mid ;


	return ret ;     
}
void StringDatabase::Add(const std::string& a )
{
	// 是否重複
	int left , ret ;
	if( _vec.size() == 0 )
	{
		_vec.push_back( a );
		return ; 
	}
	ret = binary_search( _vec , 0 , _vec.size() - 1 , a , left );
	if( ret != -1 )
		return ;
	if( left >= 0 )
	if( left < ( _vec.size() )) 
	if( _vec[left] <= a)
	{
		left++;
	}
	_vec.insert( _vec.begin() + left , a );

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

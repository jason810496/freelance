

// --------------------------------------------------------------------------------------------
#include<bits/stdc++.h>


struct IMetro {
    virtual void AddConnection(std::string station_name_a, std::string station_name_b) = 0;
    virtual bool IsConnected(std::string station_name_a, std::string station_name_b) = 0;
    virtual bool HasPath(std::string station_name_a, std::string station_name_b) = 0;
    virtual std::vector<std::string> ShortestPath(std::string station_name_a, std::string station_name_b) = 0;
    virtual ~IMetro() {}
};


// [YOUR CODE WILL BE PLACED HERE] 



#include<bits/stdc++.h>
#define Vec std::vector
#define Str std::string 
#define Set std::set
#define UMap std::unordered_map
#define pii std::pair<int,int>
#define F first 
#define S second 

class Metro : public IMetro{
    private :
        UMap< Str , int> Mp;
        UMap< int ,Str > Mp_T;
        // UMap< int ,Vec<int> > Graph;
        // UMap< int ,int > GroupID;
        // UMap<int,Set<int> > Connection;
        // std::bitset<100005> vis=0;

        Vec<Vec<int> > Graph;
        Vec<int> GroupID;
        Vec<bool> vis;
        Vec<pii> Edge;
        int G_ID=1;
        int N;
        int cnt=0;
        bool flag=false;

    public:
        void AddConnection(std::string station_name_a, std::string station_name_b) override;
        bool IsConnected(std::string station_name_a, std::string station_name_b) override;
        bool HasPath(std::string station_name_a, std::string station_name_b) override;
        std::vector<std::string> ShortestPath(std::string station_name_a, std::string station_name_b) override;
        ~Metro() override;
        Metro(){
        }

        inline int GetCode(const Str &s){

            if( Mp.find(s)==Mp.end() ){
                Mp[ s ]=cnt;
                Mp_T[ cnt ] = s;
                cnt++;
            }

            return Mp[ s ];
        }

        void DFS(int cur){
            vis[ cur ]=1;
            GroupID[ cur ] = G_ID;

            for(int nxt : Graph[ cur ] ){
                if( !vis[nxt] ) DFS( nxt );
            }
        }

        void Init(){
            flag = true;
            N = Mp.size();

            Graph.resize( N , Vec<int>(N,0) );
            vis.resize( N , 0 );
            GroupID.resize( N );

            for(pii &i:Edge){
                Graph[i.F].push_back( i.S );
                Graph[i.S].push_back( i.F );
            }

            for(int i=0;i<N;i++){
                if( !vis[i] ){
                    DFS(i);
                    G_ID++;
                }
            }

            for(int i=0;i<N;i++){
                std::cout<<i<<' '<<GroupID[i]<<'\n';
            }
        }

};


void Metro::AddConnection(std::string station_name_a, std::string station_name_b)
{
	int a=GetCode( station_name_a)  ,b=GetCode( station_name_b);
    if( a>b) std::swap(a,b);

    Edge.push_back( {a,b} );
}

bool Metro::IsConnected(std::string station_name_a, std::string station_name_b){
    if( !flag ){
        Init();
    }

    int a=GetCode( station_name_a) , b=GetCode( station_name_b);
    if( a>b) std::swap(a,b);


    for(int nxt :Graph[a] ){
        if( nxt==b ) return true;
    }
    return false;
}


bool Metro::HasPath(std::string station_name_a, std::string station_name_b){
    if( !flag ){
        Init();
    }

    int a=GetCode( station_name_a) , b=GetCode( station_name_b);
    if( a>b) std::swap(a,b);

    return GroupID[ a ]==GroupID[ b ];
}

Vec<Str> Metro::ShortestPath(std::string station_name_a, std::string station_name_b)
{
	Vec<Str> ans;
    

    int a=GetCode( station_name_a) , b=GetCode( station_name_b);
    if( a>b) std::swap(a,b);

    if( !HasPath( station_name_a, station_name_b) ) return ans;

    Vec<bool> V(N);
    Vec<int> From(N);
    bool flag = false;

    std::queue<int> q;
    q.push(a);
    From[a]=-1;
    V[a] = 1;
    
    

    while( q.size() ){
        int cur = q.front();
        q.pop();

        if( cur == b ){
            flag = true;
            break;
        }

        for(int nxt : Graph[ cur ] ){
            if( !V[nxt] ){
                q.push( nxt );
                From[ nxt ] = cur ;
                V[ nxt ] =1 ;
            }
        }
    }

    int f = b;
    if( flag ){
        while( f >0 ){
            ans.push_back( Mp_T[ f] );
        }
    }

    return ans;
}

Metro::~Metro()
{
}
// --------------------------------------------------------------------------------------------

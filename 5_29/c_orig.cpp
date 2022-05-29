

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




#define Vec std::vector
#define Str std::string 
#define Set std::set
#define UMap std::unordered_map
#define pii std::pair<int,int>

class Metro : public IMetro{
    private :
        UMap< Str , int> Mp;
        UMap< int ,Vec<int> > Graph;
        UMap< int ,int > GroupID;
        std::bitset<100005> vis=0;
        UMap<int,Set<int> > Connection;
        Vec<pii> Edge;
        int G_ID=1;
        int G_Size;
        int cnt=0;
        bool flag;

    public:
        void AddConnection(std::string station_name_a, std::string station_name_b) override;
        bool IsConnected(std::string station_name_a, std::string station_name_b) override;
        bool HasPath(std::string station_name_a, std::string station_name_b) override;
        std::vector<std::string> ShortestPath(std::string station_name_a, std::string station_name_b) override;
        ~Metro() override;
        Metro(){
        }

        inline int GetCode(const Str &s){

            if( Mp.find(s)==Mp.end() ) Mp[ s ]=cnt++;

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

        }

};


void Metro::AddConnection(std::string station_name_a, std::string station_name_b)
{
	int a=GetCode( station_name_a)  ,b=GetCode( station_name_b);
    if( a>b) std::swap(a,b);

    Graph[a].push_back(b);
    Graph[b].push_back(a);

    Connection[a].insert(b);
}

bool Metro::IsConnected(std::string station_name_a, std::string station_name_b)
{
    int a=GetCode( station_name_a) , b=GetCode( station_name_b);
    if( a>b) std::swap(a,b);

    return Connection[a].find(b)!=Connection[a].end();
}


bool Metro::HasPath(std::string station_name_a, std::string station_name_b){
    int a=GetCode( station_name_a) , b=GetCode( station_name_b);
    if( a>b) std::swap(a,b);

    if( !vis[a] || !vis[b]){
        G_Size = Mp.size();

        for(int i=0;i<G_Size;i++){
            DFS(i);
            G_ID++;
        }
    }

    return GroupID[ a ]==GroupID[ b ];
}

Vec<Str> Metro::ShortestPath(std::string station_name_a, std::string station_name_b)
{
	Vec<Str> temp;
    return temp;
}

Metro::~Metro()
{
}
// --------------------------------------------------------------------------------------------

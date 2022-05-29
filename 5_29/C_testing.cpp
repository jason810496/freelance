#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random> // For Test

struct IMetro {
    virtual void AddConnection(std::string station_name_a, std::string station_name_b) = 0;
    virtual bool IsConnected(std::string station_name_a, std::string station_name_b) = 0;
    virtual bool HasPath(std::string station_name_a, std::string station_name_b) = 0;
    virtual std::vector<std::string> ShortestPath(std::string station_name_a, std::string station_name_b) = 0;
    virtual ~IMetro() {}
};

// [YOUR CODE WILL BE PLACED HERE] 


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
        // UMap< int ,Vec<int> > Graph;
        // UMap< int ,int > GroupID;
        // UMap<int,Set<int> > Connection;
        // std::bitset<100005> vis=0;

        Vec<Vec<int> > Graph;
        Vec<int> GroupID;
        Vec<bool> vis;
        Vec<pii> Edge;
        int G_ID=1;
        int N=1005;
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
            flag = true;
            // N = Mp.size();

            Graph.resize( N );
            vis.resize( N );
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
	Vec<Str> temp;
    return temp;
}

Metro::~Metro()
{
}
// ---------------------------------------------------------------------
// [YOUR CODE WILL BE PLACED HERE] 

void Dump(const std::vector<std::string>&);

void Test1(); // Sample1
void Test2(); // AddConnection, IsConnected 
void Test3(); // AddConnection, IsConnected 
void Test4(); // AddConnection, HasPath 
void Test5(); // AddConnection, HasPath
void Test6(); // AddConnection, ShortestPath 
void Test7(); // AddConnection, ShortestPath

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int id;
    std::cin >> id;
    void (*f[])() = { Test1, Test2, Test3, Test4, Test5, Test6, Test7};
    f[id-1]();
}

void Dump(const std::vector<std::string>& path) {
    bool isFirst = true;
    for (const std::string& s : path) {
        if (!isFirst) {
            std::cout << " -> ";
        } else {
            isFirst = false;
        }
        std::cout << s;
    }
    std::cout << std::endl;
}

namespace Feis {}

void Test1() {
    Metro m;
    m.AddConnection("TaipeiMainStation", "ShandoTemple");
    m.AddConnection("TaipeiMainStation", "Zhongshan");
    m.AddConnection("TaipeiMainStation", "Ximen");
    m.AddConnection("Shuanglian", "Zhongshan");
    m.AddConnection("Beimen", "Zhongshan");
    m.AddConnection("Beimen", "Ximen");
    m.AddConnection("MinquanWRd", "Shuanglian");
    m.AddConnection("MinquanWRd", "Yuanshan");
    m.AddConnection("MinquanWRd", "ZhongshangElementarySchool");
    m.AddConnection("XingtianTample", "ZhongshangElementarySchool");
    m.AddConnection("XingtianTample", "SongjianNanjing");
    m.AddConnection("ZhongxiaoXinsheng", "SongjianNanjing");
    m.AddConnection("ZhongxiaoXinsheng", "Dongmen");
    m.AddConnection("ShandoTemple", "ZhongxiaoXinsheng");
    m.AddConnection("ZhongxiaoXinsheng", "ZhongxiaoFuxing");
    m.AddConnection("ZhongxiaoFuxing", "SunYat-SenMemorialHall");
    m.AddConnection("SunYatSenMemorialHall", "TaipeiCityHall");
    m.AddConnection("TaipeiCityHall", "Yongchun");
    m.AddConnection("Yongchun", "Houshanpi");
    m.AddConnection("Houshanpi", "Kunyang");
    m.AddConnection("Kunyang", "Nanggong");

    std::cout << "01) " << std::boolalpha << m.IsConnected("TaipeiMainStation", "Ximen") << std::endl;

    std::cout << "02) " << std::boolalpha << m.IsConnected("TaipeiMainStation", "Beimen") << std::endl;

    std::cout << "03) " << std::boolalpha << m.IsConnected("TaipeiMainStation", "TaipeiMainStation") << std::endl;

    std::cout << "04) " << std::boolalpha << m.HasPath("TaipeiMainStation", "Beimen") << std::endl;

    std::cout << "05) " << std::boolalpha << m.HasPath("TaipeiMainStation", "FuJenUniversity") << std::endl;

    std::cout << "06) " << std::boolalpha << m.HasPath("TaipeiMainStation", "TaipeiMainStation") << std::endl;

    std::cout << "07) ";
    Dump(m.ShortestPath("TaipeiMainStation", "TaipeiCityHall"));

    std::cout << "08) ";
    Dump(m.ShortestPath("TaipeiMainStation", "Nanggong"));

    std::cout << "09) ";
    Dump(m.ShortestPath("TaipeiMainStation", "SongjianNanjing"));

    m.AddConnection("Zhongshan", "SongjianNanjing");

    std::cout << "10) ";
    Dump(m.ShortestPath("TaipeiMainStation", "SongjianNanjing"));

    std::cout << "11) ";
    Dump(m.ShortestPath("TaipeiMainStation", "Beimen"));
}

void Test2() {}
void Test3() {}
void Test4() {}
void Test5() {}
void Test6() {}
void Test7() {}

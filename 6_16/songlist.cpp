#include<bits/stdc++.h>
using namespace std;
/*********************************
    Input : sonlist.csv favorite.csv 
    Output: sonlist.csv favorite.csv ( updated )

*********************************/


/*********************************
   string : name  , singer
   uint32 : len
   bool : favorite
    
*********************************/
struct Song{
    string name,singer;
    unsigned int len;
    bool favorite;

    Song(string n,string s,unsigned int l,bool f){
        name = n;
        singer = s;
        len = l;
        favorite = f;
    };

};

/*********************************
    function :
        Add
        Delete
            - by song name
            - by singer name
        Modify
            - by song name
        Search
            - by song name
            - by singer name
            - by len
        Favorite
            - With multi list
            - Add to favorite
            - search by list name

*********************************/
class Table{
    private:
        // Raw Data sort by len
        vector<Song> Data;
        // Store id that is deleted
        unordered_set<int>  Deleted_ID;
        // hashmap : singer->ID
        unordered_map< string , vector<int> > Singer_ID;
        // hashmap : name->ID
        unordered_map< string , int > Name_ID; 
        // hashmap : list name-> { id }
        unordered_map< string , unordered_set<int> > Favorite_List; 
    public:
        void Read_songlist();
        
};

// read raw data
void Table::Read_songlist(){
    fstream fin;
    fin.open("songlist.csv" , ios::in );

    string line ,temp , str;
    vector<string> row;

    while( getline(fin,line) ){
        row.clear();
        cout<<"Line : "<<line<<"\n";
        int last=0;
        for(int i=0;i<line.size();i++){
            if( line[i]==',' ){
                row.push_back( line.substr(last,i-last) );
                last=i;
                i++;
            }
        }
        row.push_back( line.substr(last) );

        for(auto i:row ){
            cout<<i<<" | ";
        }
        cout<<"\n";
    }
}


int main(){

    Table table;
    table.Read_songlist();

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
/*********************************
    Input : sonlist.csv 
    Output: sonlist.csv favorite.csv ( updated )

*********************************/

typedef unsigned int uint32;
/*********************************
   string : name  , singer
   uint32 : len
   bool : favorite
    
*********************************/
struct Song{
    string name,singer;
    uint32 len;
    bool favorite;

    Song(string n,string s,uint32 l,bool f){
        name = n;
        singer = s;
        len = l;
        favorite = f;
    };

};


#define ADD 1
#define DELETE 2
#define MODIFY 3
#define SEARCH 4
#define FAV_ADD 5
#define FAV_SEARCH 6
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

    /*****************************
        Data organize in different property
    *****************************/
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

    /*****************************
        User INterface of different functions
    *****************************/
        void UI_Add();
        // Delete song
        void UI_Delete();
        // Modify song
        void UI_Modify();
        // Search song ( by name , by singer )
        void UI_Search();
        // Add to Favorite
        void UI_Fav_Add();
        // Search Favorite list
        void UI_Fav_Serach();

    public:

    /*****************************
        Preprocess
    *****************************/
        // Input csv file
        void Read_Data();
        // Sort table
        void Sort();

    /*****************************
        Functions
    *****************************/
        // Add new song
        void Add();
        // Delete song
        void Delete();
        // Modify song
        void Modify();
        // Search song ( by name , by singer )
        void Search();
        // Add to Favorite
        void Fav_Add();
        // Search Favorite list
        void Fav_Search();

};

// read raw data
void Table::Read_Data(){
    
    fstream fin;
    fin.open("songlist.csv" , ios::in );

    string line;
    vector<string> row(3);

    while( getline(fin,line) ){
        // cout<<"Line : "<<line<<"\n";
        int last=0 , idx=0;
        bool bracket = false;

        for(int i=0;i<line.size();i++){
            if( line[i]==','){
                row[idx++] = line.substr(last,i-last);
                last=++i;
            }
            if( line[i]=='"' ){
                last = ++i;
                while( line[i]!='"' ) i++;
                row[idx++] = line.substr(last,i-last);
                i+=2;
                last = i;
            }
        }
        row[idx]= line.substr(last , line.size()-last ) ;

        // add to Data list
        Data.push_back( Song(row[0] , row[1] , (uint32)(stoi(row[2]) ) , 0) );
    }
}

void Table::Sort(){
    //  sort Data by len 
    sort(Data.begin() , Data.end() , [&](const Song &a,const Song &b){
        return a.len<b.len;
    });

    // Create Singer to ID & Name to ID tables
    for(int i=0;i<Data.size();i++){
        Singer_ID[ Data[i].singer ].push_back( i );
        Name_ID[ Data[i].name ] = i;
    }
}

/*****************************
    Add a new song
*****************************/
void Table::UI_Add(){
    string name , singer;
    int len;
}

void Table::Add(){
    UI_Add();
}



int User_Interface(){
    int opt;

    cout<<"Options :\n";
    cout<<"(1) Add\n";;
    cout<<"(2) Delete\n";
    cout<<"(3) Modify\n";
    cout<<"(4) Serach\n";
    cout<<"(5) Add to Favorite\n";
    cout<<"(6) Search Favorite\n";

    cin>>opt;

    while( opt<1 || opt>6 ){
        cout<<"Error : out of options' range\n";
        cin>>opt;
    }

    return opt;
}

int main(){

    Table table;
    table.Read_Data();
    table.Sort();

    int option;

    while( true ){
        option = User_Interface();

        switch(option) {
        case ADD:
            table.Add();
            break;
        case DELETE:
            table.Delete();
            break;
        case MODIFY:
            table.Modify();
            break;
        case SEARCH:
            table.Search();
            break;
        case FAV_ADD:
            table.Fav_Add();
            break;
        case FAV_SEARCH:
            table.Fav_Search();
            break;
        default:
            cout<<"Error\n";
    }

    return 0;
}
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


/*****************************
    Overload ostream oeprator 
*****************************/

ostream& operator<<(ostream& os, const Song& item){
    os<<"----------------------------------\n";
    os<<"song :\t"<<item.name<<"\n";
    os<<"singer:\t"<<item.singer<<"\n";
    os<<"length:\t"<<item.len<<"\n";
    os<<"----------------------------------\n";
    return os;
}

ostream& operator<<(ostream& os, const vector<Song>& result){
    os<<"----------------------------------\n";
    os<<"song\t\t|\t\tsinger\t\t|\t\tlength\n";
    for(const Song &i:result ){
        os<<i.name<<"\t"<<i.singer<<"\t"<<i.len<<"\n";
    }
    return os;
}

#define EXIT 0
#define ADD 1
#define DELETE 2
#define MODIFY 3
#define SEARCH 4
#define FAV_ADD 5
#define FAV_SEARCH 6
#define RAND 7

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
        list<Song> Data;
        map< string , vector<Song> > Favorite_List;

    /*****************************
        User INterface of different functions
    *****************************/
        Song UI_Add();
        // Delete song
        int UI_Delete();
        // Modify song
        void UI_Modify();
        // Search song ( by name , by singer )
        int UI_Search();
        // Add to Favorite
        int UI_Fav_Add();
        // Search Favorite list
        int UI_Fav_Serach();
        // Random play
        void UI_Random_Play();

    public:

    /*****************************Song &item
        Preprocess
    *****************************/
        // Input csv file
        void Read_Data();

        void Write_Data();

    /*****************************
        API
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
        // Random play a song 
        void Random_Play();

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


void Table::Write_Data(){
    fstream fout1 , fout2;
  
    // opens an existing csv file or creates a new file.
    fout1.open("songlist_updated.csv", ios::out | ios::app);
    
    for(const Song &i : Data){
        fout1<<i.name<<","<<i.singer<<","<<i.len<<"\n";
    }

    fout2.open("favorite_updated.csv", ios::out | ios::app);
    
    for(const auto &P : Favorite_List ){

        for(const Song &i : P.second){
            fout2<<P.first<<","<<i.name<<","<<i.singer<<","<<i.len<<"\n";
        }
    }
    
}

/*****************************
    Add a new song
*****************************/
Song Table::UI_Add(){
    string name , singer;
    uint32 len;

    string buffer;
    getline(cin,buffer);

    cout<<"Please input new song name :\n";
    getline(cin,name);
    cout<<"Please input singer name of new song :\n";
    getline(cin,singer);
    cout<<"Please input length of new song :\n";
    cin>>len;

    return Song(name,singer,len,0);
}

void Table::Add(){
    Song item = UI_Add();
    int id = Data.size();

    Data.push_back( item );
}

/*****************************
    Delete a new song
    Delete by singer name 
*****************************/
int Table::UI_Delete(){
    cout<<"Options :\n";
    cout<<"(1) Delete by song name\n";;
    cout<<"(2) Delete by singer name\n";

    int opt;
    cin>>opt;

    while( opt<1 || opt>2 ){
        cout<<"Error : out of options' range\n";
        cin>>opt;
    }

    return opt;
}

void Table::Delete(){
    int opt = UI_Delete();

    string buffer;
    getline(cin,buffer);

    string name , singer;
    // delete by song name 

    bool flag = true;
    if( opt==1 ){
        cout<<"Please input the song name that you want to delete.\n";
        getline(cin,name);
        
        auto it = Data.begin();

        while(it!=Data.end()){
            if( it->name==name ){
                it = Data.erase(it);
                flag = false;
                break;
            }
            it++;
        }

        cout<<(flag ? "song name not found\n":"successfully delete\n");
    }
    else{
        cout<<"Please input the singer name that you want to delete.\n";
        getline(cin,singer);
        
        auto it = Data.begin();

        while(it!=Data.end()){
            if( it->singer==singer ){
                it = Data.erase(it);
                flag = false;
            }
            it++;
        }

        cout<<(flag ? "singer not found\n":"successfully delete\n");
    }
}

void Table::UI_Modify(){
    cout<<"Modify by song name:\n";
    cout<<"Please input the song name that you want to modify.\n";
    string buffer;
    getline(cin,buffer);
}

void Table::Modify(){
    UI_Modify();

    string name ;
    getline(cin,name);

    bool flag = true;
    auto it = Data.begin();

    while(it!=Data.end()){
        if( it->name == name ){
            flag = false;
            break;
        }
        it++;
    }

    if( flag ){
        cout<<"song name not found\n";
        return;
    }

    string __name , __singer;
    bool __fav;
    uint32 __len;

    Song item = (*it);

    cout<<"Original song information:\n"<<item<<"\n";

    cout<<"input new song information:\n";
    cout<<"new song name:\n";
    cin>>__name;
    cout<<"new singer name:\n";
    cin>>__singer;
    cout<<"new song's length\n";
    cin>>__len;

    it->name = __name;
    it->singer = __singer;
    it->len = __len;

    cout<<"New song information:\n";

    item = (*it);
    cout<<item;
}

int Table::UI_Search(){
    cout<<"Options :\n";
    cout<<"(1) Search by song name\n";
    cout<<"(2) Search by singer name\n";
    cout<<"(3) Search by song length\n";

    int opt;
    cin>>opt;

    while( opt<1 || opt>3 ){
        cout<<"Error : out of options' range\n";
        cin>>opt;
    }

    return opt;
}

void Table::Search(){
    int opt = UI_Search();

    string buffer;
    getline(cin,buffer);

    bool flag = true;
    if( opt==1 ){
        cout<<"Please input the song name that you want to search.\n";
        string name;
        getline(cin,name);
        for(const Song &i : Data ){
            if( i.name== name ){
                flag = false;
                cout<<i;
                break;
            }
        }

        if( flag ){
            cout<<"song not found.\n";
        }
    }
    else if( opt==2 ){
        vector<Song> result;

        cout<<"Please input the singer that you want to search.\n";
        string singer;
        getline(cin,singer);
        for(const Song &i : Data ){
            if( i.singer== singer ){
                result.push_back( i );
            }
        }

        if( result.empty() ){
            cout<<"singer not found.\n";
        }
        else{
            cout<<result;
        }

    }
    else{
        cout<<"Options :\n";
        cout<<"(1) Search song longer than time range\n";
        cout<<"(2) Search song shorter than time range\n";

        cin>>opt;

        while( opt<1 || opt>2 ){
            cout<<"Error : out of options' range\n";
            cin>>opt;
        }
        
        string buffer;
        getline(cin,buffer);

        int bound;
        

        cout<<"Input time bound:\n";
        cin>>bound;
        getline(cin,buffer);

        vector<Song> result;
        if( opt ==1 ){
            
            for(const Song &i:Data){
                if( i.len <= bound ){
                    result.push_back( i );
                }
            }  
        }
        else{
            for(const Song &i:Data){
                if( i.len >= bound ){
                    result.push_back( i );
                }
            }  
        }

        sort(result.begin() , result.end() , [&](const Song &a,const Song &b){
            return a.len < b.len;
        });

        cout<<result;
    }
}

int Table::UI_Fav_Add(){
    cout<<"Options :\n";
    cout<<"(1) Create a Favorite List\n";
    cout<<"(2) Add song into Favorite List\n";

    int opt;
    cin>>opt;

    while( opt<1 || opt>2 ){
        cout<<"Error : out of options' range\n";
        cin>>opt;
    }

    return opt;
}

void Table::Fav_Add(){
    int opt = UI_Fav_Add();

    string buffer;
    getline(cin,buffer);

    if( opt==1 ){
        string name;
        cout<<"input new Favorite List name:\n";
        getline(cin,name);
        if( Favorite_List.find(name)==Favorite_List.end() ){
            Favorite_List[name] = {};
        }
        else{
            cout<<"Favorite List name existed.\n";
        }
    }
    else{
        string name , song;
        cout<<"input new Favorite List name:\n";
        getline(cin,name);

        if( Favorite_List.find(name)==Favorite_List.end() ){
            cout<<"Favorite List not found\n";
        }
        else{
            cout<<"Please input the song name that you want to add to Favorite list:\n";
            getline(cin,song);
            
            bool flag = true ;
            for(const Song &i : Data ){
                if( i.name == song ){
                    flag = false;
                    Favorite_List[name].push_back( i );
                    break;
                }
            }

            if( flag ){
                cout<<"Song name not found.\n";
            }

        }
    }
}

int Table::UI_Fav_Serach(){
    cout<<"Options :\n";
    cout<<"(1) Search Favorite List\n";
    cout<<"(2) Search song in Favorite List\n";

    int opt;
    cin>>opt;

    while( opt<1 || opt>2 ){
        cout<<"Error : out of options' range\n";
        cin>>opt;
    }

    return opt;
}

void Table::Fav_Search(){
    int opt = UI_Fav_Serach();

    string buffer;
    getline(cin,buffer);

    if( opt==1 ){
        string name;
        cout<<"input Favorite List name:\n";
        getline(cin,name);
        if( Favorite_List.find(name)==Favorite_List.end() ){
            cout<<"Favorite List not found.\n";
        }
        else{
            cout<<"Favorite List existed.\n";
        }
    }
    else{
        string name , song;
        cout<<"input Favorite List name:\n";
        getline(cin,name);

        if( Favorite_List.find(name)==Favorite_List.end() ){
            cout<<"Favorite List not found\n";
        }
        else{
            cout<<"Please input the song name that you want to search in Favorite list:\n";
            getline(cin,song);
            
            bool flag = true ;
            for(const Song &i : Favorite_List[name] ){
                if( i.name == song ){
                    flag = false;
                    cout<<i;
                    break;
                }
            }

            if( flag ){
                cout<<"Song name not found.\n";
            }

        }
    }

}


void Table::Random_Play(){
    int idx = rand()%Data.size();

    for(const Song &it : Data){
        if( !idx ){
            cout<<it;
            break;
        }
        idx--;
    }
}

int User_Interface(){
    int opt;

    cout<<"Options :\n";
    cout<<"(0) Exit\n";
    cout<<"(1) Add\n";;
    cout<<"(2) Delete\n";
    cout<<"(3) Modify\n";
    cout<<"(4) Serach\n";
    cout<<"(5) Add to Favorite\n";
    cout<<"(6) Search Favorite\n";
    cout<<"(7) Randomly play\n";

    cin>>opt;

    while( opt<0 || opt>7 ){
        cout<<"Error : out of options' range\n";
        cin>>opt;
    }

    return opt;
}


int main(){
    srand( time( NULL) ) ;

    Table table;
    table.Read_Data();

    int option;

    while( true ){
        option = User_Interface();
        if( option == EXIT ) break;

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
            case RAND:
                table.Random_Play();
                break;
            default:
                cout<<"Error\n";
        }
    }

    table.Write_Data();
    return 0;
}
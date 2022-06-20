#include<bits/stdc++.h>
using namespace std;

struct Song{
    string name,singer;
    uint32_t len;
    bool favorite;

    Song(string n,string s,uint32_t l,bool f){
        name = n;
        singer = s;
        len = l;
        favorite = f;
    };

};

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

int main(){

}
#include <iostream>
#include "PlayList.h"
#include "Song.h"
using namespace std;

int main() {
  int option=0;
  PlayList lst=PlayList();
  while(option!=5){
    cout<<"1. Enter a song in the play list at a given position"<<endl;
    cout<<"2. Remove a song from the play list at a given position"<<endl;
    cout<<"3. Swap two songs in the play list, given their position"<<endl;
    cout<<"4. Print all the songs in the play list"<<endl;
    cout<<"5. Quit"<<endl;
    cin>>option;

    // Let n be the number of nodes in the playlist
    // Runtime=O(n)
    // The function uses size() to give the user the positions to choose from and insert() to enter the song at the given position
    if(option==1){
      string song_name;
      string artist;
      int length;
      int position;
      cout<<"Song name: "<<endl;
      cin >> ws;
      getline(cin, song_name);
      cout<<"Artist: "<<endl;
      getline(cin, artist);
      cout<<"Length: "<<endl;
      cin>>length;
      cout<<"Position(1 to "<<lst.size()<<"): "<<endl;
      cin>>position;
      while(position<1&&position>lst.size()){
        cout<<"The input is invalid"<<endl;
        cout<<"Position(1 to "<<lst.size()<<"): "<<endl;
        cin>>position;
      }
      lst.insert(Song(song_name, artist, length),position-1);
    }

    // Let n be the number of nodes in the playlist
    // Runtime=O(n)
    // The function uses size() to give the users the positions to choose from and remove() to remove the song at the given position 
    if(option==2){
      int position;
      cout<<"Position(1 to "<<lst.size()<<"): "<<endl;
      cin>>position;
      while(position<1&&position>lst.size()){
        cout<<"The input is invalid"<<endl;
        cout<<"Position(1 to "<<lst.size()<<"): "<<endl;
        cin>>position;
      }
      lst.remove(position-1);
    }

    // Let n be the number of nodes in the playlist
    // Runtime=O(n)
    // The function uses size() to give the user the positions to choose from and swap() to swap the nodes at the given positions
    if(option==3){
      int pos1;
      int pos2;
      cout<<"Swap song at the position (1 to "<<lst.size()<<"): "<<endl;
      cin>>pos1;
      while(pos1<1&&pos1>lst.size()){
        cout<<"The input is invalid"<<endl;
        cout<<"Swap song at the position (1 to "<<lst.size()<<"): "<<endl;
        cin>>pos1;
      }
      cout<<"with the song at postion (1 to "<<lst.size()<<"): "<<endl;
      cin>>pos2;
      while(pos2<1&&pos2>lst.size()||pos2==pos1){
        cout<<"The input is invalid"<<endl;
        cout<<"with the song at position (1 to "<<lst.size()<<"): "<<endl;
        cin>>pos2;
      }
      lst.swap(pos1-1, pos2-1);
    }

    // Let n be the number of nodes in the playlist
    // Runtime=O(n)
    // The function uses for loop to print out the all the songs in the playlist and size() to print out the number of songs in the playlist
    if(option==4){
      for(int i=0; i<lst.size(); i++){
        cout<<i+1<<" "<<lst.get(i).getName()<<" ("<<lst.get(i).getArtist()<<") "<<lst.get(i).getLength()<<endl;
      }
      cout<<"There are "<<lst.size()<<" songs in the play list."<<endl;
    }
  }
  cout << "You have chosen to end the quit the program"<<endl << endl;
}
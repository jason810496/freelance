// Write your name and date here
#include "PlayList.h"
#include <iostream>
using namespace std;
// PlayList method implementations go here
PlayList::PlayList(){
  head=NULL;
  tail=NULL;
}

// Let n be the number of nodes in pl
// Runtime=O(n)
// The method copy the song data of pl to the song members of object itself
PlayList::PlayList(const PlayList& pl){
  PlayListNode* cur=pl.head;
  PlayListNode* cur2=head;
  while(cur!=NULL){
    PlayListNode* newNode=new PlayListNode(cur->song,NULL);
    cur2=newNode;
    tail=newNode;
    cur2=cur2->next;
    cur=cur->next;
  }
}

PlayList::~PlayList(){
   PlayListNode* tmp = head;
   PlayListNode* cur = head;
   while(cur) {
     delete tmp;
     cur = cur->next;
     tmp = cur;
   }
}

// fix bugs
PlayList& PlayList::operator=(const PlayList & pl) {
  PlayListNode* h = this->head;
  h = pl.head;

  return *this;
}
  // this->head=pl.head;
  // this->tail=pl.tail;

// Let n be the number of nodes in the playlist
// Runtime=O(n)
// The method uses while loop to find the position in the playlist 
void PlayList::insert(Song sng, unsigned int pos){
  if (head == NULL) {
    head = new PlayListNode(sng);
    tail = head;
    return;
  }
  int i=0;
  PlayListNode* prev=head;
  PlayListNode* cur=head->next;
  while(prev && i!=pos){
    if(cur) cur=cur->next;
    prev=prev->next;
    i++;
  }
  PlayListNode* newNode=new PlayListNode(sng, cur);
  prev->next=newNode;
}

// Let n be the number of nodes in the playlist
// Runtime=O(n)
// The method uses while loop to find the node to be removed
// find bug !
Song PlayList::remove(unsigned int pos){
  int i=1;
  PlayListNode* prev=head;
  PlayListNode* cur=head->next;
  while(i!=pos){
    cur=cur->next;
    prev=prev->next;
    i++;
  }
  Song ret=cur->song;
  prev->next=cur->next;
  delete[] cur;
  return ret;
}

// Let n be the number of nodes in the playlist
// Runtime=O(n)
// The method uses while loop to find the nodes to be swapped, then swaps their data member 
void PlayList::swap(unsigned int pos1, unsigned int pos2){
  int i=0;
  int j=0;
  PlayListNode*cur1=head;
  PlayListNode*cur2=head;
  while(i!=pos1){
    i++;
    cur1=cur1->next;
  }
  while(j!=pos2){
    j++;
    cur2=cur2->next;
  }
  Song temp=cur1->song;
  cur1->song=cur2->song;
  cur2->song=temp;
}

// Let n be the number of nodes in the playlist
// Runtime=O(n)
// The moethod uses while loop to find the node in the given position and return its song data member
Song PlayList::get(unsigned int pos)const{
  int i=0;
  PlayListNode* cur=head;
  while(i!=pos){
    cur=cur->next;
    i++;
  }
  return cur->song;
}

// Let n be the number of nodes in the PlayList
// Runtime=O(n)
// The method uses while loop to find the length of the playlist
unsigned int PlayList::size()const{
  int ret=0;
  PlayListNode*cur=head;
  while(cur!=NULL){
    ret++;
    cur=cur->next;
  }
  return ret;
}
#include<iostream>


#include "Sequence.hpp"
#include "container.hpp"

int main(){
    CS52::Container m( 5 ,3);
    CS52::Container n(5,0);

    n[0]=50 , n[1]=100 , n[2]=500;

    CS52::Container o=n-m;

    std::cout<<o<<'\n';

    CS52::Sequence *seq[2];

    // CS52::Sequence * ptr1 = new CS52::Container;

    seq[0] = new CS52::Container(5,11);

    seq[1] = new CS52::Container(3,1);

    std::cout<<seq[0]->type();
}
#include "container.hpp"

int main(){
    CS52::Container m( 5 ,3);
    CS52::Container n(3,0);

    n[0]=50 , n[1]=100 , n[2]=500;

    CS52::Container o=n-m;

    std::cout<<o;
}
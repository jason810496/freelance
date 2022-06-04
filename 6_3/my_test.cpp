#include <iostream>
using namespace std;

class Base {
public:
    virtual void fun()
    {
        std::cout << "Base::fun()" << std::endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun()
    {
        std::cout << "Derived::fun()" << std::endl;
    }
};

int main(){

    Base* base = new Derived;
    base->fun();   

return 0;
}

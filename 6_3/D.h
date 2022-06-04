

class Derived : public Base
{
public:
    virtual void fun()
    {
        std::cout << "Derived::fun()" << std::endl;
    }
};
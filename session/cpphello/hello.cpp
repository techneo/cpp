#include <cstdint>
#include <utility>
#include <string>
#include <iostream>


//simple base class
class CBase {
    public:
    int a;
    int c;

    //prototype delcared here
    CBase()
    {
        std::cout << "Base  Live " << this << std::endl;
    }

    //prototype
    CBase(int a);

    ~CBase()
    {
        std::cout << "Base Dead " << this << std::endl;
    }

};

// the class is derived from the base class
class CDerived : CBase
{
    private:
    int pvar;

    public:
    int b;
    CDerived(int a , int b)
    {
        this->b = b;
        this->a = a;
        std::cout << "a=" << this->a << " b=" << this->b << " Live" << std::endl;
    }
    // cant use if the other cons in 42 is needed
    // CDerived(int a) : CBase(a) 
    // {

    // }
    // ctor which calls the base ctor and also assigns a private variable a value
    CDerived(int a,int b,int c) : CBase(a) , pvar(b)
    {
        std::cout << "a=" << this->a << " b=" << this->b << "pvar = " << this->pvar << " Live" << std::endl;
    }

};

// member functions can be declared outside the class defn 
CBase :: CBase(int a)
    {
        this->a = a;
        std::cout << "a=" << this->a << " Live" << std::endl;
    }

int main(void)
{
    //CBase B1(); //does not call the constructor/destructor
    //CBase B2(13); //calls c/d
    //CBase B3{}; //calls c/d
    //CDerived D1(3,4);
    CDerived D2{4,5,0}; //calls the derived class constructor which in turn calls the base class constructor
    return 0;
}

/*
A typical template implementation
*/
#include <iostream>

template <typename T>

class MyClass
{
private:
    T var;
public:
    MyClass(T xx) : var{xx}
    {

    }
    T getVal()
    {
        return var;
    }
};

int main(void)
{
    MyClass<int> C1{1};
    MyClass<float> C2{1.9};
    MyClass<double> C3{1.93};
    MyClass<std::string> C4{"hello"};
    std::cout<<"x= "<<C1.getVal()<<"\n";
    std::cout<<"x= "<<C2.getVal()<<"\n";
    std::cout<<"x= "<<C3.getVal()<<"\n";
    std::cout<<"x= "<<C4.getVal()<<"\n";
    return 0;
}
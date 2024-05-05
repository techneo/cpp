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
    std::cout<<"x= "<<C1.getVal()<<"\n";
    std::cout<<"x= "<<C2.getVal()<<"\n";
    return 0;
}
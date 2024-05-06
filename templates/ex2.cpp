/*
Write a program that defines a simple class template that has one data member of a 
generic type, a constructor, a getter function of a generic type, and a setter member 
function. Instantiate a class in the main() function for int and double types:
*/

#include <iostream>

template <typename T>
class MySimpleClass {
    public:
    T myvar;
    MySimpleClass();
    T getter(void);
    void setter(T var);

};

template <typename T>
MySimpleClass<T>::MySimpleClass()
{
    myvar = 0;
}

template <typename T>
T MySimpleClass<T>::getter(void)
{
    return myvar;
}

template <typename T>
void MySimpleClass<T>::setter(T var)
{
    myvar = var;
}



int main(void)
{
    MySimpleClass<int> C1;
    MySimpleClass<double> C2;
    std::cout<<C1.getter()<<"\n";
    std::cout<<C2.getter()<<"\n";
    C1.setter(9);
    C2.setter(0.55);
    std::cout<<C1.getter()<<"\n";
    std::cout<<C2.getter()<<"\n";
    return 0;
}
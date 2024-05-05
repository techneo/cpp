#include <iostream>

template <typename T> //T here stands for a type name


void myFunc(T param)
{
    std::cout<<"value of param is "<<param<<"\n";
}

int main(void)
{
    myFunc(10);
    myFunc(32.55);
    myFunc("Hello");
    return  0;
}
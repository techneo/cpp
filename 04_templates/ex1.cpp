/*
Write a program that defines a template for a function that sums two numbers. Numbers 
are of the same generic type T and are passed to function as arguments. Instantiate the 
function in main() using int and double types:
*/

#include <iostream>

template <typename T>
T sum(T var1 , T var2)
{
    return var1+var2;
}

int  main(void)
{
    int res = sum<int>(10.95,20);
    std::cout<<"res = "<<res<<"\n";
    std::cout<<sum(1,5)<<"\n";
    std::cout<<sum(1.4,5.7)<<"\n";
    return 0;
}
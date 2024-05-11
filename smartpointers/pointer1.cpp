/*
Usage of Smart Pointers and comparison with traditional pointers
*/

#include <iostream>
#include <memory> //needed for smart pointers

int main()
{
    {
        //simple pointers (not recommended)
        int *p = new int(5);
        std::cout << *p;
        delete p; //needed for a normal pointer

        //standard C++ way
        std::unique_ptr<int> p1(new int{444});
        std::cout<<"Smart pointer value="<<*p1;

        std::unique_ptr<int> p2 = std::make_unique<int>(44); //C++14 standard. -std=c++14
        std::cout<<"Smart pointer value="<<*p2;
    } //both p1 and p2 get deleted here as the variables are out of scope after this
    return 0;
}

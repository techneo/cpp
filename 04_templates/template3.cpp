#include <iostream>

template <typename T>
class MyTempClass {
    public:
        void test(T var)
        {
            std::cout<<var;
            std::cout<<" PASS\n";
        }
        // prototype for function taking T as param and return object of type T
        T test1(T var);
        // prototype for void fn with template
        void test2(T var);

};

// generic template for diffent data types
template <typename T>
T MyTempClass<T>::test1(T var)
{
    return var*2;
}

// a specialised template for std::string
template <>
std::string MyTempClass<std::string>::test1(std::string s)
{
    return s+"added";
}

// implement member function outside the class definition
template <typename T>
void MyTempClass<T>::test2(T var)
{
    std::cout<<"test2 called\n";
}

int main(void)
{
    MyTempClass<int> c1;
    MyTempClass<float> c2;
    MyTempClass<std::string> c3;
    c1.test(1);
    std::cout<<c1.test1(4);
    std::cout<<c2.test1(4.55)<<"\n";
    std::cout<<c3.test1("hello")<<"\n";
    c2.test2(6);

}
#include <iostream>

class MyClass
{
    private:
        int a;
        int b;
    public:
        MyClass(void)
        {
            std::cout<<"default const"<<std::endl;
        }
};

int main(void)
{
    MyClass C1;
    return 0;
}
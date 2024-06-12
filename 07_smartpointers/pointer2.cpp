/*
Usage of Smart Pointers and comparison with traditional pointers
*/

#include <iostream>
#include <memory> //needed for smart pointers

class CFoo
{
    public:
        void print(void)
        {
            std::cout<<"print from Foo Class\n";
        }
        virtual void print1(void)
        {
            std::cout<<"print1 function of f00 \n";
        }

};

class CBar : public CFoo
{
    public:
        void print1(void)
        {
            std::cout<<"print1 in derived class \n";
        }

};

int main()
{
    std::unique_ptr<CFoo> c1 = std::make_unique<CFoo>();    
    c1->print();

    std::unique_ptr<CFoo> c2 = std::make_unique<CBar>();
    c2->print1();
    
    return 0;
}

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

    //not posible to make copies (compile error)
    //std::unique_ptr<CFoo> cx =c1;    
    c1->print();
    // we can create copies if we declare as shared_ptr
    std::shared_ptr<CFoo> c2 = std::make_unique<CBar>();
    //both point to the same onject. 
    std::shared_ptr<CFoo> c3 = c2;
    c3->print1();
    c2->print1();
    return 0;
}

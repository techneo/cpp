#include <iostream>

class MyBaseClass //when there is a pure virtual function, it becomes a abstract class
{
public:
    int a;
    int b;
    MyBaseClass(void)
    {
        a = 10;
    }
    virtual void mainfunc(void) // this function can be overridden by any derived class
    {
        std::cout << "Base function\n";
    }
    virtual void subfunc(void) = 0; // a pure virtual function that derived classes have to implement
    void check_a(void)
    {
        std::cout << "a= " << a << "\n";
    }
    virtual ~MyBaseClass(void)
    {
        
    }
};

class NewClass : public MyBaseClass
{
public:
    void mainfunc(void) // this overrides the base class function
    {
        std::cout << "New function\n";
    }
    virtual void subfunc(void)
    {
        std::cout << "NewClass sub function\n";
    }
};

class NewClass1 : public MyBaseClass // this class does not override the baseclass function
{
public:
    int a;
    NewClass1(void)
    {
        std::cout << "NewClass1 constructor\n";
        a = 20;
    }
    void subfunc(void)
    {
        std::cout << "NewClass1 sub function\n";
    }
};

class NewClass2 : public NewClass1
{
public:
    NewClass2(void)
    {
        std::cout << "NewClass2 constructor\n";
    }
    void subfunc(void)
    {
        std::cout << "NewClass2 sub function\n";
    }
};

int
main(void)
{
    // MyBaseClass c0; not posible as this is a abstract class ( has 2 virtual funcs)
    NewClass1 c1;
    MyBaseClass *c2 = new NewClass(); // this is posbile because NewClass is derived from MyBaseClass
    MyBaseClass *c3 = new NewClass2();
    // NewClass * c3 = new MyBaseClass; : Will give compile error
    // NewClass1 c3; // this is posbile because NewClass is derived from MyBaseClass
    // c0.mainfunc();
    c1.mainfunc(); // does not implement mainfunc
    c2->mainfunc();
    c1.mainfunc();
    c1.check_a();
    c3->subfunc();
    delete c2;
    delete c3;
    return 0;
}
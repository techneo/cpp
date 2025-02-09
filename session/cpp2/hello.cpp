#include <cstdint>
#include <utility>
#include <string>
#include <iostream>

#include <bits/stdc++.h>

class CBaseClass
{
public:
    int gvar;
    CBaseClass(int a)
    {
        this->gvar = a;
    }
    virtual int get_calc(void) = 0;
};

//inheritence is private by default.
class CDerived : public CBaseClass
{
public:
    CDerived(int a) : CBaseClass(a)
    {
    }
    int get_calc(void)
    {
        return ldexp((this->gvar),4);
    }
};

int main(void)
{
    CDerived c1{4};
    std::cout << "GVAR = " << c1.gvar <<std::endl;
    std::cout << c1.get_calc() <<std::endl;
    return 0;
}

#include <iostream>

enum class cpus { // the class keyword give the enum a scope
    intel,
    amd,
    rockchip,
    allwinner
};

int main(void)
{
    int choice;
    std::cout<<"Enter a number:"<<"\n";
    std::cin>>choice;
    //std::cout<<choice;
    switch (choice)
    {
        case (int)cpus::intel: //enums accessed with scope 
            std::cout<<"You selected Intel\n";
        break;
                case (int)cpus::amd:
            std::cout<<"You selected AMD\n";
        break;
                case (int)cpus::rockchip:
            std::cout<<"You selected Rockchip\n";
        break;
                case (int)cpus::allwinner:
            std::cout<<"You selected Allwinner\n";
        break;
        default:
            std::cout<<"Invalid Choice";
    }
}
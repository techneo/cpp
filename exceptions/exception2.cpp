/*
Example for Multiple Exeception Handling
*/

#include <iostream>

int main(void)
{
    int choice;
    std::cout<<"enter choice 1- int 2-string :";
    std::cin>>choice;
    try // integer exception
    {
        if (choice == 1)
        {
            std::cout << "Let us throw a exception\n";
            // forced exception generation
            throw(123);
        }
        else if (choice == 2)
        {
            std::cout << "Let us throw a string exception\n";
            throw std::string{"Hello"};
        }
    }
    catch (int e)
    {
        std::cout << "exception raised " << e << "\n";
    }
    catch (const std::string &e)
    {
        std::cout << "String exception " << e << '\n';
    }
    return 0;
}
/*
Example for Exeception Handling
*/

#include <iostream>

int main(void)
{
    try // integer exception
    {
        std::cout << "Let us throw a exception\n";
        // forced exception generation
        throw(123);
    }
    catch (int e)
    {
        std::cout << "exception riased " << e << "\n";
    }
    try //string exception
    {
        /* code */
        std::cout << "Let us throw a string exception\n";
        throw std::string{"Hello"};
    }
    catch (const std::string &e)
    {
        std::cout << "String exception " << e << '\n';
    }
    return 0;
}
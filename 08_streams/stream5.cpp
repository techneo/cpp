#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
using Strinstream to read and write from String

istringstream - to read from string
ostringstream - to write to string
stringstream - to read and write from string

*/
int main()
{

    // now we will read back from a string stream to different variables
    std::string s;
    float f;
    int i;

    std::stringstream ss2{"3.14 980 HELLO1"};
    // read in the same order else we get junk
    ss2 >> f >> i >> s;
    std::cout <<"Reading from stream :";
    std::cout <<f<<","<<i<<","<<s<<std::endl;
    return 0;
}

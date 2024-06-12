#include <iostream>
#include <fstream>
#include <string>
/*
Writing objects (string) to a file stream
*/
int main()
{
    // creating is similar to file in c
    // parameters are filename and permission

    //std::ios::out - overwrites if exists
    //std::ios::app - append if file exists
    std::string s1 = "line1\n";
    std::string s2 = "line2";

    std::fstream fs{"testout2.txt",std::ios::out};
    fs << s1 << s2;
    return 0;
}

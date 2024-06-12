#include <iostream>
#include <fstream>
#include <string>

/*

Writing to a file stream

*/

int main()
{
    // creating is similar to file in c
    // parameters are filename and permission

    //std::ios::out - overwrites if exists
    //std::ios::app - append if file exists
    std::fstream fs{"testout1.txt",std::ios::app};
    fs << "new line in text " << "\n" << "new line 2";
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>

/*
Types of streams
ifstream - Read from file
ofstream - Write to file
fstream - Read/Write from file

*/

int main()
{

    std::fstream fs{"text.txt"};
    std::string s;
    char c;

    while (fs)
    {

        std::getline(fs, s);
        std::cout << s << "\n";
        if (fs.eof())
        {
            break;
        }
    }

    fs.clear();
    fs.seekg(0);

    //while (fs >> c) // leaves all the white spaces
    while (fs >> std::noskipws >> c)
    {
        std::cout<<c;
    }
    std::cout<<"\n";
    return 0;
}

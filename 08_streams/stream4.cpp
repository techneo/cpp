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
    //using the constructor to create the stringstream
    std::string temps{"Test string "};
    std::stringstream ss{"Hello world"};
    std::stringstream ss1{temps};

    //str() -> member function to print the content of the stream
    std::cout << ss.str();


    // Write to the string stream
    ss << "New world";

    std::cout << ss.str();
    std::cout << ss1.str();

    //write formatted string
    ss<<"\nChar is "<<'c'<< "\nfloat  is "<<1.44<<"\nNumber is" <<43<<std::endl;
    std::cout<<ss.str()<<std::endl;

    return 0;
}

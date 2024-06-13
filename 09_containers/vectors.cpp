#include <iostream>
#include <vector>

int main() {
    //declare a vector
    std::vector<int> a ;
    //add elements to vector
    a.push_back(4);
    a.push_back(41);
    std::cout << "Hello, World!" << std::endl;

    //print elements of vector
        for (auto it = a.begin(); it != a.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}

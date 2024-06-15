#include <iostream>
#include <set>

int main() {
    //declare a set
    std::set<int> a;
    //add elements
    a.insert(4);
    a.insert(3);
    a.insert(5);
    // not reflectd in set as 5 is already present
    a.insert(5);

    //set is sorted by default
    for (auto el : a)
    {
        std::cout << el << "\n";
    }
    return 0;

    /*
    Output:
    3
    4
    5
    */
}

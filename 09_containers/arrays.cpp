#include <iostream>
#include <set>

int main() {
 
    std::array<int,5> a = {1,3,4,6,7};
    //add elements not posible
    //a.insert(3);
    

    for (auto el : a)
    {
        std::cout << el << "\n";
    }
    //index starts from 0
    //print element at post 3
    std::cout <<"element at 3rd pos= "<<a[3]<<"\n";
    return 0;

    /*
    Output:
    3
    4
    5
    */
}

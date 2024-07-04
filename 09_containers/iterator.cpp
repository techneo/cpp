/*
 * Iterators are used to traverse containers.
 * Containers like vectors have v.begin() and v.end() that 
 * point to the first and the least+1 element 
*/
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> vec = { 1,2,4,6,8 };
    //without using iterator
    std::cout << "Original Vector:\n";
    for (auto el:vec)
    {
        std::cout<<el<<"\n";
    }
    
    //let us change element at index 3 (val=4)
    
    //index starts at 0. 
    auto it =vec.begin()+2;
    std::cout<<"Val at 3= "<<*it<<"\n";
    *it = 88; //change value
    std::cout<<"updated value \n";
    //using iterator variable;
    std::cout << "Updated Vector:\n";
    for (auto itr = vec.begin();itr !=vec.end();itr++)
    {
        std::cout<<*itr<<"\n";
    }
    
    //let us remove one element 
    it = vec.begin()+4;
    //not advised
    // ref: https://www.codeproject.com/Articles/1227392/Erase-remove-Idiom-Revisited
    vec.erase(it);
    std::cout << *it;
    std::cout << "removed \n";
    
    //using iterator variable;
    std::cout << "New Vector:\n";
    for (auto it = vec.begin();it !=vec.end();it++)
    {
        std::cout<<*it<<"\n";
    }
    
    //let us add one more element and remove it using STL method
    vec.push_back(66);
    std::cout << "after add new element , New Vector:\n";
    for (auto it = vec.begin();it !=vec.end();it++)
    {
        std::cout<<*it<<"\n";
    }
    return 0;
}
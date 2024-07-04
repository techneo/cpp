#include <iostream>
#include <map>

/*
 * Implementation of the MAP container
 * 
 */

int main(void)
{
    // the syntax for map asks for 2 parameters 
    // first is the key
    // second is the value
    std::map<int,int> m1 = {{1,4},{2,5}};
    // adding new element is simple 
    // if key is not present the element is inserted
    m1[3]='r';
    // map elements can also be updated 
    // if key already present.
    m1[1]=99;
    // or we can use the insert method specifying the key and value
    m1.insert({5,7});
    // insert method does not update the value 
    m1.insert({5,8});
    
    for (auto el:m1)
    {
        std::cout<<el.first<<","<<el.second<<"\n";
    }
    
    //we can lookup elements in the map using find()
    // if found it points to a pair 
    // it->first and it->second point to the matched pair
    auto it = m1.find(6);
    if (it != m1.end())
    {
        std::cout<<"Key "<<it->first<<" found with value "<<it->second<<"\n";
    }
    else
    {
        std::cout<<"Key not found\n";
    }
    
    return 0;
}
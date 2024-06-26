#include <iostream> //for cout

class MyClass // class name
{
private: // members are not accesible only inside the class functions
    int a;
    int b;

public: // methods and variables are available to the instance
    MyClass(void)
    {
        std::cout << "default const" << std::endl;
    }
    MyClass(int aa, int bb) : a{aa}, b{bb} // constructor that inits the private variables
    {
    }
    MyClass &operator+=(MyClass rhs) // overload the + operator to
                                     // add the memebers inside the class
    {
        this->a += rhs.a;
        this->b += rhs.b;
        return *this;
    }

    // the friend function avoids
    // instantiating a new class and copy
    // this to it and then perform the
    // operation
    friend MyClass operator+(MyClass lhs, const MyClass &rhs)
    {
        lhs += rhs;
        return lhs;
// without friend code
#if 0
            MyClass result = *this;  // Create a copy of the current object
            result += rhs;           // Perform addition using compound assignment
            return result;           // Return the result
#endif
    }
    void print(void) // public function to print the privarte variables
    {
        std::cout << this->a << "," << this->b << std::endl;
    }
};

int main(void)
{
    MyClass C1{1, 10};
    MyClass C2{1, 1};
    C1.print();
    // C1 = C1 += C2;
    C1 = C1 + C2 + C1;
    // C1 = C1+C1;
    C1.print();
    return 0;
}
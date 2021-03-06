#include "./MyArray.hpp"
#include <iostream>
#include <string>
#include <iterator>
int main()
{
    // MyArray<double, 10> myArray;
    // myArray.fill(10.32);
    // myArray[3] = 3; // Assuming that 'my' has been appropriately allocated based

    // std::cout << "Looking for '3'? " << (myfind(myArray.begin(), myArray.end(), 3) != myArray.end()? "found" : "sry no") << std::endl;
    // std::cout << *myArray.end() << std::endl;
    // std::cout << *myArray.begin() << std::endl;
    // std::cout << myArray[5] << std::endl;
    // std::cout << myArray.size() << std::endl;

    MyArray<int, 15> myInt;
    MyArray<double, 20> myDouble;
    myInt[10] = 10;
    myInt[4] = 22;
    myInt[3] = 32;
    myInt[1] = 1;
    myDouble = myInt;
    std::cout << myAccumalation(myInt) <<std::endl;
    // std::cout << myInt[10] << std::endl;
    // std::cout << myDouble[4] << std::endl;
    // std::cout << myDouble[5] << std::endl;

    MyArray<std::string*, 10> myString;
    myString[5] = new std::string("Hello");
    myString[0] = new std::string("Beginning");
    std::cout << **myString.begin() << std::endl;
    std::cout << "Looking for 'Hello '? " << (myfind(myString.begin (), myString.end(),
        std:: string("Hello")) != myString.end()? "found" : "sry no") << std::endl;

    //Test for std:: algorithms
    std::ostream_iterator<int> ouput(std::cout, " ");
    MyArrayIterator<int> it1(myInt.begin());
    MyArrayIterator<int> it2(myInt.end());

    std::cout << "Writing contents of myarray to cout:" << std::endl;
    std::copy(it1, it2, ouput);
    
    return 0;
}

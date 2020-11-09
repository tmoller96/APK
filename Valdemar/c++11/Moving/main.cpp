#include "File.hpp"
#include <iostream>
#include "Copyable.hpp"
#include <vector>


int main()
{
    //File test 
    //----------------------------------------------------------------------------------
    //Test constructor
    // File file1("test.txt");
    // std::cout << file1.read(10) << std::endl;

    //Test copy constructor
    // File copyFile(file1);
    // std::cout << "Reading from copied File: " << copyFile.read(10) << std::endl;

    // //Test assignment operator
    // File assigned = copyFile;
    // std::cout << "Reading from assigned file: " << assigned.read(10) << std::endl;

    //Test move constructor
    // File moveConstructed(std::move(file1));
    // std::cout << "Reading from move constructor: " << moveConstructed.read(10) << std::endl; 

    //Test move assignment 
    // File moveAssign("test1.txt");
    // moveAssign = std::move(moveConstructed);
    // std::cout << "Reading from move assignment: " << moveAssign.read(10) << std::endl;
    //----------------------------------------------------------------------------------


    std::vector<Copyable> v = std::vector<Copyable>();
    for(int i = 0; i < 100; ++i)
    {
        v.emplace_back(i, "This is some string"); //Using emplace_back constructs in place and therefore we save a move- would look like this
//      emplace_back:
//      I am being constructed.
 
//      push_back:
//      I am being constructed.
//      I am being moved.
//Also all elements are moved once the vector is resized
    }

    std::cout << "Moving from one vector to another";
    std::vector<Copyable> v2 = std::move(v);
}
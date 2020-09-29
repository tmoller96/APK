#include <string>
#include <boost/variant.hpp>
#include <iostream>
#include "OutputVisitor.hpp"
int main() 
{
    boost::variant<int, MyClass, std::string, double> myV {};
    myV = 10;
    std::cout << myV << std::endl;
    myV = MyClass("test", 1, 1023);
    std::cout << myV << std::endl;
    myV = 1031230;
    boost::apply_visitor(OutputVisitor(), myV);
    myV = MyClass("test", 1, 1023);
    boost::apply_visitor(OutputVisitor(), myV);

    myV = 2.310;
    boost::apply_visitor(OutputVisitor(), myV);

    return 0;
}
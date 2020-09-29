#include <boost/variant.hpp>
#include <iostream>
#include "class.hpp"
class OutputVisitor : public boost::static_visitor<>
{
    public:
    void operator() (int &i) const 
    {
        std::cout << "Calling functor with integer" << std::endl;
        std::cout << i << std::endl;
    }
    void operator() (MyClass & myC) const
    {
        std::cout << "Calling functor with MyClass" << std::endl;
        std::cout << myC << std::endl;
    }
    void operator() (long & l) const
    {
        std::cout << "Calling functor with long" << std::endl;
        std::cout << l << std::endl;
    }
    template<typename T>
    void operator() (T & t) const
    {
        std::cout << "Calling functor with template" << std::endl;
        std::cout << t << std::endl;
    }
};
#include <iostream>
#include <thread>
#include "Events.hpp"
class FunctorTest {
    public:
    void operator()(const std::shared_ptr<Event> &event) 
    {
        std::cout << "Called from within Functor: " << event << std::endl;
    }
};
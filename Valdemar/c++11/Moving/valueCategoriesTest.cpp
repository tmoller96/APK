#include "ValueCategories.hpp"
#include <iostream>
#include "Copyable.hpp"

int main()
{
    //prvalues
    PRINT_VALUE_CAT(42);
    PRINT_VALUE_CAT(Copyable(10, "Random2"));

    //lvalues
    PRINT_VALUE_CAT("This is a string");
    std::string s("This is another string");
    PRINT_VALUE_CAT(s);
    Copyable c(10, "Random");
    PRINT_VALUE_CAT(c);
    
    //xvalues
    PRINT_VALUE_CAT(std::move(s));
}   
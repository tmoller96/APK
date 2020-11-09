#include <iostream>
#include "binary.hpp"
#include "typelist.hpp"

typedef TypeList<long , TypeList<char , TypeList<int, NullType>>> TL;

int main(int argc, char const *argv[])
{
    /* Generates a compiler error */
    // std::cout << "Binary <1011 >:: value = " << Binary <1020>:: value << std::endl;

    /* Doesn't generate a compiler error */
    std::cout << "Binary <1011 >:: value = " << Binary <1011>:: value << std::endl;

    // IsSame
    /* Must be true */
    std::cout << "IsSame <int , int >:: value=" << IsSame <int , int >:: value << std::endl;
    /* Must be false */
    std::cout << "IsSame <int , char >:: value=" << IsSame <int , char >:: value << std::endl;

    // Contains
    /* Must be true */
    std::cout << "Contains <TL , int >:: value=" << Contains <TL , int>:: value << std::endl;

    /* Must be false */
    std::cout << "Contains <TL , std::string >:: value=" << Contains <TL , std::string>:: value << std::endl;

    // AtIndex
    /* Must be true */
    std::cout << "IsSame <typename AtIndex <TL , 2>::type , int >:: value=" << IsSame <typename AtIndex <TL , 2>::type , int >:: value << std::endl;

    /* Must be false */
    std::cout << "IsSame <typename AtIndex <TL , 2>::type , char >:: value=" << IsSame<typename AtIndex <TL , 2>::type , char >:: value << std::endl;

    return 0;
}

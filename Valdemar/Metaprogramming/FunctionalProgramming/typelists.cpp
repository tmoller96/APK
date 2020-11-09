#include "at_index.hpp"
#include "contains.hpp"
#include "is_same.hpp"
#include <iostream>
// #define TYPELIST1(T1) TypeList<T1, NullType>;
// #define TYPELIST2(T1, T2) TypeList<T1, T2>;
// #define TYPELIST3(T1, T2, T3) TypeList<T1, TypeList<T2, T3>>;

int main()
{
  std::cout << "IsSame <int , int >:: value=" << IsSame<int, int>::value
            << std::endl;

  std::cout << "IsSame <int , char >:: value=" << IsSame<int, char>::value
            << std ::endl;

  typedef TypeList<int, TypeList<char, TypeList<long, NullType>>> TL;
  std::cout << "Contains <TL , int >:: value=" << Contains<TL, int>::value
            << std::endl;

  /* Must be false */
  std::cout << "Contains <TL , std::string >:: value="
            << Contains<TL, std::string>::value << std::endl;

  typedef TypeList<long, TypeList<char, TypeList<int, NullType>>> TL2;
  /* Must be true */
  std::cout << "IsSame <typename AtIndex <TL , 2>::type , int >:: value"
            << IsSame<typename AtIndex<TL2, 2>::type, int>::value << std::endl;
    
  std::cout << "IsSame <typename AtIndex <TL , 2>::type , char >:: value"
            << IsSame<typename AtIndex<TL2, 2>::type, char>::value << std::endl;
}

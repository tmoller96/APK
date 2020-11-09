#ifndef PRINTIT_HPP
#define PRINTIT_HPP
#include "typelist.hpp"
template <typename TL> struct PrintIt
{
  static constexpr name =
      typeid(typename TL::First).name() + PrintIt<typename TL::Rest>::name;
};

template <> struct PrintIt<NullType>
{
    static constexpr name = ""
};

#endif
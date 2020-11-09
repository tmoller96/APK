#ifndef CONTAINS_HPP
#define CONTAINS_HPP

#include "front.hpp"
#include "is_same.hpp"
#include "pop_front.hpp"
#include "typelist.hpp"

template <typename TL, typename T> struct Contains
{
public:
  static const bool value =
      IsSame<typename TL::First, T>::value ? true : Contains<typename TL::Rest, T>::value;
};


template <typename T> struct Contains<NullType, T>
{
public:
  static const bool value = false;
};

#endif
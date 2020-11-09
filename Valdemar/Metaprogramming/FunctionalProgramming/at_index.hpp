#ifndef ATINDEX_HPP
#define ATINDEX_HPP
#include "typelist.hpp"
template <typename TL, int I> struct AtIndex
{
public:
  using type = typename AtIndex<typename TL::Rest, I - 1>::type;
};

template <typename TL> 
struct AtIndex<TL, 0>
{
public:
  using type = typename TL::First;
};

template<>
struct AtIndex<NullType, 0>
{
public:
  using type = NullType;
};

#endif
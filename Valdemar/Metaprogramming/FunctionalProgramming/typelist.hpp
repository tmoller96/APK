#ifndef TYPELIST_HPP
#define TYPELIST_HPP
template <typename L, typename R> struct TypeList
{
  typedef L First;
  typedef R Rest;
};
struct NullType
{
};
#endif
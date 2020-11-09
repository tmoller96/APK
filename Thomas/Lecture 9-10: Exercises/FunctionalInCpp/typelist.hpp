#pragma once
#include <iostream>

struct NullType {};

template<typename L, typename R>
struct TypeList
{
    typedef L First;
    typedef R Rest;
};


/*
IsSame - Exercise 3.2.1
If struct is called with 2 different types, return false.
*/
template<typename T0, typename T1>
struct IsSame 
{
    static constexpr bool value = false;
};

/*
IsSame - Exercise 3.2.1
If struct is called with a single type, return true.
*/
template<typename T>
struct IsSame<T, T>
{
    static constexpr bool value = true;
};


/*
Contains - Exercise 3.2.2
Checks if first type in list is the same as given type.
If it is, returns true, else calling contains recursive,
with the rest of the types from the typelist.
*/
template<typename TList, typename T>
struct Contains
{
    static constexpr bool value = IsSame<typename TList::First, T>::value ? true : Contains<typename TList::Rest, T>::value;
};

/*
Contains - Exercise 3.2.2
Base case for recursive call on contains. When this
struct is called, the given type is not included 
in the typelist, and therefore this returns false.
*/
template<typename T>
struct Contains<NullType, T>
{
    static constexpr bool value = false;
};


/*
AtIndex - Exercise 3.2.3
*/
template<typename TList, size_t N, size_t NStart = 0>
struct AtIndex
{
    using type = typename AtIndex<typename TList::Rest, N, NStart + 1>::type;
};

template<size_t N, size_t NStart>
struct AtIndex<NullType, N, NStart>
{
    using type = decltype(NullType());
};

template<typename TList, size_t N>
struct AtIndex<TList, N, N>
{
    using type = typename TList::First;
};
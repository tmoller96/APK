#include <cstddef>
#include <typeinfo>
#include <type_traits>
#include <iostream>
template<typename T, std::size_t capacity>
class MyArray
{
private:
    T * _array;
public: 
    MyArray()
    {
        _array = new T[capacity];
    }
    ~MyArray()
    {
        delete _array;
    }
    template<typename U>
    MyArray(const MyArray<U,capacity>& other)
    {
        if(std::is_convertible<U, T>::value) //Can implicitly convert
        {
            _array = new T[other.size()];
            int i = 0;
            for(U * ptr = other.begin(); ptr != other.end(); ++ptr)
            {
                _array[i++] = *ptr;
            }
        }
        else 
        {
            std::cout << "Unable to convert from " << typeid(U).name() << " to " << typeid(T).name() << std::endl;
        }        
    }
    template<typename U, std::size_t otherCapacity>
    MyArray<T, capacity>& operator=(const MyArray<U, otherCapacity>& rhs)
    {
        if(std::is_convertible<U, T>::value) //Can implicitly convert
        {
            int i = 0;
            for(U * ptr = rhs.begin(); ptr != rhs.end() && i < capacity; ++ptr)
            {
                _array[i++] = *ptr;
            }
        }
        else 
        {
            std::cout << "Unable to convert from " << typeid(U).name() << " to " << typeid(T).name() << std::endl;
        }
        return *this;  
    }
    void fill(const T& value);
    T * begin() const;
    T * end() const;
    T& operator[](int i)
    {
        if(i >= 0 && i < capacity)
        {
            return _array[i];
        }
    }
    const size_t size();
};

template<typename T, const std::size_t capacity>
void MyArray<T,capacity>::fill(const T& value)
{
    for(int i = 0; i < capacity; ++i)
    {
        _array[i] = value;
    }
}

template<typename T, const std::size_t capacity>
T * MyArray<T,capacity>::begin() const
{
    return _array;
}

template<typename T, const std::size_t capacity>
T * MyArray<T,capacity>::end() const
{
    return (T *) (&_array[capacity - 1]);
}

template<typename T, const std::size_t capacity>
const std::size_t MyArray<T,capacity>::size()
{
    return capacity;
}

template<typename T, typename U>
T* myfind(T* first, T* last, const U& v)
{
    for(T * i = first; i != last; ++i)
    {
        if(*i == v)
        {
            return i;
        }
    }
    return last;
}

//Pointer specialization
template<typename T, std::size_t capacity>
class MyArray<T*, capacity>
{
private:
    T ** _array;
public:
   MyArray()
    {
        _array = new T*[capacity];
        // for(int i = 0; i < 0; ++i) 
        // {

        // }
    }
    ~MyArray()
    {
        for(T ** i = begin(); i != end(); ++i) 
        {
            if(i != nullptr)
            {
                delete *i;
            }
        }
    }
    template<typename U>
    MyArray(const MyArray<U *,capacity>& other)
    {
        if(std::is_convertible<U, T>::value) //Can implicitly convert
        {
            _array = new T*[other.size()];
            int i = 0;
            for(U * ptr = other.begin(); ptr != other.end(); ++ptr)
            {
                _array[i++] = ptr;
            }
        }
        else 
        {
            std::cout << "Unable to convert from " << typeid(U).name() << " to " << typeid(T).name() << std::endl;
        }        
    }
    template<typename U, std::size_t otherCapacity>
    MyArray<T *, capacity>& operator=(const MyArray<U *, otherCapacity>& rhs)
    {
        if(std::is_convertible<U, T>::value) //Can implicitly convert
        {
            int i = 0;
            for(U ** ptr = rhs.begin(); ptr != rhs.end() && i < capacity; ++ptr)
            {
                _array[i++] = *ptr;
            }
        }
        else 
        {
            std::cout << "Unable to convert from " << typeid(U).name() << " to " << typeid(T).name() << std::endl;
        }
        return *this;  
    }
    // void fill(const T*& value);
    T ** begin() const;
    T ** end() const;
    T*& operator[](int i)
    {
        if(i >= 0 && i < capacity)
        {
            return _array[i];
        }
    }
    const size_t size();
};
//This function is dropped from the pointer implementation because it doesnt really make sense to fill a new array with pointers so the same object. 
// template<typename T, const std::size_t capacity>
// void MyArray<T *,capacity>::fill(const T*& value)
// {
//     for(int i = 0; i < capacity; ++i)
//     {
//         _array[i] = value;
//     }
// }

template<typename T, const std::size_t capacity>
T ** MyArray<T*,capacity>::begin() const
{
    return _array;
}

template<typename T, const std::size_t capacity>
T ** MyArray<T*,capacity>::end() const
{
    return &_array[capacity - 1];
}

template<typename T, const std::size_t capacity>
const std::size_t MyArray<T*,capacity>::size()
{
    return capacity;
}

template<typename T, typename U>
T** myfind(T** first, T** last, const U& v)
{
    for(T ** i = first; i != last; ++i)
    {
        if(**i == v)
        {
            return i;
        }
    }
    return last;
}







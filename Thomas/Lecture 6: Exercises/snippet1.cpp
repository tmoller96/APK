#include <cstring>
#include <iostream>
#include <string>

class Test
{
    /* Some code */
};

template <typename T, size_t N>
class MyArray
{
public:
    T &operator[](size_t i)
    {
        if (i >= N)
        {
            return T();
        }
        return data_[i];
    }

private:
    T data_[N];
};

/* Using */
void f()
{
    MyArray<Test, 10> my;
    Test t;
    my[5] = t;
}
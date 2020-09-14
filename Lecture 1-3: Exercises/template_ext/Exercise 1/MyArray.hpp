using namespace std;

template <typename T, const size_t capacity = 200>
class MyArray
{
private:
    T elements[capacity];
    int endIndex;

public:
    MyArray()
    {
        endIndex = 0;
    }
    ~MyArray() {}

    MyArray(const MyArray &arr)
    {
        arr = this;
    }

    void fill(const T &value)
    {
        endIndex = 0;
        for (int i = 0; i < capacity; i++)
        {
            elements[i] = value;
            endIndex++;
        }
    }

    T *begin() const;

    T *end() const;

    T &
    operator[](int i)
    {
        if (i <= endIndex || i >= 0)
        {
            return elements[i];
        }
        else
        {
            return elements[endIndex];
        }
    }

    template <typename U, const size_t otherCapacity>
    MyArray<T, capacity> &operator=(const MyArray<U, otherCapacity> &arr)
    {
        if (is_convertible<T, U>::value)
        {
            int index = 0;
            for (U *i = arr.begin(); i != arr.end(); i++)
            {
                elements[index++] = *i;

                if (index == endIndex)
                {
                    return *this;
                }
            }
        }

        else
        {
            cout << "Types cannot be converted" << endl;
        }

        return *this;
    }

    const size_t size()
    {
        return capacity;
    }
};

template <typename T, typename U>
T *myfind(T *first, T *last, const U &v)
{
    for (T *i = first; i != last; i++)
    {
        if (*i == v)
        {
            return i;
        }
    }

    return last;
}

template <typename T, const size_t capacity>
T *MyArray<T, capacity>::begin() const
{
    return elements;
}

template <typename T, const size_t capacity>
T *MyArray<T, capacity>::end() const
{
    return elements + capacity;
}
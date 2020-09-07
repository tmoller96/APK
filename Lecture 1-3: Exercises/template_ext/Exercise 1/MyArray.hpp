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

    void fill(const T &value)
    {
        endIndex = 0;
        for (int i = 0; i < capacity; i++)
        {
            elements[i] = value;
            endIndex++;
        }
    }

    T *begin()
    {
        return elements;
    }

    T *end()
    {
        return elements + capacity;
    }

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

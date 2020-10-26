class Test
{
    /* Some code */
};

template <typename T>
class MyVector
{
public:
    MyVector(size_t capacity)
        : capacity_(capacity), count_(0), data_(new T[capacity])
    {
    }

    bool full() const { return (count_ == capacity_); }

    void push_back(const T &oneMore)
    {
        if (full())
        {
            capacity_ *= 2;
            MyVector<T> temp(capacity);

            std::copy(data_, data_ + count_, temp.get());
            std::swap(data_, temp.get());
        }

        data_[count_] = oneMore;
        ++count_;
    }

private:
    size_t capacity_;
    size_t count_;
    T *data_;
};

/* Using */
void f()
{
    MyVector<Test> my(20);

    Test t;

    my.push_back(t);
}

// TODO: Ret dette lort igennem
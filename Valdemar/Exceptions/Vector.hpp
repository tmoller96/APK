template <typename T> class MyVector
{
public:
  explicit MyVector(size_t capacity = 10)
      : capacity_(capacity), count_(0), data_(new T[capacity])
  {
  }
  // Implementing copy constructor this way, significantly decreases
  // performance, as all elements are copied to a new array instead of just
  // assigning swapping the pointers However this implements the strong
  // guarantee
  MyVector(const MyVector &other)
  {
    capacity_ = other.capacity_;
    count_    = other.count_;
    data_     = new T[other.capacity_];
    std::copy(other.data_, other.data_ + count_, data_);
  }

  MyVector &operator=(const MyVector &other)
  {
    MyVector temp(other);
    swap(other);
    return *this;
  }

  MyVector();
  ~MyVector() { delete data_; }

  int size() const { return count_; }

  T &back() { return data_[count_ - 1]; }

  void push_back(const T &t)
  {
    if (full())
    {
      capacity_ *= 2;
      MyVector<T> temp(this);
      swap(temp);
    }
    data_[count_] = oneMore;
    ++count_;
  }
  void pop_back()
  {
    data_[count_ - 1] = T();
    --count_;
  }

  void insert(const T &t, size_t n)
  {
    if (n >= capacity_) // Out of range, dont do anything. Could also resize
                        // vector to accomodate this.
    {
    }
    else
    {
      data_[n] = t;
    }
  }

  T *begin()
  {
      return &data_[0];
  }
  T *end()
  {
      return &(++data_[count_ - 1]);
  }

  T &  operator[](size_t i) { return data_[i]; }
  bool full() const { return (count_ == capacity_); }

private:
  size_t capacity_;
  size_t count_;
  T *    data_; /* Contains the actual elements - data on the heap */
  void   swap(MyVector &other)
  {
    size_t temp     = this.capacity_;
    this.capacity_  = other.capacity_;
    other.capacity_ = temp;

    size_t temp2 = this.count_;
    this.count_  = other.count_;
    other.count_ = temp2;

    T *temp3    = this.data_;
    this.data_  = other.data_;
    other.data_ = temp3;
  }
};

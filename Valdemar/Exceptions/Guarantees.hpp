
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
class Test
{
public:
  Test() {}
  Test(const Test &other) {}
  void operator=(const Test &other) {}
};

template <typename T, size_t N> class MyArray
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
//----------------------------------------------------------------------------------------------------------

template <typename T> class MyVector
{
public:
  MyVector(size_t capacity)
      : capacity_(capacity), count_(0), data_(new T[capacity])
  {
  }
  MyVector(const MyVector &other)
  {
    capacity_ = other.capacity_;
    count_    = other.count_;
    data_     = new T[other.capacity_];
    std::copy(other.data_, other.data_ + count_, data_);
  }

  bool full() const { return (count_ == capacity_); }

  void push_back(const T &oneMore)
  {
    if (full())
    {
      capacity_ *= 2;
      MyVector<T> temp(this);
      swap(this, temp);
    }
    data_[count_] = oneMore;
    ++count_;
  }
  ~MyVector() { delete[] data_; }

private:
  void swap(MyVector &first, MyVector &second)
  {
    size_t temp      = first.capacity_;
    first.capacity_  = second.capacity_;
    second.capacity_ = temp;

    size_t temp2  = first.count_;
    first.count_  = second.count_;
    second.count_ = temp2;

    T *temp3     = first.data_;
    first.data_  = second.data_;
    second.data_ = temp3;
  }
  size_t capacity_;
  size_t count_;
  T *    data_;
};

/* Using */
void f()
{
  MyVector<Test> my(20);

  Test t;

  my.push_back(t);
}

//-----------------------------------------------------------------------------------------------------------------------

class String
{
public:
  String() : s_(nullptr) {}

  String(const char *s) : s_(new char[strlen(s) + 1]) { std::strcpy(s_, s); }

  String(const String &other) : s_(new char[strlen(other.s_) + 1])
  {
    std::strcpy(s_, other.s_);
  }

  String &operator=(const String &other)
  {
    String temp(other);
    swap(*this, temp);
  }
  void swap(String &first, String &second)
  {
    char *temp = first.s_;
    first.s_   = second.s_;
    second.s_  = temp;
  }

  String() { delete[] s_; }

private:
  char *s_;
};

/* Using */
void f()
{
  String s("Hello world");

  String aCopy(s);

  s = "Hello girls";
}

//-----------------------------------------------------------------------------------------------------------------
class Blob
{
};
class Key
{
  public:
  bool isValid() {
    return true;
  }
  const std::string id() {
    return "asdafas13124g1yg2v3t1yv23hgv12";
  }
};
class InvalidKey : public std::exception
{
public:
  InvalidKey(const std::string id);
};
class DataSet
{
public:
  DataSet(Key *key, Blob *blob) : key_(key), blob_(blob)
  {
    if (!key->isValid()) throw InvalidKey(key->id());
  }

  void overWrite(const Key *key, const Blob *blob)
  {
    //With this implementation we could risk that only one is actually overwritten. Maybe we could make a try-catch all and roll back changes?

    *key_  = *key;
    *blob_ = *blob;
  }
  DataSet()
  {
    delete key_;
    delete blob_;
  }

private:
  Key * key_;
  Blob *blob_;
};

/* Using */
void f()
{
  Key * key = new Key();
  Blob * blob = new Blob();
  DataSet ds(key, blob);
  //When creating this scope the created objects will go out of scope, after the DB is overwritten, this will essentially cause a wipe of the database. 
  //Instead here probably should use a shared_ptr or some other mechanism for allocating objects. 
  {
    Key  k(getKeyValue());
    Blob b(fetchDBBlobByKey(k));

    ds.overWrite(&k, &b);
  }
}
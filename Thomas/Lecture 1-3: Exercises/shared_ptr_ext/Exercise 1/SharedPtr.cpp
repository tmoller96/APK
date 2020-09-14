#include <iostream>

using namespace std;

template <typename T>
class SharedPtr
{
private:
  int count;

public:
  SharedPtr(T *t);
  SharedPtr(const SharedPtr &);
  ~SharedPtr();
};

template <typename T>
SharedPtr::SharedPtr(T *t)
{
}

SharedPtr::~SharedPtr()
{
}

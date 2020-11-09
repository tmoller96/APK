#include <iostream>
class Copyable
{
public:
  Copyable(int someInt, std::string someString)
      : _someInt(someInt), _someString(someString)
  {
    std::cout << "Constructor called" << std::endl;
  }

  Copyable(const Copyable &other)
      : _someString(other._someString), _someInt(other._someInt)
  {
    std::cout << "Copy constructor called" << std::endl;
  }

  // Add move semantics
  Copyable(Copyable &&other) noexcept
      : _someString(std::move(other._someString)),
        _someInt(other._someInt)
  {
      std::cout << "Move constructor called" << std::endl;
  }

  Copyable &operator=(Copyable &&rhs) noexcept
  {
      _someString = std::move(rhs._someString);
      _someInt = rhs._someInt;
      std::cout << "Move assignment called!" << std::endl;
      return *this;
  }

  Copyable &operator=(const Copyable &rhs)
  {
    _someInt    = rhs._someInt;
    _someString = rhs._someString;
    std::cout << "Assignment operator called" << std::endl;
    return *this;
  }
  ~Copyable() { std::cout << "Destructor called" << std::endl; }
  int test = 42;

private:
  int         _someInt;
  std::string _someString;
};
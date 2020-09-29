#include <string>
class MyClass
{
private:
  std::string _myString;
  int    _myInt;
  long   _myLong;

public:
  MyClass(std::string s, int i, long l) : _myString(s), _myInt(i), _myLong(l) {}
  friend std::ostream &operator<<(std::ostream & oStream, const MyClass &myClass);
};

std::ostream& operator<<(std::ostream& os, const MyClass &myClass)
{
    os << myClass._myString << myClass._myInt << myClass._myLong;
    return os;
}
#include <vector>

class CustomVectorClass
{
public:
  CustomVectorClass()
  {
    _randomDouble = 10.03231;
    _randomInt    = 103124;
    _data         = new char[20];
  }

  ~CustomVectorClass() { delete _data; }

private:
  int    _randomInt;
  double _randomDouble;
  char * _data;
};

class CustomClass
{
public:
  CustomClass() {}
    void add(CustomVectorClass& obj) 
    {
        objects.push_back(obj);
    }
private:
  std::vector<CustomVectorClass> objects;
};

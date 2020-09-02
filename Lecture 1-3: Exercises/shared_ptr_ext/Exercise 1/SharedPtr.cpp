#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;

int main(int argc, char *argv[])
{
  boost::shared_ptr<string> obj1(new string("Hello world"));
  boost::shared_ptr<string> obj2(new string("Goodbye world"));

  //Test af assignment operator
  obj2 = obj1;

  //Test af copy constructor
  boost::shared_ptr<string> obj3(obj1);

  boost::shared_ptr<string> obj4(new string("Hello moon"));
  obj1 = obj4;

  if (obj1->find("world") != string::npos)
  {
    cout << "The 'obj1' string does contain 'world'" << endl;
  }

  else
  {
    cout << "The 'obj1' string does NOT contain 'world'" << endl;
  }

  if (obj1->find("moon") != string::npos)
  {
    cout << "The 'obj1' string does contain 'moon'" << endl;
  }

  else
  {
    cout << "The 'obj1' string does NOT contain 'moon'" << endl;
  }

  if (obj2->find("Goodbye") != string::npos)
  {
    cout << "The 'obj2' string does contain 'Goodbye'" << endl;
  }

  else
  {
    cout << "The 'obj2' string does NOT contain 'Goodbye'" << endl;
  }

  if (obj2->find("Hello") != string::npos)
  {
    cout << "The 'obj2' string does contain 'Hello'" << endl;
  }

  else
  {
    cout << "The 'obj2' string does NOT contain 'Hello'" << endl;
  }

  if (obj3->find("Hello") != string::npos)
  {
    cout << "The 'obj3' string does contain 'Hello'" << endl;
  }

  else
  {
    cout << "The 'obj3' string does NOT contain 'Hello'" << endl;
  }
}

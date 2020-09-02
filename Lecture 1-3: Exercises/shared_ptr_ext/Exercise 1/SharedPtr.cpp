#include <boost/shared_ptr.hpp>
#include <iostream>
using namespace std;
int main(int argc , char* argv [])
{
  boost::shared_ptr<int> a;
  boost::shared_ptr<int> b(new int(102));
  cout << "B: " << endl;
  cout << *b << "\t" << b.use_count() << endl;
  boost::shared_ptr<int> c(new int(14));
  cout << "C: " << endl;
  cout << *c << "\t" << c.use_count() << endl;
  cout << "Assigning a to b" << endl;
  a = b;
  cout << *a <<"\t" << a.use_count() << endl;
  boost::shared_ptr<int> d(a);
  cout << "Copy contructor for D using A: " << endl;
  cout << *d << "\t" << a.use_count() << endl;
  cout << "Resetting A: " << endl;
  a.reset();
  cout << "\t" << a.use_count() << endl;
}

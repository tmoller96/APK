#include <iostream>
#include <vector>
#include <string>
#include "SharedPtr.hpp"

using namespace std;

int main()
{
    SharedPtr<string> sp(new string("Hello world"));
    if(sp)
        cout << "SP Contains " << *sp << endl;

    SharedPtr<string> sp2;
    sp2 = sp;
    if(sp == sp2)
    {
        cout << "sp == sp2" << endl;
    }
    else 
    {
        cout << "sp != sp2" << endl;
    }
    
}
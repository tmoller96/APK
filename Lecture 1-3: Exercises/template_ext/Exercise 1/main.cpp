#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    MyArray<double, 100> arr;
    cout << arr.size() << endl;
    arr.fill(9.0);
    cout << arr.size() << endl;
    cout << arr[9] << endl;

    cout << *arr.begin() << endl;
    cout << *arr.end() << endl;
    cout << arr.size() << endl;

    arr[3] = 3.0;
    cout << arr[3] << endl;

    cout << "Looking for '3'? " << (myfind(arr.begin(), arr.end(), 3) != arr.end() ? "found" : "sry no") << std::endl;

    MyArray<int, 10> intArr;
    MyArray<double, 10> doubleArr;

    intArr.fill(6);
    intArr[2] = 10;
    intArr[9] = 69;

    doubleArr = intArr;

    cout << doubleArr[1] << doubleArr[2] << doubleArr[9] << endl;

    return 0;
}

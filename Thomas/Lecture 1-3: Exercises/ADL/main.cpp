#include <iostream>
#include <string>

// void f(int)
// {
//     std::cout << "f( int )" << std::endl;
// }
// class base
// {
// public:
//     void f(long) { std::cout << "f( long )" << std::endl; }
// };

// class derived : public base
// {
// public:
//     void f(short) { std::cout << "f( short )" << std::endl; }
//     void g() { f(42); }
// };

// namespace BigMath
// {
//     class BigNumber
//     {
//     };

//     bool operator<(const BigNumber &, const BigNumber &);

// } /* namespace BigMath */

// void g(const BigMath::BigNumber &a,
//        const BigMath::BigNumber &b)
// {
//     BigMath::BigNumber x = std::max(a, b);
// }

// namespace N
// {
//     class T
//     {
//     public:
//         T() {}
//     };
//     void f(T &) { std::cout << " Namespace N" << std::endl; }
// } /* namespace N */

// namespace R
// {
//     void f(N::T &) { std::cout << " Namespace R" << std::endl; }
//     void adl()
//     {
//         N::T t;
//         f(t); /* <<<—— */
//     }
// } // namespace R

// int main()
// {
//     derived d;
//     d.g();
// }

// template <typename T, int capacity = 200>
// class Stack
// {
// public:
//     Stack() : top_(0) {}
//     bool empty() { return top_ == 0; }
//     void push(const T &t) { elem_[top_++] = t; }
//     T pop() { return elem_[top_]; }

// private:
//     T elem_[capacity];
//     int top_;
// };

// class Person
// {
// public:
//     /* Implicit defaultconstructor
// */
//     Person(const std::string &str = "John Doe");

//     /* Person(const Person& other); */
//     /* Person& operator=(const Person& other); */
// };

// Template class
template <typename T>
class Spunky
{
public:
    Spunky(T x)
    {
        std::cout << x << " is not a character nor a pointer!" << std::endl;
    }
};

// Partial specialised - Takes all pointers
template <typename T>
class Spunky<T *>
{
public:
    Spunky(T *x)
    {
        std::cout << x << " is indeed a pointer!" << std::endl;
    }
};

// Full specialised - Takes charactors
template <>
class Spunky<char>
{
public:
    Spunky(char x)
    {
        std::cout << x << " is indeed a character!" << std::endl;
    }
};

int main()
{
    Spunky<int> s1(4);
    Spunky<double> s2(4.5);
    Spunky<char> s3('q');

    int r = 5;
    int *ptr_r = &r;

    Spunky<int *> s4(ptr_r);
}

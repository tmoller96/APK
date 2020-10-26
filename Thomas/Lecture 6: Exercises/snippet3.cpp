#include <cstring>
#include <iostream>
#include <string>

class String
{
public:
    String() : s_(nullptr) {}

    String(const char *s) : s_(new char[strlen(s) + 1])
    {
        std::strcpy(s_, s);
    }

    String(const String &other)
        : s_(new char[strlen(other.s_) + 1])
    {
        std::strcpy(s_, other.s_);
    }

    String &operator=(const String &other)
    {
        delete[] s_;
        s_ = new char[strlen(other.s_) + 1];
        std::strcpy(s_, other.s_);
        return *this;
    }

    ~String()
    {
        delete[] s_;
    }

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
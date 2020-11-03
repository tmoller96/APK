#include <iostream>
void ya_printf(const char *s)
{
  while (*s)
  {
    if (*s == '%')
    {
      if (*(s + 1) == '%')
      {
        ++s;
      }
      else
      {
        throw std::runtime_error("invalid format string: missing arguments");
      }
    }
    std::cout << *s++;
  }
}

template <typename T, typename... Args>
void ya_printf(const char *s, T value, Args... args)
{
  while (*s)
  {
    if (*s == '%')
    {
      if (*(s + 1) == '%')
      {
        ++s;
      }
      else
      {
        std::cout << value;
        if constexpr (sizeof... (args) == 0)
        {
          ya_printf(s + 1);
        }
        else
        {
          ya_printf(s + 1, args...);
        }

        // call even when *s == 0 to detect extra arguments
        return;
      }
    }
    std::cout << *s++;
  }
  throw std::logic_error("extra arguments provided to printf");
}

int main() {
    int s1 = 10;
    int s2 = 203;
    ya_printf("Sensor values %, %", s1, s2);
}
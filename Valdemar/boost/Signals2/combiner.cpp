#include <iostream>
double sum(double first, double second, double third)
{
  return first + second + third;
}

double mean(double first, double second, double third)
{
  return sum(first, second, third) / 3;
}

double product(double first, double second, double third)
{
  return first * second * third;
}

double subtract(double first, double second, double third)
{
  return first - second - third;
}

template <typename T> struct meanCombiner
{
  typedef T result_type;
  template <typename InputIterator>
  T operator()(InputIterator first, InputIterator last) const
  {
    T   sum         = *first++;
    int numElements = 0;
    if (first == last) return T();
    for (; first != last; ++first)
    {
      sum += *first;
      ++numElements;
    }
    return sum / numElements;
  }
};

#include <boost/signals2.hpp>
int main()
{
  boost::signals2::signal<double(double, double, double), meanCombiner<double>>
      sig;
  sig.connect(&mean);
  sig.connect(&product);
  sig.connect(&subtract);
  sig.connect(&sum);
  std::cout << "Mean value from combiner: " << sig(10.32, 103.32, -0.2) << std::endl;
}
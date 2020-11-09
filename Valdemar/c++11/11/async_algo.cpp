#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <iterator>
#include <vector>
#include <pthread.h>

class Algo
{
public:
  Algo(std::vector<int> v) : data_(std::move(v)) {}

  void doAlgo()
  {
    std::chrono::time_point<std::chrono::high_resolution_clock> commence =
        std::chrono::high_resolution_clock::now();
    std::sort(data_.begin(), data_.end());
    std::chrono::time_point<std::chrono::high_resolution_clock> complete =
        std::chrono::high_resolution_clock::now();
    duration_ = std::chrono::nanoseconds(complete - commence);
  }

  std::chrono::duration<long double> processingTime() { return duration_; }

  void print()
  {
    std::copy(data_.begin(), data_.end(),
              std::ostream_iterator<int>(std::cout, " "));
  }

private:
  Algo(const Algo &) = delete; // No copy construction is allowed

  Algo &operator=(const Algo &) = delete; // No copy assignment is allowed

  std::vector<int>         data_;
  std::chrono::nanoseconds duration_;
};

typedef Algo SmartAlgo;
typedef Algo CoolAlgo;
typedef Algo FantasticAlgo;

int main(int argc, char *argv[])
{
  int i = 0;
  int n = 10000000; // Change at your leasure

  std::vector<int> data;
  data.reserve(n);
  generate_n(back_inserter(data), n, [&i]() { return i++; });
  random_shuffle(data.begin(), data.end());

  std::future<std::shared_ptr<SmartAlgo>> smartAlgoFuture = std::async(
      std::launch::async,
      [](std::vector<int> data) -> std::shared_ptr<SmartAlgo> {
        SmartAlgo *algo = new SmartAlgo(data);
        algo->doAlgo();
        return std::shared_ptr<SmartAlgo>(algo);
      },
      data);
  std::future<std::shared_ptr<CoolAlgo>> coolAlgoFuture = std::async(
      std::launch::async,
      [](std::vector<int> data) -> std::shared_ptr<CoolAlgo> {
        CoolAlgo *algo = new CoolAlgo(data);
        algo->doAlgo();
        return std::shared_ptr<CoolAlgo>(algo);
      },
      data);
  std::future<std::shared_ptr<FantasticAlgo>> fantasticAlgoFuture = std::async(
      std::launch::async,
      [](std::vector<int> data) -> std::shared_ptr<FantasticAlgo> {
        FantasticAlgo *algo = new FantasticAlgo(data);
        algo->doAlgo();
        return std::shared_ptr<FantasticAlgo>(algo);
      },
      data);
  smartAlgoFuture.wait();
  coolAlgoFuture.wait();
  fantasticAlgoFuture.wait();

  std::cout << "Result from smart algo: " << smartAlgoFuture.get()->processingTime().count() << std::endl; 
  std::cout << "Result from cool algo: " << coolAlgoFuture.get()->processingTime().count() << std::endl; 
  std::cout << "Result from fantastic algo: " << fantasticAlgoFuture.get()->processingTime().count() << std::endl; 
  return 0;
}

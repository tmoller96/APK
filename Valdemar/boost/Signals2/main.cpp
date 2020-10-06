#include <boost/signals2.hpp>
#include <iostream>
void printSignal(const std::string &name, double value)
{
  std::cout << "From free function" << std::endl;
  std::cout << "Sensor name: " << name << std::endl;
  std::cout << "Sensor value: " << value << std::endl;
}

class PrintFunctor
{
public:
  void operator()(const std::string &name, double value)
  {
    std::cout << "From functor" << std::endl;
    std::cout << "Sensor name: " << name << std::endl;
    std::cout << "Sensor value: " << value << std::endl;
  }
};

class SensorOutput
{
public:
  void printSensorOutput(const std::string &name, const double value) const
  {
    std::cout << "From function inside class" << std::endl;
    std::cout << "Sensor name: " << name << std::endl;
    std::cout << "Sensor value: " << value << std::endl;
  }
};

int main()
{
  boost::signals2::signal<void(const std::string &, double)> sig;
  sig.connect(&printSignal);
  sig.connect([](const std::string &name, double value) -> void {
    std::cout << "From lambda:" << std::endl;
    std::cout << "Sensor name: " << name << std::endl;
    std::cout << "Sensor value: " << value << std::endl;
  });
  PrintFunctor functor;
  sig.connect(functor);
  SensorOutput output = SensorOutput();
  //Using bind:
  sig.connect(boost::bind(&SensorOutput::printSensorOutput, output, _1, _2));
  //Using lamda:
  sig.connect([output](const std::string& name, double value) -> void {
      output.printSensorOutput(name, value);
  });
  sig("Humidity sensor", 90.32);
}
#include <iostream>
#include <vector>
#include <boost/signals2.hpp>

void doStuff(const std::string& sensorName, double sensor) 
{
    std::cout << "\nFree function: " << "Sensor: " << sensorName << ", value: " << sensor << std::endl;
}

struct Sensor{
  void operator()(const std::string& sensorName, double sensor){
    std::cout << "\nFunctor: " << "Sensor: " << sensorName << ", value: " << sensor << std::endl;
  }
};

class Meter {
  
public:  

  void getData(double sensor, const std::string& sensorName){// opposite order from expected - need to reorder the _1 and _2 in boost::bind
    std::cout << "\nMeter getting data: " << sensorName << ", value: " << sensor << "\n" << std::endl;
  }

};

int main()
{
  // create signal
  boost::signals2::signal<void (const std::string&, double)> sig;

  // connect slot to signal
  sig.connect(&doStuff);

  sig.connect(Sensor());

  sig.connect([](const std::string& sensorName, double sensor)
  {
    std::cout << "\nLambda: " << "Sensor: " << sensorName << ", value: " << sensor << std::endl;
  });

  // connect to member function of an obj reference
  // bind: 
  Meter meter;
  // OR
  // https://stackoverflow.com/questions/16525649/using-boost-signals2-how-do-i-connect-dynamically-allocated-objects-to-a-signal
  // auto meter = std::make_shared<Meter>(); // så skal objektet ikke være by reference
  sig.connect(boost::bind(&Meter::getData, &meter, _2, _1));
  
  // lambda:
  sig.connect([&meter](auto a, auto b) { 
    std::cout << "_Lambda member function:_\n";
    meter.getData(b,a);
  });
  
  // signal slot with parameters
  sig("Water sensor", 30);

  return 0;
}
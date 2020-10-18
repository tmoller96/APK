/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

// bindanyfunction.cpp : Defines the entry point for the console application.
//

#include "Events.cpp"
#include "Events.hpp"
#include "Functor.hpp"
#include "Timer.cpp"
#include "Timer.hpp"
#include <functional>
#include <iostream>
#include <mutex>
#include <string>

std::mutex stdioProt;
using namespace std::placeholders;
void freeFunction(const std::shared_ptr<Event> &event)
{
  // Protecting stdio since its not thread safe
  std::lock_guard<std::mutex> lock(stdioProt);
  auto isOtherEvent = std::dynamic_pointer_cast<EventOther>(event);
  if (isOtherEvent)
  {
    std::cout << "Is other event: "
              << *isOtherEvent.get()
              << std::endl;
  }
  else
  { // Is base
    std::cout << "Is base event: " << *event.get() << std::endl;
  }
}

void withAnExtra(const std::shared_ptr<Event> &event, const std::string text)
{
  // Protecting stdio since its not thread safe
  std::lock_guard<std::mutex> lock(stdioProt);

  auto isOtherEvent = std::dynamic_pointer_cast<EventOther>(event);
  if (isOtherEvent)
  {
    std::cout << "Is other event: "
              << *isOtherEvent.get()
              << std::endl;
  }
  else
  { // Is base
    std::cout << "Is base event: " << *event.get() << std::endl;
  }
  std::cout << "Extra argument: " << text << std::endl;
}

class ReferenceObj
{
public:
  ReferenceObj() : called_(0) {}

  void call(const std::shared_ptr<Event> &event)
  {
    // Protecting stdio since its not thread safe
    std::lock_guard<std::mutex> lock(stdioProt);

    ++called_;
    std::cout << "From inside reference object. Called " << called_ << " times" << std::endl;
  }

  int gotCalled() { return called_; }

private:
  int called_;
};

int main()
{
  // Try to make several timers with different callbacks
  Timer t1(4);
  t1.attach(freeFunction);

  FunctorTest test;
  auto functorLambda = [&test](const std::shared_ptr<Event> &event) -> void { test(event); };
  t1.attach(functorLambda);

  auto boundWithExtraParams = std::bind(withAnExtra, _1, "With an extra argument");
  t1.attach(boundWithExtraParams);

  ReferenceObj ref = ReferenceObj();
  auto referenceObjectCallback = std::bind([&ref](const std::shared_ptr<Event> &event) { ref.call(event); }, _1);
  t1.attach(referenceObjectCallback);
  // The threads run naturally in the background (no clean up has been added for
  // the threads)

  // You might wanna change the loop below such that you can extract the value
  // of called_
  //  from your instance of ReferenceObj
  for (;;)
  {
    std::chrono::milliseconds sleepFor(1000);
    std::this_thread::sleep_for(sleepFor);
  }

  return EXIT_SUCCESS;
}

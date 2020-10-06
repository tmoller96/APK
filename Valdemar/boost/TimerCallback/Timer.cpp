#include "Timer.hpp"
#include "Events.hpp"
#include <iostream>
#include <thread>
#include <pthread.h>

Timer::Timer(int timer) : eventTimer_(timer), terminator_(false)
{
  thread_     = new std::thread(std::bind(&Timer::timerThreadFunction, this));
  latestCbId_ = 0;
  callbacks_ =
      new std::map<int, cbSign>();
}

Timer::~Timer()
{
  terminator_ = true;
  thread_->join();
  delete thread_;
  if (callbacks_ != nullptr) delete callbacks_;
}

int Timer::timerThreadFunction()
{
  int counter = 0;
  while (!terminator_)
  {
    std::chrono::milliseconds sleepFor(1000);
    std::this_thread::sleep_for(sleepFor);

    notifyAll(std::make_shared<Event>());
    if (++counter >= eventTimer_)
    {
      counter = 0;
      std::cout << "EventOther created..." << std::endl;

      notifyAll(std::make_shared<EventOther>());
    }
  }
  return 0;
}

int Timer::attach(Timer::cbSign callback)
{
  std::pair<int, Timer::cbSign> p = std::make_pair(
          ++latestCbId_, callback);
  callbacks_->insert(p);
  return latestCbId_;
}

void Timer::detach(int cbId) {
  callbacks_->erase(cbId);
}

void Timer::notifyAll(std::shared_ptr<Event> event)
{
  for(std::map<int, Timer::cbSign>::iterator start = callbacks_->begin(); start != callbacks_->end(); ++start)
  {
    start->second(event);
  }
}
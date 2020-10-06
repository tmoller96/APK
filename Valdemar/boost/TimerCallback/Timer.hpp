#ifndef TIMER_HPP_
#define TIMER_HPP_
#include <string>
#include <map>
#include <thread>
#include <functional>
#include <chrono>
#include "Events.hpp"

class Timer
{
public:
typedef std::function<void (const std::shared_ptr<Event>&)> cbSign;
  explicit Timer( int timer = 10);
  int attach(Timer::cbSign);
  void detach(int);
  void notifyAll(std::shared_ptr<Event> data);
  ~Timer();  
  
private:
  int  timerThreadFunction();
  
private:
  int           eventTimer_;
  std::thread*	thread_;
  bool          terminator_;	
  std::map<int, Timer::cbSign> * callbacks_;
  int latestCbId_;
};






#endif

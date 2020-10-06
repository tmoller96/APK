/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

// bindanyfunction.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <mutex>
#include <functional>
#include "Events.hpp"
#include "Timer.hpp"
#include "Timer.cpp"
#include "Events.cpp"

std::mutex stdioProt;


void freeFunction( const std::shared_ptr<Event>& event )
{
   // Protecting stdio since its not thread safe
  std::lock_guard<std::mutex> lock(stdioProt );
  auto isOtherEvent = std::dynamic_pointer_cast<EventOther>(event);
  if(isOtherEvent)
  {
    std::cout << "Is other event: " << isOtherEvent.get()->creationTime().time_since_epoch().count() << std::endl;
  }
  else { //Is base
  std::cout << "Is base event: " << event.get()->creationTime() << std::endl;
  }
    
}


void withAnExtra(const std::shared_ptr<Event>& event, const std::string text)
{
   // Protecting stdio since its not thread safe
  std::lock_guard<std::mutex> lock(stdioProt);

  // auto isOtherEvent = std::dynamic_pointer_cast<EventOther>(event);

}


class ReferenceObj
{
public:
   ReferenceObj() : called_(0) 
   {
   }

  void call( const std::shared_ptr<Event>& event )
  {
    // Protecting stdio since its not thread safe
    std::lock_guard<std::mutex> lock(stdioProt );

    /* MISSING EVENT PRINT OUT */
    
    ++called_;
  }

   int gotCalled()
   {
      return called_;
   }
  
private:
   int   called_;
};



int main()
{
  // Try to make several timers with different callbacks
  Timer t1( 4 );
  t1.attach( freeFunction );



  // The threads run naturally in the background (no clean up has been added for the threads)

   
  // You might wanna change the loop below such that you can extract the value of called_
  //  from your instance of ReferenceObj
  for(;;)
  {
    std::chrono::milliseconds sleepFor(1000);
    std::this_thread::sleep_for(sleepFor);
  }
   

  return EXIT_SUCCESS;
}

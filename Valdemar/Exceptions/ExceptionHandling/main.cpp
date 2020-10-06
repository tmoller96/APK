
#include "logfile.cpp"
#include "logfile.hpp"
#include <iostream>
using namespace std;

int main()
{
  {
    LogFile dummy;
    try
    {
      dummy.write("Writing from main");
    }
    catch (LogFileException e)
    {
      switch (e.getState())
      {
      case LogFileException::EState::es_FILENAME_IS_EMPTY:
        cerr << "Dummy not initialized" << endl;
        break;
      case LogFileException::EState::es_COULD_NOT_OPEN_FILE:
        cerr << "Could not open Dummy" << endl;
        break;
      }
    }
  }
  try
  {
    LogFile logFile("Exceptions.log");
    logFile.write("Writing from main");
    logFile.write("Writing from main - again");
  }
  catch (LogFileException e)
  {
    switch (e.getState())
    {
    case LogFileException::EState::es_FILENAME_IS_EMPTY:
      cerr << "File not initialized" << endl;
      break;
    case LogFileException::EState::es_COULD_NOT_OPEN_FILE:
      cerr << "Could not open File" << endl;
      break;
    }
  }
}

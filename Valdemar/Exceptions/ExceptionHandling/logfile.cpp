
#include <iostream>
#include <fstream>
using namespace std;

#include "logfile.hpp"
#include "LogFileException.hpp"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LogFile::LogFile()
{
	cout << "Creating LogFile Object" << endl;
}

LogFile::LogFile( const string& logfilename )
{
	init( logfilename );
}

LogFile::~LogFile()
{
	cout << "Deleting LogFile Object" << endl;
}

void LogFile::init( const string& logfilename )
{
	logfilename_ = logfilename;
	internalWrite( "" );
}

void LogFile::write( const string& data )
{
	internalWrite( data+"\n" );
}

void LogFile::internalWrite( const string& data )
{
	if( logfilename_ == "" )
	{
		throw LogFileException(LogFileException::EState::es_FILENAME_IS_EMPTY, "Filename was empty");
	}
	std::ofstream out;
	out.open( logfilename_.c_str(), std::ofstream::out | std::ofstream::app);
	if( out )
		out << data;
	else
	{
		throw LogFileException(LogFileException::EState::es_COULD_NOT_OPEN_FILE, "Could not open file");
	}
	out.close();
}


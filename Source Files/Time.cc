#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

/*
Purpose: Collection class to store the specific time in which a call occured.

Complex or Critical members:

greaterThan(Time* t): Returns true if 'this' Time object appears later in time than the Time object stored in the function parameter, false otherwise.

print(): Prints out the data members in the specified format: 'hours:minutes, '
*/

Time::Time(int h, int m)
{
  setTime(h, m);
}

void Time::setTime(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

bool Time::greaterThan(Time* t)
{
  return convertToMins() > t->convertToMins();
}

int Time::convertToMins() 
{
  return (hours*60 + minutes);

}

void Time::print() 
{
	cout<<setfill('0')<<setw(2)<<hours<<":"
		<<setfill('0')<<setw(2)<<minutes<<",  ";
}

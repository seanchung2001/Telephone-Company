#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

/*
Purpose of Date.cc: Used in the Call's collection class. Used to specify the date in which each call occured.

Complex or critical members:

greaterThan(Date* d): Calculates if the 'this' Date object is later in date then the Date object specified in the function parameter. Returns true if 'this' date occurs later, false otherwise.

print(): Prints out the data members for the Date object in this specified format: 'year-month-day '
*/

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date()
{

}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

void Date::print()
{
	cout<<setfill('0')<<setw(4)<<year<<"-"<<setfill('0')<<setw(2)<<month<<"-"<<setfill('0')<<setw(2)<<day<<" ";
}


int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = { 
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

bool Date::greaterThan(Date* d)
{
	//Checks up until the start time.
	if(this->year == d->year){
		if(this->month == d->month){
			if(this->day == d->day){
				return false;
			}
			else if(this->day < d->day){
				return false;
			}
			else{
				return true;
			}
		}
		else if(this->month < d->month){
			return false;
		}
		else{
			return true;
		}
	}
	else if(this->year < d->year){
		return false;
	}
	else{
		return true;
	}
}

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Call.h"

/*
Purpose of Call.cc: Collection class that stores all information for each Call that is made in the Telco class (Does not have to be specifically the Telco class, will work for other classes but for this program, it is specifically meant for the Telco class). Stores; Date in which the call occured, Time in which the call occured, the source phone number, the destination phone number, and the duration of the call.

Complex or critical members:

greaterThan(Call* c): Calculates if 'this' Call object occurs later in Date and Time then the Call object specified in the function parameter. This function will return true if 'this' Call object occurs later, and false otherwise.

print(): Prints out the data members for 'this' Call object in the specified format: 'year-month-day hours:minutes, mins From: src To: dest'

~Call: fress the dynamically allocated Date and Time objects stored in each Call object.

getSrc(): Returns data member 'src' in the Call object.

getDest(): Returns data member 'dest' in the Call object.
*/

Call::Call(string s, string d, int dura, int day, int month, int y, int h, int m)
{
	src = s;
	dest = d;
	duration = dura;
	date = new Date(day, month, y);
	time = new Time(h, m);
}

Call::~Call()
{
	delete date;
	delete time;
}

bool Call::greaterThan(Call* c)
{
	if(date == c->date){
		if(time->greaterThan(c->time) == true){
			return true;
		}
		else{
			return false;
		}
	}
	if(date->greaterThan(c->date) == true){
		return true;
	}
	else{
		return false;
	}
}

void Call::print()
{
	date->print();
	time->print();
	cout<<duration<<" mins: From: "<<src<<" To: "<<dest<<endl;
}

string Call::getSrc()
{
	return this->src;
}

string Call::getDest()
{
	return this->dest;
}

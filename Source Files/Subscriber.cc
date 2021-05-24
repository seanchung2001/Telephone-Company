#include <iostream>
using namespace std;

#include "Subscriber.h"

/*
Purpose of Subsriber.cc: Collection class that stores a subscriber corresponding to the Telco's array of subscribers. Stores the subscribers phone number, as well as two Array objects. The first Array object stores all of the subscribers incoming calls, the other stores all of the subscribers outgoing calls(calls made from the subscriber to another person).

Complex or critical members:

addIncoming(Call* c): Adds the Call object specified in the function parameter to the incoming calls (inCalls) Array object.

addOutgoing(Call* c): Adds the Call object specified in the function parameter to the outgoing calls (outCalls) Array object.

getPhoneNum(): returns the phoneNum member function (subscribers phone number).

getInCalls(int i): returns the Call object that is stored in the 'inCalls' Array object at the specified index. (Calls on Array classes get() function).

getOutCalls(int i): returns the Call object that is stored in the 'outCalls' Array object at the specified index. (Calls on Array classes get() function).

getInCallsSize(): returns the number of Call pointers that are stored in the inCalls Array object.

getOutCallsSize(): returns the number of Call pointers that are stored in the outCalls Array object.

print(): Prints out all the member functions stored in 'this' Subscriber. Starts by printing the phone number, then prints out every Call that is stored in both Array objects.
*/

Subscriber::Subscriber(string s)
{
	phoneNum = s;
}

void Subscriber::addIncoming(Call* c)
{
	this->inCalls.add(c);
}

void Subscriber::addOutgoing(Call* c)
{
	this->outCalls.add(c);
}

void Subscriber::print()
{
	cout<<"Subscriber "<<phoneNum<<":"<<endl;
	
	Array temp(inCalls);
	temp.add(outCalls);
	temp.print();
}

string Subscriber::getPhoneNum()
{
	return phoneNum;
}

Call* Subscriber::getInCalls(int i)
{
	return inCalls.get(i);
}

Call* Subscriber::getOutCalls(int i)
{
	return outCalls.get(i);
}

int Subscriber::getInCallsSize()
{
	return inCalls.getSize();
}

int Subscriber::getOutCallsSize()
{
	return outCalls.getSize();
}

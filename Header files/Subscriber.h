#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#define MAX_ARR 64

#include "Array.h"

class Subscriber
{
  public:
		Subscriber(string="0000000000");
		void addIncoming(Call*);
		void addOutgoing(Call*);
		void print();
		string getPhoneNum();
		Call* getInCalls(int);
		Call* getOutCalls(int);
		int getInCallsSize();
		int getOutCallsSize();
		

  private:
		string phoneNum;
		Array inCalls;
		Array outCalls;
};

#endif

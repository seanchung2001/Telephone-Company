#ifndef TELCO_H
#define TELCO_H

#define MAX_ARR 64

#include "Array.h"
#include "Subscriber.h"
#include "Call.h"

class Telco
{
  public:
  	Telco(string="unspecified");
  	~Telco();
  	void addSub(Subscriber*);
  	void addCall(string, string, int, int, int, int, int, int);
  	void computeFreqCaller(string);
  	void computeFreqCalled(string);
  	void mostFreqSub(Subscriber**, int*);
  	void print();
  	
  	
  private:
  	string name;
  	Array* allCalls;
  	Subscriber* subscribers[MAX_ARR];
  	int numSubs;
};

#endif

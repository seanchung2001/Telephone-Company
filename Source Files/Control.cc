#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

/*
Purpose of Control.cc: Initializes all of the data that is needed to test our program. Includes the launch() function which will start the program when called.

Complex or critical members:

initData(Telco* tel): Calls on initSubscribers() and initCalls() functions to create test Subscriber and Call objects.

launch(): Calls on initData to initalize the data, then begins the program by calling on the View classes showMenu() function. Will continue to call showMenu() until the user exits by inputting '0' in which, the showMenu() function terminates.
*/

Control::Control()
{
	telco = new Telco("Sean's Telephone Company");
}

Control::~Control()
{
	delete telco;
}


void Control::initData(Telco* tel)
{
  initSubscribers(tel);
  initCalls(tel);
}

void Control::initSubscribers(Telco* tel)
{
  tel->addSub(new Subscriber("6139990000")); 
  tel->addSub(new Subscriber("6133334444"));
  tel->addSub(new Subscriber("6138889999")); 
  tel->addSub(new Subscriber("6131112222"));
  tel->addSub(new Subscriber("6132223333"));
  tel->addSub(new Subscriber("6134445555")); 
}

void Control::initCalls(Telco* tel)
{
  tel->addCall("6139990000", "6133334444", 2020, 1, 1, 0, 31, 12);
  tel->addCall("6139990000", "6132223333", 2019, 2, 2, 10, 54, 2);

  tel->addCall("6132223333", "6139990000", 2019, 2, 23, 6, 33, 11);
  tel->addCall("6132223333", "6139990000", 2019, 3, 2, 10, 54, 2);
  tel->addCall("6132223333", "6139990000", 2019, 2, 20, 14, 22, 5);
  tel->addCall("6132223333", "6131112222", 2019, 12, 18, 4, 5, 15);

  tel->addCall("6131112222", "6132223333", 2019, 6, 30, 6, 2, 5);
  tel->addCall("6131112222", "6139990000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6130000000", 2019, 8, 9, 8, 29, 7);
  tel->addCall("6131112222", "6138889999", 2019, 3, 10, 15, 12, 11);

  tel->addCall("6134445555", "6138889999", 2019, 3, 10, 15, 22, 1);
  tel->addCall("6134445555", "6138887777", 2019, 3, 10, 15, 24, 10);
}

void Control::launch()
{
	initData(telco);
	
	int choice;
	view->showMenu(choice);
	
	while(choice != 0){
		if(choice == 1){
			string destNum;
			cout << "Please insert a destination phone number: "<<endl;
			view->readStr(destNum);
			telco->computeFreqCaller(destNum);
		}
		else if(choice == 2){
			string srcNum;
			cout << "Please insert a source phone number: "<<endl;
			view->readStr(srcNum);
			telco->computeFreqCalled(srcNum);
		}
		else if(choice == 3){
			telco->print();
		}
		view->showMenu(choice);
	}
	return;
	
}

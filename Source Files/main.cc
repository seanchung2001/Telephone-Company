#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

/*
Purpose of this program: The purpose of this assignment was to practice implementing a design that follows a UML class diagram. Focus on encapsulation by seperating the control, view, and collection objects. And to practice encapsulation through the principle of least priviledge.

Usage: Creating a simulation of a telephone company. This program allows us to store a collection of subscribers, in which, stores a collection of incoming and outgoing calls to and from the subscriber. With this information, we are able to compute a specified subscriber's most frequent caller, who the subscriber has called most frequently, and print out a history of incoming and outgoing calls for the telephone company. We are also able to manipulate these collection classes when a new subscriber is added, or a phone call is made. The program will begin by displaying a menu to: (1) Compute the most frequent caller for a specific subscriber, (2) Compute the subscriber's most frequently called number, (3) Print out the history of all calls made by subscribers in the telephone company, (0) Exit the program. After the user inputs a specified number corresponding to which function they want to call; If they input '1' or '2', the program will prompt the user to enter a specific phone number that is included in the collection of the Telco's subscribers.

Author: Sunyeop (Sean) Chung

All revisions:
*/


int main()
{
	Control* control = new Control();
	control->launch();
	
	delete control;
	return 0;
}

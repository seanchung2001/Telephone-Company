#include <iostream>
using namespace std;

#include "Telco.h"

/*
Purpose of Telco.cc: Entity class. This Class contains functions that can; (1) Compute the most frequent caller to a specific subscriber, (2) Compute a specific subscribers most frequently called number, (3) Prints out information for every subscriber in the Telco class.

Complex or critical members:

~Telco(): calls the Array classes cleanup() function to deallocate all of the Call pointers stored in the array, as well as the Array object itself. Also deallocates the memory for every Subscriber pointer stored in the subscribers array.

addSub(Subscriber* sub): adds the Subscriber object specified in the function parameter, and stores it in the subscribers[] array of pointers.

addCall(string srcNum, string destNum, int year, int month, int day, int hour, int minute, int duration): creates a new Call object using the parameters specified in the function. Then it adds the Call object into allCalls[] array. Also checks that the source number corresponds to a subsribers phone number. If it does, then it adds the Call object into the corresponding subscribers array of outgoing calls. Does the same for the destination number.

computeFreqCaller(string destNum): Computes the most frequent caller to the specified phone number and displays the most frequent callers phone number, as well as the information for every call that was made to the specififed phone number. If the phone number specified in the function parameter is != a subscriber in the telco class, then it cannot be computed. In the case of a tie, they are all printed. If the specified string in the parameter is 'all', then the most frequent caller is calculated from the array of allCalls[].

computeFreqCalled(string srcNum): If the source number corresponds to a subscriber in the Telco class, then it computes the most frequently called number by the subscriber. Then displays the most frequently called phone number, as well as the information for every call that was made to the most frequently called phone number. In the case of a tie, they are all printed. If the specified string in the parameter is 'all', then the most frequently called number is calculated from the array of allCalls[].

print(): Prints out all of the information for every Subscriber that is stored in the subscribers[] array.
*/

Telco::Telco(string s)
{
	name = s;
	allCalls = new Array();
	numSubs = 0;
}

Telco::~Telco()
{
	allCalls->cleanup();
	delete allCalls;
	for(int i = 0; i < numSubs; i++){
		delete subscribers[i];
	}
}

void Telco::addSub(Subscriber* sub)
{
	if(numSubs == MAX_ARR){
		return;
	}
	subscribers[numSubs] = sub;
	numSubs++;
}

void Telco::addCall(string srcNum, string destNum, int year, int month, int day, int hour, int minute, int duration)
{
	Call* newCall;
	newCall = new Call(srcNum, destNum, duration, day, month, year, hour, minute);
	allCalls->add(newCall);
	for(int i = 0; i < numSubs; i++){
		if(subscribers[i]->getPhoneNum() == srcNum){
			subscribers[i]->addOutgoing(newCall);
		}
		else if(subscribers[i]->getPhoneNum() == destNum){
			subscribers[i]->addIncoming(newCall);
		}
	}
}

void Telco::computeFreqCaller(string destNum)
{
	if(destNum == "all"){
		static Call* temp;
		int mostFreqNum = 0;
		static Call* mostFreqCallers[5];
		static Call* callList[30];
		int callListSize = 0;
		static Call* tempCallList[5];
		int mostFreqCallerSize = 0;
		int count = 0;
		for(int i = 0; i < allCalls->getSize(); i++){
			if(count > mostFreqNum){
				mostFreqNum = count;
				mostFreqCallerSize = 1;
				mostFreqCallers[0] = temp;
				for(int r = 0; r < count; r++){
					callList[r] = tempCallList[r];
				}
				callListSize = count;
			}
			else if(count == mostFreqNum && i != 0){
				mostFreqCallerSize++;
				mostFreqCallers[mostFreqCallerSize-1] = temp;
				int tempIndex = 0;
				for(int p = count; p < count*2; p++){
					callList[p] = tempCallList[tempIndex];
					tempIndex++;
				}
				callListSize += count;
			}
			count = 0;
			temp = allCalls->get(i);
			bool flag = true;
			for(int k = 0; k < mostFreqCallerSize; k++){
				if(temp->getSrc() == mostFreqCallers[k]->getSrc()){
					flag = false;
				}
			}
			if(flag == false){
				continue;
			}
			for(int j = 0; j < allCalls->getSize(); j++){
				if(allCalls->get(j)->getSrc() == temp->getSrc()){
					tempCallList[count] = allCalls->get(j);
					count++;
				}
			}
		}
		count = 0;
		for(int k = 0; k < mostFreqCallerSize; k++){
			cout<<"Most frequent caller to all: "<<mostFreqCallers[k]->getSrc()<<endl;
			while(count < mostFreqNum){
				callList[count]->print();
				count++;
			}
			cout<<endl;
			mostFreqNum += mostFreqNum;
		}
		return;
	}
	
	static Call* mostFreqCaller[10];
	static Subscriber* searchIncomingCalls;
	static Call* temp;
	int count = 0;
	int mostFreq = 0;
	int index = 0;
	bool flag = false;
	bool noCalls = false;
	for(int i = 0; i < numSubs; i++){
		if(subscribers[i]->getPhoneNum() == destNum){
			searchIncomingCalls = subscribers[i];
			flag = true;
			break;
		}
	}
	if(flag == true){
		if(searchIncomingCalls->getInCallsSize() == 0){
			noCalls = true;
		}
	}
	if(flag == true && noCalls == false){
		for(int j = 0; j < searchIncomingCalls->getInCallsSize()+1; j++){
			if(count == mostFreq && j != 0){
				mostFreqCaller[index] = temp;
				index++;
			}
			else if(count > mostFreq){
				
				index = 0;
				mostFreqCaller[index] = temp;
				index++;
				mostFreq = count;
			}
			if(j == searchIncomingCalls->getInCallsSize()){
				break;
			}
			temp = searchIncomingCalls->getInCalls(j);
			count = 0;
			/*
			for(int r = 0; r < index; r++){
				if(mostFreqCaller[r]->getSrc() == temp->getSrc()){
					flag = false;
				}
			}
			if(flag == false){
				continue;
			}*/
			for(int k = 0; k < searchIncomingCalls->getInCallsSize();k++){
				if(temp->getSrc() == searchIncomingCalls->getInCalls(k)->getSrc()){
					count++;
				}
			}
		}
		flag = true;
		string sourceNum = mostFreqCaller[0]->getSrc();
		for(int i = 0; i < index; i++){
			if(flag == true){
				cout<<"Most frequent caller to "<<destNum<<": "<<mostFreqCaller[i]->getSrc()<<endl;
				if(i != index-1){
					if(sourceNum == mostFreqCaller[i+1]->getSrc()){
						flag = false;
					}
					else{
						flag = true;
						sourceNum = mostFreqCaller[i+1]->getSrc();
					}
				}
			}
			mostFreqCaller[i]->print();
		}
	}
	else if(flag == false){
		cout<<"ERROR:  Could not find subscriber! ps: (Hello TA!)"<<endl;
		return;
	}
	else if(noCalls == true){
		cout<<"This phone number had no incoming calls!"<<endl;
	}
}

void Telco::computeFreqCalled(string srcNum)
{
	if(srcNum == "all"){
		static Call* temp;
		int mostFreqNum = 0;
		static Call* mostFreqCallers[5];
		static Call* callList[30];
		int callListSize = 0;
		static Call* tempCallList[5];
		int mostFreqCallerSize = 0;
		int count = 0;
		for(int i = 0; i < allCalls->getSize(); i++){
			if(count > mostFreqNum){
				mostFreqNum = count;
				mostFreqCallerSize = 1;
				mostFreqCallers[0] = temp;
				for(int r = 0; r < count; r++){
					callList[r] = tempCallList[r];
				}
				callListSize = count;
			}
			else if(count == mostFreqNum && i != 0){
				mostFreqCallerSize++;
				mostFreqCallers[mostFreqCallerSize-1] = temp;
				int tempIndex = 0;
				for(int p = count; p < count*2; p++){
					callList[p] = tempCallList[tempIndex];
					tempIndex++;
				}
				callListSize += count;
			}
			count = 0;
			temp = allCalls->get(i);
			bool flag = true;
			for(int k = 0; k < mostFreqCallerSize; k++){
				if(temp->getDest() == mostFreqCallers[k]->getDest()){
					flag = false;
				}
			}
			if(flag == false){
				continue;
			}
			for(int j = 0; j < allCalls->getSize(); j++){
				if(allCalls->get(j)->getDest() == temp->getDest()){
					tempCallList[count] = allCalls->get(j);
					count++;
				}
			}
		}
		count = 0;
		for(int k = 0; k < mostFreqCallerSize; k++){
			cout<<endl;
			cout<<"Most frequent caller to all: "<<mostFreqCallers[k]->getDest()<<endl;
			while(count < mostFreqNum){
				callList[count]->print();
				count++;
			}
			cout<<endl;
			mostFreqNum += mostFreqNum;
		}
		return;
	}
	static Call* mostFreqCaller[10];
	static Subscriber* searchIncomingCalls;
	static Call* temp;
	int count = 0;
	int mostFreq = 0;
	int index = 0;
	bool flag = false;
	bool noCalls = false;
	for(int i = 0; i < numSubs; i++){
		if(subscribers[i]->getPhoneNum() == srcNum){
			searchIncomingCalls = subscribers[i];
			flag = true;
			break;
		}
	}
	if(flag == true){
		if(searchIncomingCalls->getOutCallsSize() == 0){
			noCalls = true;
		}
	}	
	if(flag == true && noCalls == false){
		for(int j = 0; j < searchIncomingCalls->getOutCallsSize()+1; j++){
			if(count == mostFreq && j != 0){
				mostFreqCaller[index] = temp;
				index++;
			}
			else if(count > mostFreq){
				index = 0;
				mostFreqCaller[index] = temp;
				index++;
				mostFreq = count;
			}
			if(j == searchIncomingCalls->getOutCallsSize()){
				break;
			}
			temp = searchIncomingCalls->getOutCalls(j);
			count = 0;
			/*for(int r = 0; r < index; r++){
				if(mostFreqCaller[r]->getDest() == temp->getDest()){
					flag = false;
				}
			}
			if(flag == false){
				continue;
			}*/
			for(int k = 0; k < searchIncomingCalls->getOutCallsSize(); k++){
				if(temp->getDest() == searchIncomingCalls->getOutCalls(k)->getDest()){
					count++;
				}
			}
		}
		string destinationNum = mostFreqCaller[0]->getDest();
		for(int i = 0; i < index; i++){
			if(destinationNum == mostFreqCaller[i]->getDest() && flag == true){
				cout<<endl;
				cout<<"Most frequent called to "<<srcNum<<": "<<mostFreqCaller[i]->getDest()<<endl;
				if(i != index-1){
					if(mostFreqCaller[i+1]->getDest() == destinationNum){
						flag = false;
					}
					else{
						flag = true;
						destinationNum = mostFreqCaller[i]->getDest();
					}
				}
			}
			mostFreqCaller[i]->print();
		}
	}
	else if(flag == false){
		cout<<"ERROR:  Could not find subscriber! ps: (Hello TA!)"<<endl;
		return;
	}
	else if(noCalls == true){
		cout<<"This subscriber has no outgoing calls!"<<endl;
		return;
	}
}

void Telco::print()
{
	for(int i = 0; i < numSubs; i++){
		subscribers[i]->print();
	}
}

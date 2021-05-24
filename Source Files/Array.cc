#include <iostream>
using namespace std;

#include "Array.h"

/*
Purpose of Array.cc: Collection class that stores an array of Call pointers.

Complex or critical members:

Array(& a): Copy constructor, creates an Array object which stores the exact same values as the Array object specified in the copy constructors parameter.

add(Call* c): adds a Call object that is specified in the functions parameter to the array of Call pointers. Adds the Call object in the correct spot of the calls array in order to maintain a decreasing order of Date and Time. Returns true if the call was added properly, false otherwise.

add(Array& arr): Adds each and every call from the Array object specified in the function parameter, to 'this' Array object's array of Call pointers.

get(int i): Retrieves the Call object that is located in the i'th index of 'this' Array objects array of calls.

getSize(): Returns the 'size' member function.

print(): Prints the information for every Call pointer that is stored in the 'calls' array. This function calls on the Call classes 'print()' function.
*/

Array::Array()
{
  size = 0;
}

void Array::cleanup()
{
  for (int i=0; i<size; ++i){
    delete calls[i];
  }
}

Array::Array(Array& a){
	size = 0;
	for(int i = 0; i < a.size; i++){
		this->add(a.calls[i]);
	}
	size = a.size;
}


bool Array::add(Call* c)
{
	int addIndex = -1;
	if(this->size == 0){
		this->calls[0] = c;
		size++;
		return true;
	}
	if(size == MAX_ARR){
		return false;
	}
	for(int i = 0; i < this->size; i++){
		if(c->greaterThan(calls[i]) == true){
			addIndex = i;
			break;
		}
	}
	if(addIndex == -1){
		calls[size] = c;
		size++;
		return true;
	}
	for(int j = this->size; j > addIndex; j--){
		this->calls[j] = this->calls[j-1];
	}
	this->calls[addIndex] = c;
	this->size++;
	return true;

}

bool Array::add(Array& arr)
{
	bool flag = true;
	for(int i = 0; i < arr.size; i++){
		flag = this->add(arr.calls[i]);
		if(flag == false){
			return flag;
		}
	}
	return flag;
}

Call* Array::get(int i)
{
	return this->calls[i];
}

int Array::getSize()
{
	return this->size;
}

void Array::print()
{
  for (int i=0; i<size; ++i){
    calls[i]->print();
  }

  cout << endl;
}

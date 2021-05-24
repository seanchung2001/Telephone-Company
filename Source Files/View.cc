#include <iostream>
using namespace std;
#include <string>

#include "View.h"

/*
Purpose of View.cc: Display the menu and read in user input.

Complex or critical members:

showMenu(int& choice): Displays a menu with instructions on what to input depending on if the user wants to; (1) Compute most frequent caller, (2) Compute most frequently called, (3) Show all calls, (0) Exit. This function will make sure that the user input is between 0-3.

printStr(string str): Prints the string that is specified in the function parameter.

readInt(int& n): Reads in an integer from the user and stores it in the int parameter 'n'.

readStr(string& str): Reads in a string from the user and stores it in the string parameter 'str'.
*/

void View::showMenu(int& choice)
{
  int numOptions = 3;

  cout << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Compute most frequent caller" << endl;
  cout << "  (2) Compute most frequently called" << endl;
  cout << "  (3) Show all calls" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}

/*
QUESTION----------------------------------------------------------
For this second response, you will create a switch statement. The 
switch statement should include the following:

A variable of type char for the comparison
The switch statement should check for the value of 'y' (lowercase) 
or 'Y' (uppercase) and output the response "You chose y or Y" to 
the console window
The switch statement should check for the value 'n' or 'N' and 
output the response, "You chose n or N" to the console window
The switch statement should include the correct component that 
will output "You didn't choose a valid option" if neither of 
these two previous conditions are true

Paste your code in the response section below
RESPONSE----------------------------------------------------------
*/

#define YES 'y'
#define NO 'n'
#define ON_YES "You chose Y or y"
#define ON_NO "You chose N or n"
#define ON_INVALID "You didn't choose a valid option"

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::tolower;

using std::string;

int main()
{
  string userInput;
  bool validUserInput = false;
  
  while (!validUserInput) {
    
    cout << "Confirm? [y/n] > ";
    
    if (cin >> userInput) {
      char firstChar = tolower(userInput[0]);
      
      switch (firstChar) {
        case YES:
          cout << ON_YES << endl;
          validUserInput = true;
          break;
        case NO:
          cout << ON_NO << endl;
          validUserInput = true;
          break;
        default:
          cout << ON_INVALID << endl;
      }
    }
  }
  
  return 0;
}

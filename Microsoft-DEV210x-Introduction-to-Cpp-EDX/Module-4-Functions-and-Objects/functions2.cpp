/*
QUESTION----------------------------------------------------------

Expanding Your Knowledge
For the second part of this assignment, you will create a function 
to perform the average of values in an array. To complete this 
portion, your code should match the following requirements:

Create a function called avg that will accept an integer array. 
You may not have seen this in a demo but passing an array to a 
function is no different than passing any other data type. Search 
the Internet for an example if you can't figure out how to pass 
the array.

Create an array of integers, at least 5 in size, and pass it to 
the avg function.

Inside the function, use a loop to iterate over the array elements 
and calculate the average.

Return the average back to the code that called it.

RESPONSE----------------------------------------------------------
*/

#include <iostream>
#include <cmath>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;

namespace Utilities {

  double avg(const int a[], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
      sum += a[i];
    }
    return sum / (double)len;
  }
  
}

using Utilities::avg;

int main()
{
  const int LEN = 6;
  int array[LEN] = { 0, 1, 2, 3, 4, 5 };
  double av = avg(array, LEN);
  cout << "The average of your array of length " 
       << LEN << " is " << av << '.' << endl;
  
  return 0;
}

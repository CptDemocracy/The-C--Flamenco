/*
QUESTION----------------------------------------------------------

The scenario is that you have been asked to create a library of 
utility functions that support mathematical functions. You will 
add this code to functions in the next module but for now, write 
code to complete the following:

Using a for loop, write code that will compute the result of an 
int raised to the power of another int. For example, your for loop 
should use two variables, one for the base and one for the exponent. 
It should then calculate the base raised to the exponent. 2 raised 
to the power of 2 should output 4, 2 raised to 8 should output 256, 
etc. Ensure your code meets these requirements and then paste it in 
the response section below:

Contains a variable for the base
Contains a variable for the exponent
Uses a for loop to perform the power function
Outputs the result to the console window

RESPONSE----------------------------------------------------------
*/

/* <summary>While the best idea would be to separate the power function and split the implementation between Utilities.h and Utilities.cpp files, for simplicity, we'll keep it in one file.

One more thing to note: [ref] 
<reference>http://stackoverflow.com/questions/3992980/c-inline-member-function-in-cpp-file</reference>

<quote author="Arun">Note: It's imperative that the function's definition (the part between the {...}) be placed in a header file, unless the function is used only in a single .cpp file. In particular, if you put the inline function's definition into a .cpp file and you call it from some other .cpp file, you'll get an "unresolved external" error from the linker.</quote>

</summary>
*/

#include <iostream>
#include <cmath>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;

namespace Utilities {

  inline int pow(int base, int exp) {
    if (exp < 0)
      throw std::range_error("exp argument must be positive");
    
    if (exp == 0) return 1;
    
    int res = base;
    for (int i = 1; i < std::abs(exp); ++i) {
      res *= base;
    }
    return res;
  }

}

using Utilities::pow;

int main()
{
  try {
    cout << pow(2, 2) << endl;
    cout << pow(2, 8) << endl;
    cout << pow(2, -3) << endl;
  }
  catch (std::range_error& e) { 
    cerr << e.what() << endl;
  }
  
  return 0;
}

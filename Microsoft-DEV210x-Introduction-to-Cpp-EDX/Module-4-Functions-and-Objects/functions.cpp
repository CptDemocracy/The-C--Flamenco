/*
QUESTION----------------------------------------------------------

In the previous module, you created a for loop to calculate a base 
raised to an exponent. In this peer review, you are going to put that 
code into a function and create two more functions. Paste your code 
in the response section below that satisfies these requirements:

Create a function called pow that accepts two integers that represent 
the base and the exponent. The exponent should not permit negative 
values. 
Use the code you created in the previous module for some of this 
functionality but add additional code
The additional code should make use of an if statement to check the 
exponent value. If it is 0, then immediately return 1 otherwise 
calculate the power and return the result.
Show sample code that will call the function and get the result.

For the second function you will compute the sine of an angle. Your 
function should accept the opposite and hypotenuse lengths and return 
the sine value. The formula for sine is:

sin = opposite / hypotenuse

where / is used to denote division

Ensure that you paste the code for the function as well as the code that 
calls the function and assigns the value to a variable.

RESPONSE----------------------------------------------------------
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
    
  inline double sin(double opp, double hyp) {
    if (hyp <= 0.0) 
      throw std::invalid_argument("hyp arg negative or zero");
      
    return opp / hyp;
  }

}

using Utilities::pow;
using Utilities::sin;

int main()
{
  int m = pow(2, 2);
  int n = pow(2, 8);
  cout << m << endl;
  cout << n << endl;
  
  double s1 = sin(5.0, 3.0);
  double s2 = sin(3.4, 2.7);
  cout << s1 << endl;
  cout << s2 << endl;
  
  return 0;
}

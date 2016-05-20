/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     85                      </page>
 * </book>

 * <exercise>   5                       </exercise>
 *
 * <summary>
 *   Modify the program above to ask the user to enter floating·point values
 *   and store them in double variables. Compare the outputs of the two
 *   programs for some inputs of your choice.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 21st 2016       </date>
 */

#include <algorithm>
#include <iostream>
#include <cmath>

int main(const int argc, const char *argv[]) 
{
    const double EPSILON { std::pow(10.0, (-1.0) * DBL_DIG) };

    double val1    { 0.0 };
    double val2    { 0.0 };
    
    double minval  { 0.0 };
    double maxval  { 0.0 };
    double product { 0.0 };
    double diff    { 0.0 };
    double ratio   { 0.0 };

    while (true)
    {
        static_cast<void>(std::cout << "Please enter two floating point numbers: ");

        while ( !(std::cin >> val1 >> val2)) {
            static_cast<void>(std::cin.clear());
            static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
            static_cast<void>(std::cerr << "Input invalid. Please try again." << std::endl);
        }
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

        minval = std::min(val1, val2);
        static_cast<void>(std::cout << "Smallest value: " << minval << std::endl);

        maxval = std::max(val1, val2);
        static_cast<void>(std::cout << "Largest value: " << maxval << std::endl);

        product = val1 * val2;
        static_cast<void>(std::cout << "Product: " << product << std::endl);

        diff = val1 - val2;
        static_cast<void>(std::cout << "Difference: " << diff << std::endl);

        static_cast<void>(std::cout << "Ratio: ");
        if (std::abs(val2) > EPSILON) {
            ratio = static_cast<double>(val1) / static_cast<double>(val2);
            static_cast<void>(std::cout << ratio);
        } else {
           static_cast<void>(std::cout << "Undefined");
        }
        static_cast<void>(std::cout << std::endl << std::endl);
    }
    return EXIT_SUCCESS;
}

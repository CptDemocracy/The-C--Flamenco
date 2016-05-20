/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     85                      </page>
 * </book>

 * <exercise>   4                       </exercise>
 *
 * <summary>
 *   Write a program that prompts the user to enter two integer values. Store
 *   these values in int variables named vall and val2. Write your program to
 *   determine the smallest, largest, sum, difference, product, and ratio of
 *   these values and report them to the user.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 21st 2016       </date>
 */

#include <algorithm>
#include <iostream>

int main(const int argc, const char *argv[]) 
{
    int val1 { 0 };
    int val2 { 0 };

    int minval  { 0 };
    int maxval  { 0 };
    int product { 0 };
    int diff    { 0 };
    double ratio { 0.0 };    

    while (true)
    {
        static_cast<void>(std::cout << "Please enter two integers: ");

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
        if (val2 != 0) {
            ratio = static_cast<double>(val1) / static_cast<double>(val2);
            static_cast<void>(std::cout << ratio);
        } else {
           static_cast<void>(std::cout << "Undefined");
        }
        static_cast<void>(std::cout << std::endl << std::endl);
    }
	return EXIT_SUCCESS;
}

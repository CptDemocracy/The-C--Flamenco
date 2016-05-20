/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     85                      </page>
 * </book>

 * <exercise>   2                       </exercise>
 *
 * <summary>
 *   Write a program in C++ that converts from miles to kilometers. Your
 *   program should have a reasonable prompt for the user to enter a number
 *   of miles. Hint: There are 1.609 kilometers to the mile.
 *  </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 21st 2016       </date>
 */

#include <iostream>

namespace {
    double MilesToKilometers(double miles);
}

int main(const int argc, const char *argv[]) 
{
    double miles { 0.0 };
    double km    { 0.0 };

    while (true)
    {
        static_cast<void>(std::cout << "Please enter the number of miles to convert to kilometers: ");

        while ( !(std::cin >> miles)) {
            /* Make sure we clear the error flag first before "ignoring" the rest of invalid input. 
             * Trying to "ignore" the trailing input before clearing the error flag will result in
             * infinite loop.
             */
            static_cast<void>(std::cin.clear());
            static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
            static_cast<void>(std::cerr << "Input invalid. Please try again." << std::endl);
        }
        /* Get rid of the trailing whitespace characters */
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
    
        km = MilesToKilometers(miles);
    
        static_cast<void>(std::cout << "There are " << km << " kilometers in " 
                                    << miles << " mile" << (miles == 1 ? "" : "s") << '.' << std::endl);
        static_cast<void>(std::cout << "Please press Enter to continue...");
        static_cast<void>(std::cin.get());
    }
    return EXIT_SUCCESS;
}

namespace {
    double MilesToKilometers(double miles) {
        constexpr static double KM_IN_MI { 1.609 };
        return (miles * KM_IN_MI);
    }
}

/*
 * <book>
 *   <author>   Walther Savitch	        </author>
 *   <name>     Absolute C++		    </name>
 *   <chapter>  1                       </chapter>
 *   <page>     41                      </page>
 * </book>
 * 
 * <exercise>   2                      </exercise>
 *
 * <summary>
 *  A government research lab has concluded that an artificial sweetener 
 *  commonly used in diet soda will cause death in laboratory mice. A 
 *  friend of yours is desperate to lose weight but cannot give up soda. 
 *  Your friend wants to know how much diet soda it is possible to drink 
 *  without dying as a result. Write a program to supply the answer. The 
 *  input to the program is the amount of artificial sweetener needed to 
 *  kill a mouse, the weight of the mouse, and the weight of the dieter. 
 *  To ensure the safety of your friend, be sure the program requests the 
 *  weight at which the dieter will stop dieting, rather than the dieter’s 
 *  current weight. Assume that diet soda contains one-tenth of 1% artificial 
 *  sweetener. Use a variable declaration with the modifier const to give 
 *  a name to this fraction. You may want to express the percentage as the 
 *  double value 0.001.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>

int main(const int argc, const char *argv[]) 
{
    const long double SWEETENER_IN_SODA_RATIO { 0.001L };

    static_cast<void>(std::cout << "Please enter the amount of artificial " 
                                << "sweetener needed to kill a mouse: " << std::endl);
    
    long double mouseLethalSweetenerAmount { 0.0L };
    while (!(std::cin >> mouseLethalSweetenerAmount)) {
        /* input error handling */
        
        static_cast<void>(std::cin.clear());
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
        static_cast<void>(std::cout << "Invalid input for the amount of artificial sweetener"
                                    << " required to kill a mouse. Please try again." << std::endl);
    }
    static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

    static_cast<void>(std::cout << "Please enter the mouse's weight: " << std::endl);
    long double mouseWeight { 0.0L };
    while (!(std::cin >> mouseWeight)) {
        /* input error handling */

        static_cast<void>(std::cin.clear());
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
        static_cast<void>(std::cout << "Invalid input for the mouse's weight. Please try again." << std::endl);
    }
    static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
    
    static_cast<void>(std::cout << "Please enter the weight at which the dieter"
                                << " will stop dieting: " << std::endl);
    long double dieterWeight { 0.0L };
    while (!(std::cin >> dieterWeight)) {
        /* input error handling */

        static_cast<void>(std::cin.clear());
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
        static_cast<void>(std::cout << "Invalid input for the weight at which the dieter will stop"
                                    << " dieting. Please try again." << std::endl);
    }
    static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

    long double lethalAmountToWeightRatio { 0.0L };
    lethalAmountToWeightRatio = mouseLethalSweetenerAmount / mouseWeight;

    long double dieterLethalSweetenerAmount { 0.0L };
    dieterLethalSweetenerAmount = dieterWeight * lethalAmountToWeightRatio;

    long double lethalSodaAmount { 0.0L };
    lethalSodaAmount = dieterLethalSweetenerAmount / SWEETENER_IN_SODA_RATIO;

    static_cast<void>(std::cout << "Mouse weight: " << mouseWeight << std::endl);
    static_cast<void>(std::cout << "Mouse lethal sweetener amount: " << mouseLethalSweetenerAmount << std::endl);
    static_cast<void>(std::cout << "The soda amount of " << lethalSodaAmount << " will prove lethal to the dieter"
                                << " of weight equal or greater than " << dieterWeight << '.' << std::endl);

#ifdef DEBUG
    static_cast<void>(_CrtDumpMemoryLeaks());
#endif
	static_cast<void>(std::cin.get());
	return EXIT_SUCCESS;
}
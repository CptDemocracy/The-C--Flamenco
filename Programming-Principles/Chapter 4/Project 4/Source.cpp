/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  4                       </chapter>
 *   <page>     126                      </page>
 * </book>
 * 
 * <exercise>   4                      </exercise>
 *
 * <summary>
 *  Write a program to play a numbers guessing game. The user
 *  thinks of a number between 1 and 100 and your program asks
 *  questions to figure out what the number is (e.g., "Is the
 *  number you are thinking of less than 50?"). Your program 
 *  should be able to identify the number after asking no more 
 *  than seven questions.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <cstdlib>
#include <string>

int main(const int argc, const char *argv[]) 
{
    const std::string RESPONSE_GREATER_THAN { "gt" };
    const std::string RESPONSE_LESS_THAN    { "lt" };
    const std::string RESPONSE_EQUAL        { "eq" };

    const int UPPER_BOUND { 100 };
    const int LOWER_BOUND { 1 };

    std::string response { };
    
    int rangeBegin  { LOWER_BOUND };
    int rangeEnd    { UPPER_BOUND };
    int rangeMid    { (rangeBegin + rangeEnd) / 2 };
    
    bool isResponseValid { true }; 
    
    static_cast<void>(std::cout << "Please think of a number between " 
                                << LOWER_BOUND << " and " << UPPER_BOUND 
                                << '.' << std::endl << std::endl);

    while (rangeBegin < rangeEnd) 
    {
        try {
            isResponseValid = true;

            static_cast<void>(std::cout << "Is the number you are thinking of greater [gt], less [lt] or equal [eq] to " 
                                        << rangeMid << '?' << std::endl);

            if (!(std::cin >> response)) {
                throw std::invalid_argument { std::string { "Error while reading input" } };
            }
            static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

            if (response == RESPONSE_GREATER_THAN) {
                rangeBegin = rangeMid + 1;
            } else if (response == RESPONSE_LESS_THAN) {
                rangeEnd = rangeMid - 1;
            } else if (response == RESPONSE_EQUAL) {
                static_cast<void>(std::cout << "Your number is " << rangeMid << '.' << std::endl);
                break;
            } else {
                isResponseValid = false;
            }

            if (isResponseValid) {
                rangeMid = (rangeBegin + rangeEnd) / 2;

                if (rangeBegin >= rangeEnd) {
                    int randNum { 0 };
                    randNum = (rand() % UPPER_BOUND) + LOWER_BOUND;
                    static_cast<void>(std::cout << "Ah c'mon, your number is probably " << randNum << '.' << std::endl);
                }
            } else {
                throw std::invalid_argument { std::string { "Input not recognized." } };
            }
        } catch (const std::invalid_argument&) {
            static_cast<void>(std::cout << "I am sorry, I didn't quite understand your answer. Come again?" << std::endl);
            static_cast<void>(std::cin.clear());
            static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
        }
    }    
#ifdef DEBUG
    static_cast<void>(_CrtDumpMemoryLeaks());
#endif
	static_cast<void>(std::cin.get());
	return EXIT_SUCCESS;
}
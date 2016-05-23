/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     86                      </page>
 * </book>

 * <exercise>   11                      </exercise>
 *
 * <summary>
 *  Write a program that prompts the user to enter some number of pennies
 *  (1-cent coins), nickels (5-cent coins), dimes (10-cent coins), quarters (25-
 *  cent coins), half dollars (50-cent coins), and one-dollar coins (100-cent
 *  coins). Query the user separately for the number of each size coin, e.g.,
 *  "How many pennies do you have?" Then your program should print out something
 *  like this:
 *      You have 23 pennies.
 *      You have 17 nickels.
 *      You have 14 dimes.
 *      You have 7 quarters.
 *      You have 3 half dollars.
 *      The value of all of your coins is 573 cents.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Nickel.h"
#include "Penny.h"
#include "Dime.h"
#include "Quarter.h"
#include "HalfDollar.h"
#include "Dollar.h"

namespace {
    int ReadInteger(std::istream& is);
}

int main(const int argc, const char *argv[]) 
{
    try {
        static const std::string PENNY_PROMPT_MESSAGE   { "Please enter the number of pennies: " };
        static const std::string PENNY_ERROR_MESSAGE    { "Invalid input for pennies. Please try again." };

        static const std::string NICKEL_PROMPT_MESSAGE  { "Please enter the number of nickels: " };
        static const std::string NICKEL_ERROR_MESSAGE   { "Invalid input for nickels. Please try again." };

        static const std::string DIME_PROMPT_MESSAGE    { "Please enter the number of dimes: " };
        static const std::string DIME_ERROR_MESSAGE     { "Invalid input for dimes. Please try again." };

        static const std::string QUARTER_PROMPT_MESSAGE { "Please enter the number of quarters: " };
        static const std::string QUARTER_ERROR_MESSAGE  { "Invalid input for quarters. Please try again." };

        static const std::string HALF_DOLLAR_PROMPT_MESSAGE   { "Please enter the number of half dollars: " };
        static const std::string HALF_DOLLAR_ERROR_MESSAGE    { "Invalid input for half dollars. Please try again." };

        static const std::string DOLLAR_PROMPT_MESSAGE   { "Please enter the number of dollars: " };
        static const std::string DOLLAR_ERROR_MESSAGE    { "Invalid input for dollars. Please try again." };
        
        std::ostream& errorStream  { std::cerr };
        std::istream& inputStream  { std::cin };
        std::ostream& outputStream { std::cout };

        std::vector< std::unique_ptr<Coin> > coins { };
        int count { 0 };
        int total { 0 };
        
        /* Request the number of pennies. */
        try {
            static_cast<void>(outputStream << PENNY_PROMPT_MESSAGE);
            count = ReadInteger(inputStream);
        } catch (const std::invalid_argument&) {
            static_cast<void>(errorStream << PENNY_ERROR_MESSAGE << std::endl);
        }
        coins.push_back(std::unique_ptr<Coin> { new Penny { count }});

        /* Request the number of nickels. */
        try {
            static_cast<void>(outputStream << NICKEL_PROMPT_MESSAGE);
            count = ReadInteger(inputStream);
        } catch (const std::invalid_argument&) {
            static_cast<void>(errorStream << NICKEL_ERROR_MESSAGE << std::endl);
        }
        coins.push_back(std::unique_ptr<Coin> { new Nickel { count }});

        /* Request the number of dimes. */
        try {
            static_cast<void>(outputStream << DIME_PROMPT_MESSAGE);
            count = ReadInteger(inputStream);
        } catch (const std::invalid_argument&) {
            static_cast<void>(errorStream << DIME_ERROR_MESSAGE << std::endl);
        }
        coins.push_back(std::unique_ptr<Coin> { new Dime { count }});

        /* Request the number of quarters. */
        try {
            static_cast<void>(outputStream << QUARTER_PROMPT_MESSAGE);
            count = ReadInteger(inputStream);
        } catch (const std::invalid_argument&) {
            static_cast<void>(errorStream << QUARTER_ERROR_MESSAGE << std::endl);
        }
        coins.push_back(std::unique_ptr<Coin> { new Quarter { count }});

        /* Request the number of half-dollars. */
        try {
            static_cast<void>(outputStream << HALF_DOLLAR_PROMPT_MESSAGE);
            count = ReadInteger(inputStream);
        } catch (const std::invalid_argument&) {
            static_cast<void>(errorStream << HALF_DOLLAR_ERROR_MESSAGE << std::endl);
        }
        coins.push_back(std::unique_ptr<Coin> { new HalfDollar { count }});   

        /* Request the number of dollars. */
        try {
            static_cast<void>(outputStream << DOLLAR_PROMPT_MESSAGE);
            count = ReadInteger(inputStream);
        } catch (const std::invalid_argument&) {
            static_cast<void>(errorStream << DOLLAR_ERROR_MESSAGE << std::endl);
        }
        coins.push_back(std::unique_ptr<Coin> { new Dollar { count }});  
        
        /* Display the number of each coin. */
        for (const auto& coinUniquePtr : coins) {
            Coin *coin { coinUniquePtr.get() };
            count = coin->GetCoinCount();

            if (count > 0) {
                static_cast<void>(outputStream << "You have " << count << ' ');

                if (dynamic_cast<Penny*>(coin) != nullptr) {
                    static_cast<void>(outputStream << "pennies");
                } 
                else if (dynamic_cast<Nickel*>(coin) != nullptr) {
                    static_cast<void>(outputStream << "nickels");
                } 
                else if (dynamic_cast<Dime*>(coin) != nullptr) {
                    static_cast<void>(outputStream << "dimes");            
                } 
                else if (dynamic_cast<Quarter*>(coin) != nullptr) {
                    static_cast<void>(outputStream << "quarters");
                } 
                else if (dynamic_cast<HalfDollar*>(coin) != nullptr) {
                    static_cast<void>(outputStream << "half-dollar");
                } 
                else if (dynamic_cast<Dollar*>(coin) != nullptr) {
                    static_cast<void>(outputStream << "dollars");
                } 
                else {
                    static_cast<void>(outputStream << "coins");
                }
                static_cast<void>(outputStream << '.' << std::endl);
            }
        }

        /* Compute the total number of coins. */
        total = 0;
        for (const auto& coinUniquePtr : coins) {
            Coin *coin { coinUniquePtr.get() };
            total += coin->GetCents();
        }
        static_cast<void>(outputStream << "The value of all your coins is " << total << " cents." << std::endl);

#ifdef DEBUG
        static_cast<void>(_CrtDumpMemoryLeaks());
#endif
	    static_cast<void>(inputStream.get());
	    return EXIT_SUCCESS;
    } catch (const std::bad_alloc&) {
        return EXIT_FAILURE;
    }
}

namespace {
    int ReadInteger(std::istream& is) {
        int value { 0 };
        while (!(is >> value)) {
            static_cast<void>(is.clear());
            static_cast<void>(is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

            throw std::invalid_argument { std::string { "Input not a valid integer." } };
        }
        static_cast<void>(is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
        return value;
    }
}
/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  4                       </chapter>
 *   <page>     127                     </page>
 * </book>
 * 
 * <exercise>   6     </exercise>
 *
 * <summary>
 *  Make a vector holding the ten string values "zero",
 *  "one" through "nine". Use that in a program that
 *  converts a digit to its corresponding spelled-out
 *  value; e.g., the input 7 produces the output "seven".
 *  Have the same program, using the same input loop,
 *  convert spelled-out numbers into their digit form;
 *  e.g., the input seven gives the output 7.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

 /*
  * May 22nd 2016. REVISION REQUEST.
  * As of now, the program will ignore numbers, not separated
  * by whitespace. As in "911 Emergency", instead of "nine one
  * one Emergency", the program will output "911 Emergency".
  * This is to be addressed in the next revision.
  *
  * May 23rd 2016. REVISION RESPONSE.
  * The issue brought up by May 22nd 2016 REVISION REQUEST
  * has been handled by introducing a Tokenizer class.
  *
  * May 23rd 2016. REVISION REQUEST.
  * Though the May 22nd 2016 REVISION REQUEST was handled and
  * groups of digits not separated by whitespace are now
  * properly detected - all non-alnum characters are dropped
  * from input completely and are output in lowercase. This
  * should be addressed.
  *
  */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <map>

namespace {
    void StringToLowerCaseInPlace(std::string& refString);

    void Tokenize(const std::string& str, std::vector<std::string>& RefResult);
}

int main(const int argc, const char *argv[]) 
{
    try {
        /*
         * Using a vector will produce a time complexity of O(n).
         * Instead we choose to use a map (which uses a Red-Black-
         * Tree.) which will result in a time complexity of O(n log(n)).
         */
        std::map<std::string, std::string> wordToDigitDict { 
            { "zero",   "0" },
            { "one",    "1" },
            { "two",    "2" },
            { "three",  "3" },
            { "four",   "4" },
            { "five",   "5" },
            { "six",    "6" },
            { "seven",  "7" },
            { "eight",  "8" },
            { "nine",   "9" },
         };

         /* Build digitToWordDict at runtime based on data present
          * in wordToDigitDict to prevent inconsistencies.
          */
        std::map<std::string, std::string> digitToWordDict { };

        for (const auto& wordDigitPair : wordToDigitDict) {
            const std::string& word  { wordDigitPair.first };
            const std::string& digit { wordDigitPair.second };

            digitToWordDict[digit] = word;
        }

         /*
          * This is where we will store our tokens. Don't forget
          * to clear it on every iteration.
          */
        std::vector<std::string> tokens { };

        std::string input { };
        char nextChar { '\0' };

        while (std::cin >> input) 
        {
            /* Ensure case-insensitive comparison.
             */
            StringToLowerCaseInPlace(input);

            /*
             * Tokenize input.
             */
            tokens.clear();
            Tokenize(input, tokens);

            for (const auto& token : tokens)
            {
                if (digitToWordDict.find(token) != digitToWordDict.cend() /* digitToWordDict.contains(input) */) {
                    static_cast<void>(std::cout << digitToWordDict.at(token));
                } else if (wordToDigitDict.find(token) != wordToDigitDict.cend() /* wordToDigitDict.contains(input */) {
                    static_cast<void>(std::cout << wordToDigitDict.at(token));
                } else {
                    static_cast<void>(std::cout << token);
                }
                static_cast<void>(std::cout << ' ');
            }

            /* Look ahead, see if we have reached the end of line.
             */
            nextChar = std::cin.get();

            while (std::isspace(nextChar) && nextChar != '\n') {
                nextChar = std::cin.get();
            }

            if (nextChar == '\n') {
                static_cast<void>(std::cout << std::endl);
            } else {
                static_cast<void>(std::cin.putback(nextChar));
            }
        }
        static_cast<void>(std::cout << std::endl);

    #ifdef DEBUG
        static_cast<void>(_CrtDumpMemoryLeaks());
    #endif
	    static_cast<void>(std::cin.get());
	    return EXIT_SUCCESS;
    } catch (const std::bad_alloc&) {
        static_cast<void>(std::cerr << "Application out of memory." << std::endl);
        return EXIT_FAILURE;
    }
}

namespace {
    void StringToLowerCaseInPlace(std::string& refString) {
        std::size_t refStringLen { refString.length() };
        char currChar { '\0' };
        for (std::size_t i { 0U }; i < refStringLen; ++i) {
            currChar = refString[i];
            refString[i] = std::tolower(currChar);
        }
    }

    void Tokenize(const std::string& str, std::vector<std::string>& RefResult) 
    {
        std::size_t strLen { str.length() };
        if (strLen > 1U) 
        {            
            char prevChar { str.at(0) };
            char currChar { '\0' };
            std::string currToken { prevChar };

            for (std::size_t i { 0U }; i < strLen - 1U; ++i) {
                prevChar = str.at(i);
                currChar = str.at(i + 1);                                                           
                if (( std::isdigit(prevChar) && !std::isalpha(currChar)) 
                 || ( std::isalpha(prevChar) && !std::isalpha(currChar))
                 || (!std::isalpha(prevChar) &&  std::isalpha(currChar)))
                {
                    RefResult.push_back(currToken);
                    currToken.clear();
                }
                if (std::isalnum(currChar)) {
                    currToken += currChar;
                }
            }
            
            if (currToken.size() > 0U) {
                RefResult.push_back(currToken);
                currToken.clear();
            }    
        } else {
            RefResult.push_back(str);
        }
    }
}
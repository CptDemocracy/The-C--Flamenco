/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  4   	                </chapter>
 *   <page>     127	                    </page>
 * </book>
 * 
 * <exercise>   5                       </exercise>
 *
 * <summary>
 *  Modify the "mini-calculator" from exercise 5 to accept (just) 
 *  single-digit numbers written as either digits or spelled out.
 * </summary>
 *
 * <author>     Efim Bogdanovsky        </author>
 * <date>       May 23rd 2016           </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <cctype>
#include <memory>
#include <string>
#include <map>

#include "MathOperatorInterpreter.h"
#include "MathOperator.h"

#include "AdditionOperatorInterpreter.h"
#include "AdditionOperator.h"

#include "SubtractionOperatorInterpreter.h"
#include "SubtractionOperator.h"

#include "MultiplicationOperatorInterpreter.h"
#include "MultiplicationOperator.h"

#include "DivisionOperatorInterpreter.h"
#include "DivisionOperator.h"

#include "ModulusOperatorInterpreter.h"
#include "ModulusOperator.h"

#include "Tokenizer.h"

namespace {
    int StringCompare(const std::string& str1, const std::string& str2, bool isCaseSensitive);
}

int main(const int argc, const char *argv[])
{
    const std::string QUIT_CMD { "quit" };

    const std::map<std::string, double> WORD_TO_DIGIT_DICT { 
            { "zero",   0.0 },
            { "one",    1.0 },
            { "two",    2.0 },
            { "three",  3.0 },
            { "four",   4.0 },
            { "five",   5.0 },
            { "six",    6.0 },
            { "seven",  7.0 },
            { "eight",  8.0 },
            { "nine",   9.0 },
         };

    const std::unique_ptr<MathOperatorInterpreter> SUPPORTED_OPERATOR_INTERPRETERS[] = {
        std::unique_ptr<MathOperatorInterpreter> { new AdditionOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new SubtractionOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new MultiplicationOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new DivisionOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new ModulusOperatorInterpreter { } },
    };

    Tokenizer tokenizer { };
    std::string input   { };
    std::string optor   { };
    std::string token   { };
    char nextChar       { '\0' };
    bool canQuit        { false };

    double lhs      { 0.0 };
    double rhs      { 0.0 };
    double result   { 0.0 };
   
    std::unique_ptr<MathOperator> optorPtr { nullptr };

    while (!canQuit)
    {
        try {
            optorPtr.reset(nullptr);

            static_cast<void>(std::cout << ">>> ");
            
            if (!(std::getline(std::cin, input))) {                
                throw std::invalid_argument { std::string { "Invalid input." } };
            }

            /* Check if users are willing to quit. 
             *
             */
            if (StringCompare(QUIT_CMD, input, false) == 0) {
                canQuit = true;
                static_cast<void>(std::cout << "Thank you for using our application!" << std::endl);
            } else {
                tokenizer.Tokenize(input);

                if (tokenizer.GetTokenCount() > 3) {
                    throw std::invalid_argument { std::string { "Invalid input." } };
                }
                        
                if (!tokenizer.MoveNext()) {
                    /* If no input provided, the result is simply 0.0.
                     */
                    result = 0.0;
                } else {
                    /*
                     * Try parse the left operand.
                     */
                    try {
                        token = tokenizer.GetCurrent();
                        lhs = std::stod(token);
                    } catch (const std::invalid_argument&) {
                        /* See if it's a digit.
                         */
                         try {
                            lhs = WORD_TO_DIGIT_DICT.at(token);
                         } catch (const std::out_of_range&) {
                             /* Not a valid operand. 
                              * Throw std::invalid_argument exception.
                              */
                             throw std::invalid_argument { "Operand invalid." };
                         }
                    }

                    /* 
                     * Try parse the operator.
                     */
                    if (!tokenizer.MoveNext()) {
                        /*
                         * If no operator provided, the result is the left operand.
                         */
                         result = lhs;
                    } else {
                        optor = tokenizer.GetCurrent();

                        for (const auto& operatorInterpreter : SUPPORTED_OPERATOR_INTERPRETERS) {
                            operatorInterpreter.get()->InterpretMathOperator(optor, optorPtr);
                            if (optorPtr.get() != nullptr) {
                                break;
                            }
                        }
                        if (optorPtr.get() == nullptr) {
                            /* Error. Unsupported operator. */
                            throw std::invalid_argument { std::string { "Unsupported operator." } };
                        }

                        if (!tokenizer.MoveNext()) {
                            throw std::invalid_argument { std::string { "Right operand is missing." } };
                        } else {
                            /*
                             * Try parse the right operand.
                             */
                            try {
                                token = tokenizer.GetCurrent();
                                rhs = std::stod(token);
                            } catch (const std::invalid_argument&) {
                                /* See if it's a digit.
                                 */
                                 try {
                                    rhs = WORD_TO_DIGIT_DICT.at(token);
                                 } catch (const std::out_of_range&) {
                                     /* Not a valid operand. 
                                      * Throw std::invalid_argument exception.
                                      */
                                     throw std::invalid_argument { "Operand invalid." };
                                 }
                            }
                        }
                        result = optorPtr.get()->Execute(lhs, rhs);
                    }
                }        

                /*
                 * Finally output the value to the screen.
                 */
                static_cast<void>(std::cout << result << std::endl);
            }

        } catch (const std::invalid_argument& e) {
            static_cast<void>(std::cerr << "Error: " << e.what() << std::endl);
            static_cast<void>(std::cout << "Please press Enter to continue..." << std::endl);

            /* Clear the input stream.
             */
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

namespace {
    int StringCompare(const std::string& str1, const std::string& str2, bool isCaseSensitive) 
    {                    
        int strLen1 { static_cast<int>(str1.length()) };
        int strLen2 { static_cast<int>(str2.length()) };

        char c1 { '\0' };
        char c2 { '\0' };

        for (int i { 0 }, j { 0 }; i < strLen1 && j < strLen2; ++i, ++j) {
            c1 = str1.at(i); 
            c2 = str2.at(j);
            if (!isCaseSensitive) {
                c1 = std::tolower(c1);
                c2 = std::tolower(c2);
            }
            if (c1 != c2) {
                break;
            }
        }
        return static_cast<int>(c1) - static_cast<int>(c2);
    }
}
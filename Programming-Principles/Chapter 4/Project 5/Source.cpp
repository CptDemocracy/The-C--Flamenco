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

int main(const int argc, const char *argv[])
{
    const char QUIT_KEY { 'q' };

    const std::unique_ptr<MathOperatorInterpreter> SUPPORTED_OPERATOR_INTERPRETERS[] = {
        std::unique_ptr<MathOperatorInterpreter> { new AdditionOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new SubtractionOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new MultiplicationOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new DivisionOperatorInterpreter { } },
        std::unique_ptr<MathOperatorInterpreter> { new ModulusOperatorInterpreter { } },
    };

    double lhsValue     { 0.0 };
    double rhsValue     { 0.0 };
    double result       { 0.0 };
    char optor          { '\0' };
    char nextChar       { '\0' };
   
    std::unique_ptr<MathOperator> optorPtr { nullptr };

    while (true)
    {
        try {
            optorPtr.reset(nullptr);

            static_cast<void>(std::cout << ">>> ");

            /* Check ahead if users are willing to quit. */
            static_cast<void>(std::cin >> optor);
            if (std::tolower(optor) == QUIT_KEY) {
                break;
            } else {
                static_cast<void>(std::cin.clear());
                static_cast<void>(std::cin.putback(optor));
            }
            
            if (!(std::cin >> lhsValue >> optor >> rhsValue)) {                
                throw std::invalid_argument { "Invalid input." };
            }

            /* Check for trailing input. */
            nextChar = std::cin.get();
            while (std::isspace(nextChar) && nextChar != '\n') {
                nextChar = std::cin.get();
            }
            if (nextChar != '\n') {
                throw std::invalid_argument { "Invalid input." };
            }

            for (const auto& operatorInterpreter : SUPPORTED_OPERATOR_INTERPRETERS) {
                operatorInterpreter.get()->InterpretMathOperator(std::string { optor }, optorPtr);
                if (optorPtr.get() != nullptr) {
                    break;
                }
            }
            if (optorPtr.get() == nullptr) {
                /* Error. Unsupported operator. */
                throw std::invalid_argument { "Unsupported operator." };
            }        
            result = optorPtr.get()->Execute(lhsValue, rhsValue);
        
            static_cast<void>(std::cout << result << std::endl);
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
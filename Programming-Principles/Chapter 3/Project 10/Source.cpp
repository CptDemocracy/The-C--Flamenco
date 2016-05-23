/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     86                      </page>
 * </book>

 * <exercise>   10                      </exercise>
 *
 * <summary>
 *   Write a program that takes an operation followed by two operands and outputs 
 *   the result. For example:
 *       + 100 3.14
 *       * 4 5
 *   Read the operation into a string called operation and use an if-statement
 *   to figure out which operation the user wants, for example, if (operation=="+")
 *   
 *   Read the operands into variables of type double. Implement this for operations
 *   +, - , *, /, plus, minus, mul, and div with their obvious meanings.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <cctype>
#include <string>
#include <queue>

#include "SumOperation.h"
#include "SubOperation.h"
#include "MulOperation.h"
#include "DivOperation.h"

int main(const int argc, const char *argv[]) 
{
    try {
        const MathOperation<double>* SUPPORTED_OPERATION_TABLE[] = {
            SumOperation<double>::GetInstance(),
            SubOperation<double>::GetInstance(),
            MulOperation<double>::GetInstance(),
            DivOperation<double>::GetInstance()
        };

        const size_t SUPPORTED_OPERATION_TABLE_COUNT { 
            sizeof(SUPPORTED_OPERATION_TABLE) / sizeof(SUPPORTED_OPERATION_TABLE[0]) 
        };

        std::string optor   { };

        char nextChar       { '\0' };

        double value        { 0.0 };
        double localResult  { 0.0 };
        double finalResult  { 0.0 };        
        double lOperand     { 0.0 };
        double rOperand     { 0.0 };

        std::queue<double> operands { };

        const MathOperation<double>* currOp { nullptr };

        while (true)
        {
            try {
                /* Clear the queue. */
                while (operands.size() > 0U) {
                    operands.pop();
                }

                /* Fetch the operator. Can't use std::cin on strings, since then our
                 * clients will be forced to separate tokens with whitespace.
                 *
                 * Make sure we clear the "optor" string before proceeding.
                 */
                optor.clear();

                nextChar = std::cin.get();
                while (!std::isdigit(nextChar) && !std::isspace(nextChar) && nextChar != '.') {
                    optor += nextChar;
                    nextChar = std::cin.get();
                }

                /* Do not forget to put the last read character back into the stream
                 * for further I/O operations to handle.
                 */
                static_cast<void>(std::cin.putback(nextChar));

                /* Validate the operator. 
                 *
                 * Make sure we reset the currOp pointer to nullptr before proceeding.
                 * Not doing so will result in every previous operation to persist if
                 * for some reason the next operation was not found.
                 */

                currOp = nullptr;

                for (size_t i { 0U }; i < SUPPORTED_OPERATION_TABLE_COUNT && currOp == nullptr; ++i) {
                    currOp = SUPPORTED_OPERATION_TABLE[i]->TryParse(optor);
                }
        
                if (currOp == nullptr) {
                    throw std::invalid_argument { std::string { "Invalid operator." } };
                }

                while (std::cin >> value) {
                    operands.push(value);

                    /* Look ahead and see if we have encountered the end of the line.
                     * The logic may be a bit complicated due to the fact we want to
                     * allow trailing spaces before encountering the end of the line.
                     */
                    do {
                        nextChar = std::cin.get();
                    } while (isspace(nextChar) && nextChar != '\n');

                    /* Do not forget to put the character back in the stream.
                     * The call to std::istream::ignore method will take care
                     * of the character.
                     */
                    static_cast<void>(std::cin.putback(nextChar));

                    /* Found the new line character. Input acquisition is complete.
                     */
                    if (nextChar == '\n') break;
                }
                static_cast<void>(std::cin.clear());
                static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));                
                
                if (operands.size() > 0U) {
                    while (operands.size() > 1U) {
                        lOperand = operands.front();
                        operands.pop();

                        rOperand = operands.front();
                        operands.pop();

                        localResult = currOp->Execute(lOperand, rOperand);

                        operands.push(localResult);
                    }

                    finalResult = operands.front();
                    operands.pop();
                } else {
                    finalResult = 0;
                }
                static_cast<void>(std::cout << finalResult << std::endl);
            } catch (const std::invalid_argument& e) {
                static_cast<void>(std::cerr << e.what() << std::endl);
            }
        }

#ifdef DEBUG
        static_cast<void>(_CrtDumpMemoryLeaks());
#endif
	    static_cast<void>(std::cin.get());
	    return EXIT_SUCCESS;
        
    } catch (const std::runtime_error&) {
        return EXIT_FAILURE;
    } catch (const std::bad_alloc&) {
        return EXIT_FAILURE;
    }
}

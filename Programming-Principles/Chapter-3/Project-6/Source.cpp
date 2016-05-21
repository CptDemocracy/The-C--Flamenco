/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     85                      </page>
 * </book>

 * <exercise>   6                       </exercise>
 *
 * <summary>
 *   Write a program that prompts the user to enter three integer values, and
 *   then outputs the values in numerical sequence separated by commas. So,
 *   if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
 *   values are the same, they should just be ordered together. So, the input 4
 *   5 4 should give 4, 4, 5.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 21st 2016       </date>
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(const int argc, const char *argv[]) 
{
    /* The number of values user is expected to enter */
    constexpr int INPUT_VALUE_COUNT { 3 };

    /* String that will serve as a separator during output */
    const std::string SEPARATOR { ", " };
    
    /* Initialize the vector to the capacity of INPUT_VALUE_COUNT
     * to save us performance overhead.
     */
    std::vector<int> userInputVector(INPUT_VALUE_COUNT);
    
    /* Temporary storage for user input values */
    int value { 0 };

    while (true)
    {
        static_cast<void>(std::cout << "Please enter " << INPUT_VALUE_COUNT << " integer values:" << std::endl);
        int i { 0 };
        while (i < INPUT_VALUE_COUNT) {
            if ( !(std::cin >> value)) {
                /* If user input was invalid. Clear the error flag and discard the trailing input.
                 * It's important to clear the error flag first or else the program will be stuck
                 * in an infinite loop.
                 */
                static_cast<void>(std::cin.clear());
                static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
                static_cast<void>(std::cerr << "Input invalid. Please retry." << std::endl);
                
                /* Make sure the counter is reset. */
                i = 0;
            } else {
                /* This will cause a runtime error if the vector was not initialized 
                 * to capacity of INPUT_VALUE_COUNT 
                 */
                userInputVector[i] = value;
                ++i;
            }
        }
        /* Discard trailing whitespace left in the std::istream by std::istream::operator>> */
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

        std::sort(userInputVector.begin(), userInputVector.end());

        std::size_t userInputVectorSize = userInputVector.size();
        for (std::size_t i { 0U }; i < userInputVectorSize; ++i) {
            static_cast<void>(std::cout << userInputVector[i]);
            if (i != userInputVectorSize - 1U) {
                /* userInputVectorSize will never wrap around. In order for it to
                 * actually wrap around, (userInputVectorSize == 0U) should hold.
                 * However, if (userInputVectorSize == 0U) is true, this loop will
                 * never execute.
                 */
                static_cast<void>(std::cout << SEPARATOR);
            }
        }
        static_cast<void>(std::cout << std::endl);
        static_cast<void>(std::cout << "Please press Enter to continue...");
        static_cast<void>(std::cin.get());
        
        /* Sanitizing data. Please keep in mind that std::vector<T>::clear(void)
         * would be unacceptable for this operation, since it shrinks the vector's
         * capacity and we heavily rely on vector to be initialized to the capacity
         * of INPUT_VALUE_COUNT.
         */
         userInputVector.assign(INPUT_VALUE_COUNT, 0);
        
        /* Guard against trailing input that might be entered before pressing the Enter key */
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
    }
    return EXIT_SUCCESS;
}

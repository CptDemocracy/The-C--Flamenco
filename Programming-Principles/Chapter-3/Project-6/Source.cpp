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
    constexpr int INPUT_VALUE_COUNT { 3 };

    const std::string SEPARATOR { ", " };

    std::vector<int> userInputVector(INPUT_VALUE_COUNT);
    int value { 0 };

    while (true)
    {
        static_cast<void>(std::cout << "Please enter " << INPUT_VALUE_COUNT << " integer values." << std::endl);
        int i { 0 };
        while (i < INPUT_VALUE_COUNT) {
            if ( !(std::cin >> value)) {
                static_cast<void>(std::cin.clear());
                static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
                static_cast<void>(std::cerr << "Input invalid. Please retry." << std::endl);
                i = 0;
            } else {
                userInputVector[i] = value;
                ++i;
            }
        }
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

        std::sort(userInputVector.begin(), userInputVector.end());

        std::size_t userInputVectorSize = userInputVector.size();
        for (std::size_t i = 0U; i < userInputVectorSize; ++i) {
            static_cast<void>(std::cout << userInputVector[i]);
            if (i != userInputVectorSize - 1) {
                static_cast<void>(std::cout << SEPARATOR);
            }
        }
        static_cast<void>(std::cout << std::endl);
        
        static_cast<void>(std::cout << "Please press Enter to continue...");
        static_cast<void>(std::cin.get());
    }
    return EXIT_SUCCESS;
}

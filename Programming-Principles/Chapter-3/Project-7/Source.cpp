/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     85                      </page>
 * </book>

 * <exercise>   7                       </exercise>
 *
 * <summary>
 *   Do exercise 6, but with three string values. So, if the user enters
 *   the values "Ste inbeck", "Hemingway", "Fitzgerald ", the output should
 *   be "Filzgerald, Hemingway, Sieinbeck".
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
    constexpr size_t INPUT_VALUE_COUNT { 3U };

    const std::string SEPARATOR { ", " };
    const std::string EMPTY     { };

    std::vector<std::string> userInputVector(INPUT_VALUE_COUNT);
    std::string value { 0 };

    while (true)
    {
        static_cast<void>(std::cout << "Please enter " << INPUT_VALUE_COUNT << " words:" << std::endl);
        size_t i { 0U };
        while (i < INPUT_VALUE_COUNT) {
            if ( !(std::cin >> value)) {
                static_cast<void>(std::cin.clear());
                static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
                static_cast<void>(std::cerr << "Input invalid. Please retry." << std::endl);
                i = 0U;
            } else {
                userInputVector[i] = value;
                ++i;
            }
        }
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

        std::sort(userInputVector.begin(), userInputVector.end());

        std::size_t userInputVectorSize { userInputVector.size() };
        for (std::size_t i = 0U; i < userInputVectorSize; ++i) {
            static_cast<void>(std::cout << userInputVector[i]);
            if (i != userInputVectorSize - 1U) {
                static_cast<void>(std::cout << SEPARATOR);
            }
        }
        static_cast<void>(std::cout << std::endl);
        
        userInputVector.assign(INPUT_VALUE_COUNT, EMPTY);

        static_cast<void>(std::cout << "Please press Enter to continue...");
        static_cast<void>(std::cin.get());
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
    }
    return EXIT_SUCCESS;
}

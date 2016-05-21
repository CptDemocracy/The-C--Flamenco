/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     86                      </page>
 * </book>

 * <exercise>   8                       </exercise>
 *
 * <summary>
 *   Write a program to test an integer value to determine if it is odd or
 *   even. As always, make sure your output is clear and complete. In other
 *   words, don't just output "yes" or "no." Your output should stand alone,
 *   like "The value 4 is an even number."
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 21st 2016       </date>
 */

#include <iostream>

namespace {
    inline bool IsOdd(int number);
}

int main(const int argc, const char *argv[]) 
{
    int val { 0 };

    const auto OnEvenHandler { 
        [] (int val) { 
            static_cast<void>(std::cout << val << " is an even number." << std::endl);
        } 
    };

    const auto OnOddHandler {
        [] (int val) {
            static_cast<void>(std::cout << val << " is an odd number." << std::endl);
        }
    };

    while (true) {
        while ( !(std::cin >> val)) {
            static_cast<void>(std::cin.clear());
            static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
            static_cast<void>(std::cerr << "Invalid input. Please try again." << std::endl);
        }
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

        if (IsOdd(val)) {
            OnOddHandler(val);
        } else {
            OnEvenHandler(val);
        }
    }
    return EXIT_SUCCESS;
}

namespace {
    inline bool IsOdd(int number) {
        return (number & 1);
    }
}

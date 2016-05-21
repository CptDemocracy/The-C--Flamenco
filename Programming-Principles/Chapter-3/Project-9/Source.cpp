/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  3                       </chapter>
 *   <page>     86                      </page>
 * </book>

 * <exercise>   9                       </exercise>
 *
 * <summary>
 *   Write a program that converts spelled·out numbers such as "zero" and
 *   "two" into digits, such as 0 and 2. When the user inputs a number, the
 *   program should print out the corresponding digit. Do it for the values
 *   0, 1, 2, 3, and 4 and write out "not a number I know" if the user enters
 *   something that doesn't correspond."
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 21st 2016       </date>
 */

#include <iostream>
#include <string>
#include <map>

int main(const int argc, const char *argv[]) 
{
    const std::map<std::string, int> WORD_LOOKUP_TABLE { 
        { std::string { "zero"  }, 0 },
        { std::string { "one"   }, 1 },
        { std::string { "two"   }, 2 },
        { std::string { "three" }, 3 },
        { std::string { "four"  }, 4 },
        { std::string { "five"  }, 5 },
        { std::string { "six"   }, 6 },
        { std::string { "seven" }, 7 },
        { std::string { "eight" }, 8 },
        { std::string { "nine"  }, 9 },
    };

    const auto OnNumberInTableHandler {
        [] (int val) {
            static_cast<void>(std::cout << val << ' ' << std::endl);
        }
    };
    
    const auto OnNumberNotInTableHandler {
        [] (int val) {
            /* Throw away the argument. */
            static_cast<void>(val);

            static_cast<void>(std::cout << "Not a number I know of! " << std::endl);
        }
    };

    std::string input { };
    int val { 0 };

    while (std::cin >> input) {
        try {
            val = WORD_LOOKUP_TABLE.at(input);
            OnNumberInTableHandler(val);
        } catch (const std::out_of_range&) {
            OnNumberNotInTableHandler(val);
        }
    }
    /* The way the main program loop is built, is that the only way to break out of it,
     * is to send the EOF signal (Ctrl Z on Windows, Ctrl D on Unix) to the stream.
     * That in turn sets the stream's badbit flag. We need to clear the bad bit flag. 
     */
    static_cast<void>(std::cin.clear());
    return EXIT_SUCCESS;
}

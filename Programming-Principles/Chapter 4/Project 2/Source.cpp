/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  4                       </chapter>
 *   <page>     126                      </page>
 * </book>

 * <exercise>   2                      </exercise>
 *
 * <summary>
 *  If we define the median of a sequence as "the number for 
 *  which exactly half of the elements of the sequence come
 *  before it and exactly half come after it", fix the program in
 *  paragraph 4.6.2 so that it always prints out a median.
 *  Hint: A median need not be an element of the sequence.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <algorithm>
#include <iostream>
#include <cctype>
#include <numeric>
#include <vector>

namespace {
    bool IsOdd(int value);
}

int main(const int argc, const char *argv[]) 
{
    std::vector<double> temps { };
    double temp { 0.0 };

    while (std::cin >> temp) {
        temps.push_back(temp);
    }
    static_cast<void>(std::cin.clear());
    static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

    size_t tempCount { temps.size() };

    double sum { 0.0 };
    sum = std::accumulate(temps.begin(), temps.end(), 0.0);

    double avg { 0.0 };
    avg = sum / static_cast<double>(tempCount);
    
    static_cast<void>(std::cout << "Average temperature: " << avg << std::endl);

    std::sort(temps.begin(), temps.end());

    double median { 0.0 };

    if (tempCount > 0U) {
        if (IsOdd(tempCount)) {
            median = temps.at(tempCount / 2U);
        } else {
            median = 0.5 * static_cast<double>(temps.at(tempCount / 2U) + temps.at((tempCount / 2U) - 1U));
        }
        static_cast<void>(std::cout << "Median temperature: " << median << std::endl);
    } else {
        static_cast<void>(std::cout << "Unable to compute a median. No input specified." << std::endl);
    }

#ifdef DEBUG
    static_cast<void>(_CrtDumpMemoryLeaks());
#endif
	static_cast<void>(std::cin.get());
	return EXIT_SUCCESS;
}

namespace {
    bool IsOdd(int value) {
        return (value & 1);
    }
}
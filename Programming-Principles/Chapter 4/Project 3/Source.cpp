/*
 * <book>
 *   <author>   Bjarne Stroustrup       </author>
 *   <name>     Programming Principles  </name>
 *   <chapter>  4                       </chapter>
 *   <page>     126                      </page>
 * </book>

 * <exercise>   3                      </exercise>
 *
 * <summary>
 *  Read a sequence of double values into a vector. Think of each
 *  value as the distance between two along a given route. Compute
 *  and print the total distance (the sum of all distances). Find
 *  and print the smallest and greatest distance between two neigh-
 *  boring cities. Find and print the mean distance between two
 *  neighboring cities.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <numeric>
#include <cctype>
#include <vector>

int main(const int argc, const char *argv[]) 
{
    try {
        std::vector<double> distances { };
        double currDistance { 0.0 };
        char nextChar { '\0' };

        while (true) {
            if (!(std::cin >> currDistance)) {
                static_cast<void>(std::cin.clear());
                static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
                static_cast<void>(std::cerr << "Input invalid. Please try again." << std::endl);

                /* Upon error, do not forget to clear the vector of old values. 
                 */
                distances.clear();
            } else {
                distances.push_back(currDistance);
            }

            /* Scan for the end of the line. Optional trailing whitespace followed by the end of
             * the line indicates that we are done gathering input and should break out of the loop.
             */
             do {
                nextChar = std::cin.get();
             } while (std::isspace(nextChar) && nextChar != '\n');

             if (nextChar == '\n') {
                break;
             } else {
                static_cast<void>(std::cin.putback(nextChar));
             }
        }

        size_t distanceCount { distances.size() };

        double totalDistance { 0.0 };
        totalDistance = std::accumulate(distances.begin(), distances.end(), 0.0);

        double meanDistance { 0.0 };
        meanDistance = totalDistance / static_cast<double>(distanceCount);
    
        double minDistance { 0.0 };
        double maxDistance { 0.0 };

        if (distanceCount > 0U) {
            minDistance = distances.at(0);
            maxDistance = distances.at(0);
            for (size_t i = 1; i < distanceCount; ++i) {
                currDistance = distances.at(i);

                if (currDistance < minDistance) {
                    minDistance = currDistance;
                } 
                else if (currDistance > maxDistance) {
                    maxDistance = currDistance;
                }
            }
        }

        static_cast<void>(std::cout << "Total distance: " << totalDistance << std::endl);
        static_cast<void>(std::cout << "Smallest distance: " << minDistance << std::endl);
        static_cast<void>(std::cout << "Largest distance: " << maxDistance << std::endl);
        static_cast<void>(std::cout << "Mean distance: " << meanDistance << std::endl);
    
    #ifdef DEBUG
        static_cast<void>(_CrtDumpMemoryLeaks());
    #endif
	    static_cast<void>(std::cin.get());
	    return EXIT_SUCCESS;
    } catch (const std::bad_alloc&) {
        static_cast<void>(std::cerr << "Out of memory." << std::endl);
        return EXIT_FAILURE;
    }
}
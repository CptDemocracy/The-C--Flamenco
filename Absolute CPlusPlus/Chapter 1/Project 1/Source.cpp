/*
 * <book>
 *   <author>   Walther Savitch	        </author>
 *   <name>     Absolute C++		    </name>
 *   <chapter>  1                       </chapter>
 *   <page>     41                      </page>
 * </book>
 * 
 * <exercise>   1                      </exercise>
 *
 * <summary>
 *  A metric ton is 35,273.92 ounces. Write a program that will 
 *  read the weight of a package of breakfast cereal in ounces 
 *  and output the weight in metric tons as well as the number 
 *  of boxes needed to yield one metric ton of cereal.
 * </summary>
 *
 * <author> Efim Bogdanovsky    </author>
 * <date>   May 22nd 2016       </date>
 */

 #define DEBUG

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <cmath>

namespace {
    double OzToMetricTon(double oz);
}

int main(const int argc, const char *argv[]) 
{
    static constexpr int PACKAGE_COUNT { 1 };
#ifdef DEBUG
    static_assert(PACKAGE_COUNT > 0, "PACKAGE_COUNT cannot be zero or negative");
#endif

    static_cast<void>(std::cout << "Please enter the weight of " << PACKAGE_COUNT 
                                << " package" << (PACKAGE_COUNT == 1 ? "" : "s") 
                                << " of breakfast cereal in ounces: " << std::endl);
                                    
    double weightOzTotal { 0.0 };
    while (!(std::cin >> weightOzTotal)) {
        static_cast<void>(std::cin.clear());
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
        static_cast<void>(std::cerr << "Input invalid. Please try again." << std::endl);
    }
    static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

    double weightTonTotal { 0.0 };
    weightTonTotal = OzToMetricTon(weightOzTotal);

    double weightTonSingle { 0.0 };
    weightTonSingle = weightTonTotal / static_cast<double>(PACKAGE_COUNT);

    static_cast<void>(std::cout << "The weight of " << PACKAGE_COUNT
                                << " package" << (PACKAGE_COUNT == 1 ? "" : "s")
                                << " of breakfast cereal is " << weightTonTotal 
                                << " metric ton." << std::endl);
    if (PACKAGE_COUNT != 1) {
        static_cast<void>(std::cout << "The weight of a single package is " 
                                    << weightTonSingle << " metric ton." << std::endl);
    }
    
    int packagesInMetricTon { 0 };
    packagesInMetricTon = static_cast<int>(std::round(1.0 / weightTonSingle));
    if (packagesInMetricTon == 0) packagesInMetricTon = 1;
    
    static_cast<void>(std::cout << packagesInMetricTon 
                                << " packages are required to yield one metric ton." << std::endl);

#ifdef DEBUG
    static_cast<void>(_CrtDumpMemoryLeaks());
#endif
	static_cast<void>(std::cin.get());
	return EXIT_SUCCESS;
}

namespace {
    double OzToMetricTon(double oz) {
        static const double OZ_IN_TON { 35273.92 };
        return oz / OZ_IN_TON;
    }
}
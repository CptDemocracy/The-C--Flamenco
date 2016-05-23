/*
 * <book>
 *   <author>   Walther Savitch	        </author>
 *   <name>     Absolute C++		    </name>
 *   <chapter> 	1                       </chapter>
 *   <page> 	41                      </page>
 * </book>
 * 
 * <exercise>   3                       </exercise>
 *
 * <summary>
 *  Workers at a particular company have won a 7.6% pay increase retroactive 
 *  for six months. Write a program that takes an employee’s previous annual 
 *  salary as input and outputs the amount of retroactive pay due the employee, 
 *  the new annual salary, and the new monthly salary. Use a variable declaration 
 *  with the modifier const to express the pay increase.
 * </summary>
 *
 * <author>     Efim Bogdanovsky 	    </author>
 * <date> 	    May 23rd 2016           </date>
 */

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>

#include "Employee.h"
#include "PayIncrease.h"

int main(const int argc, const char *argv[])
{
    try {
        const long double PAY_INCREASE_RATIO { 0.076L };
        const int PAY_DUE_MONTH_COUNT { 6 };

        const PayIncrease payIncrease { PAY_INCREASE_RATIO };
    
        static_cast<void>(std::cout << "Please enter the employee annual salary: ");

        long double employeeAnnualSalary { 0.0L };

        while ( !(std::cin >> employeeAnnualSalary)) {
            static_cast<void>(std::cin.clear());
            static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));
            static_cast<void>(std::cerr << "Input invalid. Please try again." << std::endl);
        }
        static_cast<void>(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'));

        Employee employee { employeeAnnualSalary };

        long double employeeOldAnnualSalary     { employee.GetAnnualSalary()  };
        long double employeeOldMonthlySalary    { employee.GetMonthlySalary() };

        employee.IncreaseSalary(payIncrease);

        long double employeeNewAnnualSalary     { employee.GetAnnualSalary()  };
        long double employeeNewMonthlySalary    { employee.GetMonthlySalary() };

        long double payIncreaseRatio            { payIncrease.GetPayIncreaseRatio() };
        long double retroactivePayDue           { employeeNewMonthlySalary * PAY_DUE_MONTH_COUNT };

        static_cast<void>(std::cout << "Employee monthly salary before increase: " << employeeOldMonthlySalary 
                                    << std::endl);
        static_cast<void>(std::cout << "Employee annual salary before increase: " << employeeOldAnnualSalary
                                    << std::endl);
        static_cast<void>(std::cout << "Pay increase ratio: " << payIncreaseRatio << std::endl);
        static_cast<void>(std::cout << "Employee monthly salary after increase: " << employeeNewMonthlySalary
                                    << std::endl);
        static_cast<void>(std::cout << "Employee annual salary after increase: " << employeeNewAnnualSalary
                                    << std::endl);
        static_cast<void>(std::cout << "Salary due for " << PAY_DUE_MONTH_COUNT << " months: " 
                                    << retroactivePayDue << std::endl);

    #ifdef DEBUG
        static_cast<void>(_CrtDumpMemoryLeaks());
    #endif
	    static_cast<void>(std::cin.get());
	    return EXIT_SUCCESS;
    } catch (const std::invalid_argument& e) {
        static_cast<void>(std::clog << e.what() << std::endl);
        static_cast<void>(std::cin.get());
        return EXIT_FAILURE;
    }
}
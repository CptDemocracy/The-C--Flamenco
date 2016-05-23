#include <stdexcept>

#include "PayIncrease.h"
#include "Employee.h"

PayIncrease::PayIncrease(long double payIncreaseRatio) {
    if (payIncreaseRatio < 0.0L) {
        throw std::invalid_argument { 
            std::string { 
                "Pay increase ratio cannot be negative. For salary"
                " decrease, please use the PayDecrease class."
            }
        };
    }
    _payIncreaseRatio = payIncreaseRatio;
}

PayIncrease::~PayIncrease(void) { }

void PayIncrease::ApplyPayIncrease(Employee& emp) const {
    long double employeeCurrSalary { emp.GetAnnualSalary() };
    long double employeeNewSalary { employeeCurrSalary + employeeCurrSalary * _payIncreaseRatio };
    emp.SetAnnualSalary(employeeNewSalary);
}

long double PayIncrease::GetPayIncreaseRatio(void) const {
    return _payIncreaseRatio;
}
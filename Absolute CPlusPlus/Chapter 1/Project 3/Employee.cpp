#include <stdexcept>

#include "PayIncrease.h"
#include "Employee.h"

Employee::Employee(void)
    : Employee { 0.0L } { }

Employee::Employee(long double annualSalary) {
    if (annualSalary < 0.0L) {
        throw std::invalid_argument {
            std::string { "Annual salary cannot be negative." }
        };
    }
    _annualSalary = annualSalary;
}

Employee::~Employee(void) { }

void Employee::IncreaseSalary(const PayIncrease& payIncreaseObj) {
    payIncreaseObj.ApplyPayIncrease(*this);
}

long double Employee::GetAnnualSalary(void) const {
    return _annualSalary;
}

void Employee::SetAnnualSalary(long double newAnnualSalary) {
    _annualSalary = newAnnualSalary;
}
        
long double Employee::GetMonthlySalary(void) const {
    return (_annualSalary / static_cast<double>(MONTHS_IN_YEAR));
}
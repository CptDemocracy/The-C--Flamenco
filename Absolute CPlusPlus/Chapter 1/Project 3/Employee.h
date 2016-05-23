#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class PayIncrease;

class Employee {
    private:
        const int MONTHS_IN_YEAR    { 12 };
        long double _annualSalary   { 0.0L };

    public:
        Employee(void);

        explicit Employee(long double annualSalary);

        virtual ~Employee(void);

        void IncreaseSalary(const PayIncrease& payIncreaseObj);

        long double GetAnnualSalary(void) const;

        void SetAnnualSalary(long double newAnnualSalary);
        
        long double GetMonthlySalary(void) const;
};

#endif /* EMPLOYEE_H */
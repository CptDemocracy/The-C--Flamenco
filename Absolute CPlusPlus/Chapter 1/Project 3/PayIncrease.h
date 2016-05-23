#ifndef PAYINCREASE_H
#define PAYINCREASE_H

class Employee;

class PayIncrease {
    private:
        long double _payIncreaseRatio;

    public:
        PayIncrease(void) = delete;

        explicit PayIncrease(long double payIncreaseRatio);

        virtual ~PayIncrease(void);

        void ApplyPayIncrease(Employee& emp) const;

        long double GetPayIncreaseRatio(void) const;
};

#endif /* PAYINCREASE_H */
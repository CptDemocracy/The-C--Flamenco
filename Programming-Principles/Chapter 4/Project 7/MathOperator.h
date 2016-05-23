#ifndef MATHOPERATOR_H
#define MATHOPERATOR_H

/* Abstract class. */
class MathOperator {
    protected:
        MathOperator(void) = default;
    public:
        virtual ~MathOperator(void) = default;
        virtual double Execute(double lOperand, double rOperand) const = 0;
};

#endif /* MATHOPERATOR_H */
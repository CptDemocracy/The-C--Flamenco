#ifndef DIVISIONOPERATOR_H_
#define DIVISIONOPERATOR_H_

class MathOperator;

class DivisionOperator : public MathOperator {
    public:
        double Execute(double lOperand, double rOperand) const;
};

#endif /* DIVISIONOPERATOR_H_ */

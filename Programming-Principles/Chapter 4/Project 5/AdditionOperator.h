#ifndef ADDITIONOPERATOR_H_
#define ADDITIONOPERATOR_H_

class MathOperator;

class AdditionOperator : public MathOperator {
    public:
        double Execute(double lOperand, double rOperand) const;
};

#endif /* ADDITIONOPERATOR_H_ */
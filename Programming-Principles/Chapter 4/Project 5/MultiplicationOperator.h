#ifndef MULTIPLICATIONOPERATOR_H_
#define MULTIPLICATIONOPERATOR_H_

class MathOperator;

class MultiplicationOperator : public MathOperator {
    public:
        double Execute(double lOperand, double rOperand) const;
};

#endif /* MULTIPLICATIONOPERATOR_H_ */

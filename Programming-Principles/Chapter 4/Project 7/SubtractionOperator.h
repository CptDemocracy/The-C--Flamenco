#ifndef SUBTRACTIONOPERATOR_H_
#define SUBTRACTIONOPERATOR_H_

class MathOperator;

class SubtractionOperator : public MathOperator {
    public:
        double Execute(double lOperand, double rOperand) const;
};

#endif /* SUBTRACTIONOPERATOR_H_ */
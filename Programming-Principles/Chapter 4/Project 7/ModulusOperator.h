#ifndef MODULUSOPERATOR_H_
#define MODULUSOPERATOR_H_

class MathOperator;

class ModulusOperator : public MathOperator {
    public:
        double Execute(double lOperand, double rOperand) const;
};

#endif /* MODULUSOPERATOR_H_ */

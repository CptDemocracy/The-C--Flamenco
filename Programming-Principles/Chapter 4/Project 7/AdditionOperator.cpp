#include "MathOperator.h"
#include "AdditionOperator.h"

double AdditionOperator::Execute(double lOperand, double rOperand) const {
    return (lOperand + rOperand);
}
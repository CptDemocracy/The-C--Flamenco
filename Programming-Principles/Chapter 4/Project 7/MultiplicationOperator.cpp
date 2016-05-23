#include <stdexcept>

#include "MathOperator.h"
#include "MultiplicationOperator.h"

double MultiplicationOperator::Execute(double lOperand, double rOperand) const {
    return (lOperand * rOperand);
}
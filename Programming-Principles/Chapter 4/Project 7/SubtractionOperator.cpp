#include "MathOperator.h"
#include "SubtractionOperator.h"

double SubtractionOperator::Execute(double lOperand, double rOperand) const {
    return (lOperand - rOperand);
}
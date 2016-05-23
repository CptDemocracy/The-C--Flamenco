#include <stdexcept>

#include "MathOperator.h"
#include "DivisionOperator.h"

double DivisionOperator::Execute(double lOperand, double rOperand) const {
    if (rOperand == 0.0) {
        throw std::invalid_argument { "Zero division." };
    }
    return (lOperand / rOperand);
}
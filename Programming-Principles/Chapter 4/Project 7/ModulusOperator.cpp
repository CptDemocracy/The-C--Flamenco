#include <stdexcept>
#include <cmath>

#include "MathOperator.h"
#include "ModulusOperator.h"

double ModulusOperator::Execute(double lOperand, double rOperand) const {
    if (rOperand == 0.0) {
        throw std::invalid_argument { "Zero division." };
    }
    return std::fmod(lOperand, rOperand);
}
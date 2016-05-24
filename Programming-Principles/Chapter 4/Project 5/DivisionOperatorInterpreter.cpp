#include <stdexcept>
#include <string>
#include <memory>

#include "MathOperator.h"
#include "DivisionOperator.h"

#include "MathOperatorInterpreter.h"
#include "DivisionOperatorInterpreter.h"

void DivisionOperatorInterpreter::InterpretMathOperator(
    const std::string& str, 
    std::unique_ptr<MathOperator>& OutResult) const 
{
    try {
        if (str == "/") {
            OutResult.reset(new DivisionOperator { });
        } else {
            OutResult.reset(nullptr);
        }
    } catch (const std::bad_alloc&) {
        throw;
    }
}

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
        MathOperator *ptr { nullptr };
        if (str == "/") {
            ptr = new DivisionOperator { };
        }
        OutResult.reset(ptr);
    } catch (const std::bad_alloc&) {
        throw;
    }
}
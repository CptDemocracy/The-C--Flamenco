#include <stdexcept>
#include <string>
#include <memory>

#include "MathOperator.h"
#include "MultiplicationOperator.h"

#include "MathOperatorInterpreter.h"
#include "MultiplicationOperatorInterpreter.h"

void MultiplicationOperatorInterpreter::InterpretMathOperator(
    const std::string& str, 
    std::unique_ptr<MathOperator>& OutResult) const 
{
    try {
        MathOperator *ptr { nullptr };
        if (str == "*") {
            ptr = new MultiplicationOperator { };
        }
        OutResult.reset(ptr);
    } catch (const std::bad_alloc&) {
        throw;
    }
}
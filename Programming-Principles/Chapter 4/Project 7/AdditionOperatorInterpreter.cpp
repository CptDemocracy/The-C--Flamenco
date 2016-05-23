#include <stdexcept>
#include <string>
#include <memory>

#include "MathOperator.h"
#include "AdditionOperator.h"

#include "MathOperatorInterpreter.h"
#include "AdditionOperatorInterpreter.h"

void AdditionOperatorInterpreter::InterpretMathOperator(
    const std::string& str, 
    std::unique_ptr<MathOperator>& OutResult) const 
{
    try {
        MathOperator *ptr { nullptr };
        if (str == "+") {
            ptr = new AdditionOperator { };
        }
        OutResult.reset(ptr);
    } catch (const std::bad_alloc&) {
        throw;
    }
}
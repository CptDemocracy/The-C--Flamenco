#include <stdexcept>
#include <string>
#include <memory>

#include "MathOperator.h"
#include "SubtractionOperator.h"

#include "MathOperatorInterpreter.h"
#include "SubtractionOperatorInterpreter.h"

void SubtractionOperatorInterpreter::InterpretMathOperator(
    const std::string& str, 
    std::unique_ptr<MathOperator>& OutResult) const 
{
    try {
        MathOperator *ptr { nullptr };
        if (str == "-") {
            ptr = new SubtractionOperator { };
        }
        OutResult.reset(ptr);
    } catch (const std::bad_alloc&) {
        throw;
    }
}
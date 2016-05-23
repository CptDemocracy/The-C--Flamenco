#include <stdexcept>
#include <string>
#include <memory>

#include "MathOperator.h"
#include "ModulusOperator.h"

#include "MathOperatorInterpreter.h"
#include "ModulusOperatorInterpreter.h"

void ModulusOperatorInterpreter::InterpretMathOperator(
    const std::string& str, 
    std::unique_ptr<MathOperator>& OutResult) const 
{
    try {
        MathOperator *ptr { nullptr };
        if (str == "%") {
            ptr = new ModulusOperator { };
        }
        OutResult.reset(ptr);
    } catch (const std::bad_alloc&) {
        throw;
    }
}
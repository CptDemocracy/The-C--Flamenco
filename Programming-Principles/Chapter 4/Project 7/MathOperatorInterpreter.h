#ifndef MATHOPERATORINTERPRETER_H_
#define MATHOPERATORINTERPRETER_H_

#include "MathOperator.h"

class MathOperator;

/* Abstract class. */
class MathOperatorInterpreter {
    protected:
        MathOperatorInterpreter(void) = default;
    public:
        virtual ~MathOperatorInterpreter(void) = default;
        virtual void InterpretMathOperator(const std::string&, std::unique_ptr<MathOperator>& OutResult) const = 0;
};

#endif /* MATHOPERATORINTERPRETER_H_ */
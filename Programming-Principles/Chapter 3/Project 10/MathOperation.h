#ifndef MATHOPERATION_H_
#define MATHOPERATION_H_

#include <memory>
#include <string>

/* Abstract class. */
template <typename TValue>
class MathOperation {
    protected:
        MathOperation(void) = default;

    public:
        virtual MathOperation<TValue>* TryParse(const std::string&) const = 0;

        virtual TValue Execute(TValue leftOperand, TValue rightOperand) const = 0;
};

#endif /* MATHOPERATION_H_ */
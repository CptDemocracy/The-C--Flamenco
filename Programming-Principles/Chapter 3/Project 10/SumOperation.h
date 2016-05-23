#ifndef SUMOPERATION_H_
#define SUMOPERATION_H_

#include "MathOperation.h"

/* Sealed class. */
template <typename TValue>
class SumOperation : public MathOperation<TValue> {
    private:
        SumOperation(void) = default;

        static std::unique_ptr<SumOperation<TValue> > _operation;
    public:
        static const SumOperation<TValue>* GetInstance(void) {
            if (_operation.get() == nullptr) {
                _operation.reset(new SumOperation<TValue> { });
            }
            return _operation.get();
        }
    
        SumOperation<TValue>* TryParse(const std::string& exp) const override {
            try {
                static const std::string SUM_OP_STRING { "+" };
                SumOperation<TValue>* resultPtr { nullptr };

                if (SUM_OP_STRING == exp) {
                    resultPtr = new SumOperation<TValue> { };
                }
                return resultPtr;

            } catch (const std::bad_alloc&) {
                throw;
            }
        }

        TValue Execute(TValue leftOperand, TValue rightOperand) const override {
            return (leftOperand + rightOperand);
        }
};

template <typename TValue>
std::unique_ptr<SumOperation<TValue> > SumOperation<TValue>::_operation = nullptr;

#endif /* SUMOPERATION_H_ */
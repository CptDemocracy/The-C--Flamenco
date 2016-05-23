#ifndef DIVOPERATION_H_
#define DIVOPERATION_H_

#include "MathOperation.h"

/* Sealed class. */
template <typename TValue>
class DivOperation : public MathOperation<TValue> {
    private:
        DivOperation(void) = default;

        static std::unique_ptr<DivOperation<TValue> > _operation;
    public:
        static const DivOperation<TValue>* GetInstance(void) {
            if (_operation.get() == nullptr) {
                _operation.reset(new DivOperation<TValue> { });
            }
            return _operation.get();
        }
    
        DivOperation<TValue>* TryParse(const std::string& exp) const override {
            try {
                static const std::string DIV_OP_STRING { "/" };
                DivOperation<TValue>* resultPtr { nullptr };

                if (DIV_OP_STRING == exp) {
                    resultPtr = new DivOperation<TValue> { };
                }
                return resultPtr;

            } catch (const std::bad_alloc&) {
                throw;
            }
        }

        TValue Execute(TValue leftOperand, TValue rightOperand) const override {
            if (rightOperand == 0.0) {
                throw std::invalid_argument { std::string { "Zero division error." } };
            }
            return (leftOperand / rightOperand);
        }
};

template <typename TValue>
std::unique_ptr<DivOperation<TValue> > DivOperation<TValue>::_operation = nullptr;

#endif /* DIVOPERATION_H_ */
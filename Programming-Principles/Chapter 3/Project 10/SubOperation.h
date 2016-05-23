#ifndef SUBOPERATION_H_
#define SUBOPERATION_H_

#include "MathOperation.h"

/* Sealed class. */
template <typename TValue>
class SubOperation : public MathOperation<TValue> {
    private:
        SubOperation(void) = default;

        static std::unique_ptr<SubOperation<TValue> > _operation;
    public:
        static const SubOperation<TValue>* GetInstance(void) {
            if (_operation.get() == nullptr) {
                _operation.reset(new SubOperation<TValue> { });
            }
            return _operation.get();
        }
    
        SubOperation<TValue>* TryParse(const std::string& exp) const override {
            try {
                static const std::string SUB_OP_STRING { "-" };
                SubOperation<TValue>* resultPtr { nullptr };

                if (SUB_OP_STRING == exp) {
                    resultPtr = new SubOperation<TValue> { };
                }
                return resultPtr;

            } catch (const std::bad_alloc&) {
                throw;
            }
        }

        TValue Execute(TValue leftOperand, TValue rightOperand) const override {
            return (leftOperand - rightOperand);
        }
};

template <typename TValue>
std::unique_ptr<SubOperation<TValue> > SubOperation<TValue>::_operation = nullptr;

#endif /* SUBOPERATION_H_ */
#ifndef MULOPERATION_H_
#define MULOPERATION_H_

#include "MathOperation.h"

/* Sealed class. */
template <typename TValue>
class MulOperation : public MathOperation<TValue> {
    private:
        MulOperation(void) = default;

        static std::unique_ptr<MulOperation<TValue> > _operation;
    public:
        static const MulOperation<TValue>* GetInstance(void) {
            if (_operation.get() == nullptr) {
                _operation.reset(new MulOperation<TValue> { });
            }
            return _operation.get();
        }
    
        MulOperation<TValue>* TryParse(const std::string& exp) const override {
            try {
                static const std::string MUL_OP_STRING { "*" };
                MulOperation<TValue>* resultPtr { nullptr };

                if (MUL_OP_STRING == exp) {
                    resultPtr = new MulOperation<TValue> { };
                }
                return resultPtr;

            } catch (const std::bad_alloc&) {
                throw;
            }
        }

        TValue Execute(TValue leftOperand, TValue rightOperand) const override {
            return (leftOperand * rightOperand);
        }
};

template <typename TValue>
std::unique_ptr<MulOperation<TValue> > MulOperation<TValue>::_operation = nullptr;

#endif /* MULOPERATION_H_ */
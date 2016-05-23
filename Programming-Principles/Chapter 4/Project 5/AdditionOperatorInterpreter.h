#ifndef ADDITIONOPERATORINTERPRETER_H_
#define ADDITIONOPERATORINTERPRETER_H_

class MathOperatorInterpreter;

class AdditionOperatorInterpreter : public MathOperatorInterpreter {
    public:
        void InterpretMathOperator(
            const std::string& str, 
            std::unique_ptr<MathOperator>& OutResult) const override;
};

#endif /* ADDITIONOPERATORINTERPRETER_H_ */
#ifndef MULTIPLICATIONOPERATORINTERPRETER_H_
#define MULTIPLICATIONOPERATORINTERPRETER_H_

class MathOperatorInterpreter;

class MultiplicationOperatorInterpreter : public MathOperatorInterpreter {
    public:
        void InterpretMathOperator(
            const std::string& str, 
            std::unique_ptr<MathOperator>& OutResult) const override;
};

#endif /* MULTIPLICATIONOPERATORINTERPRETER_H_ */
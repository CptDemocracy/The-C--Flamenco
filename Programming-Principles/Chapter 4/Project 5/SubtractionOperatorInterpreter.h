#ifndef SUBTRACTIONOPERATORINTERPRETER_H_
#define SUBTRACTIONOPERATORINTERPRETER_H_

class MathOperatorInterpreter;

class SubtractionOperatorInterpreter : public MathOperatorInterpreter {
    public:
        void InterpretMathOperator(
            const std::string& str, 
            std::unique_ptr<MathOperator>& OutResult) const override;
};

#endif /* SUBTRACTIONOPERATORINTERPRETER_H_ */
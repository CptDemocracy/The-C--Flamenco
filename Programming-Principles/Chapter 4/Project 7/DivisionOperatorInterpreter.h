#ifndef DIVISIONOPERATORINTERPRETER_H_
#define DIVISIONOPERATORINTERPRETER_H_

class MathOperatorInterpreter;

class DivisionOperatorInterpreter : public MathOperatorInterpreter {
    public:
        void InterpretMathOperator(
            const std::string& str, 
            std::unique_ptr<MathOperator>& OutResult) const override;
};

#endif /* DIVISIONOPERATORINTERPRETER_H_ */
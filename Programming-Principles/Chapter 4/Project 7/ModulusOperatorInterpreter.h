#ifndef MODULUSOPERATORINTERPRETER_H_
#define MODULUSOPERATORINTERPRETER_H_

class MathOperatorInterpreter;

class ModulusOperatorInterpreter : public MathOperatorInterpreter {
    public:
        void InterpretMathOperator(
            const std::string& str, 
            std::unique_ptr<MathOperator>& OutResult) const override;
};

#endif /* MODULUSOPERATORINTERPRETER_H_ */
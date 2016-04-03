#ifndef CONVERTER_H
#define CONVERTER_H

typedef double (*ConverterFunctionPtr)(double);

class Converter {
private:
	double (*_convFuncPtr)(double);
public:
	Converter(ConverterFunctionPtr);
	virtual ~Converter();
	double operator()(double) const;
};

#endif /* CONVERTER_H */

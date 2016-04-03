#ifndef CONVERTER_H
#define CONVERTER_H

class Converter {
private:
    double (*_convFuncPtr)(double);
public:
    Converter(double(*convFuncPtr)(double));
    virtual ~Converter();
    double operator()(double) const;
};

#endif /* CONVERTER_H */

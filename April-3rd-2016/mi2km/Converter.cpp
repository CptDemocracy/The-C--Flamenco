#include <stdexcept>
#include "Converter.h"

using std::runtime_error;

Converter::Converter(ConverterFunctionPtr convFuncPtr) {
	if (convFuncPtr == nullptr) {
		throw runtime_error("convFuncPtr cannot be a nullptr");
	}
	this->_convFuncPtr = convFuncPtr;
}

Converter::~Converter() { }

double Converter::operator() (double arg) const {
	return this->_convFuncPtr(arg);
}

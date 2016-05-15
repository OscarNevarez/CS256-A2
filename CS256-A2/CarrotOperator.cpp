#include "CarrotOperator.h"
#include "Value.h"
CarrotOperator::CarrotOperator() {
	operatorSymbol = '^';
	numberOfOperands = 1;
}
Value CarrotOperator::evaluate() {
	double result = operands[0].getValue();
	operands.clear();
	return Value(result);
}

#include "SubtractionOperator.h"
#include "Value.h"
SubtractionOperator::SubtractionOperator() {
	operatorSymbol = '-';
	numberOfOperands = 2;
}
Value SubtractionOperator::evaluate() {
	double result = operands[0].getValue() - operands[1].getValue();
	operands.clear();
	return Value(result);
}
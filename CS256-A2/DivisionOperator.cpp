#include "DivisionOperator.h"
#include "Value.h"
DivisionOperator::DivisionOperator() {
	operatorSymbol = '/';
	numberOfOperands = 2;
}
Value DivisionOperator::evaluate() {
	double result = operands[0].getValue() / operands[1].getValue();
	operands.clear();
	return Value(result);
}

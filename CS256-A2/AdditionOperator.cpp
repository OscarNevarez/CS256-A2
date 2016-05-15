#include "AdditionOperator.h"
#include "Value.h"
AdditionOperator::AdditionOperator() {
	operatorSymbol = '+';
	numberOfOperands = 2;
}
Value AdditionOperator::evaluate() {
	double result= operands[0].getValue() + operands[1].getValue();
	operands.clear();
	return Value(result);
}
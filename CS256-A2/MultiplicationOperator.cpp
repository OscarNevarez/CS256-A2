#include "MultiplicationOperator.h"
#include "Value.h"
MultiplicationOperator::MultiplicationOperator() {
	operatorSymbol = '*';
	numberOfOperands = 2;
}
Value MultiplicationOperator::evaluate() {
	double result = operands[0].getValue() * operands[1].getValue();
	operands.clear();
	return Value(result);
}
#include "EqualsAssingmentOperator.h"
#include "Value.h"
EqualsAssingmentOperator::EqualsAssingmentOperator() {
	operatorSymbol = '=';
	numberOfOperands = 2;
}
Value EqualsAssingmentOperator::evaluate() {
	Value variable = operands[0];
	if (variable.isVariable == true) {
		variable.setValue(operands[1].getValue());
		operands.clear();
	}
	return variable;
}
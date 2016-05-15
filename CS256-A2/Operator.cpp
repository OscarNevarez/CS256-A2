#include "stdafx.h"
#include "Operator.h"

char Operator::getOperatorSymbol()
{
	return operatorSymbol;
}
void Operator::pushOperand(Value operand) {
	operands.push_back(operand);
}

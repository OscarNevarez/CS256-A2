#pragma once
#include <vector>
#include "Value.h"
class Operator {
protected:
	char operatorSymbol;
	std::vector<Value> operands;
public:
	virtual Value evaluate() = 0;
    char getOperatorSymbol();
	void pushOperand(Value operand);
};

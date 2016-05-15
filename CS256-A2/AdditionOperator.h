#pragma once
#include "Operator.h"
class AdditionOperator : public Operator {
public:
	AdditionOperator();
	int numberOfOperands;
	virtual Value evaluate();
};

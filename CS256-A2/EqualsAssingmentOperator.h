#pragma once
#pragma once
#include "Operator.h"
class EqualsAssingmentOperator : public Operator {
public:
	EqualsAssingmentOperator();
	int numberOfOperands;
	virtual Value evaluate();
};
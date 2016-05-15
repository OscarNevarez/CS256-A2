#pragma once
#include "Operator.h"
class MultiplicationOperator : public Operator {
public:
	MultiplicationOperator();
	int numberOfOperands;
	virtual Value evaluate();
};
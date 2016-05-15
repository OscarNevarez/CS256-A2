#pragma once
#pragma once
#include "Operator.h"
class CarrotOperator : public Operator {
public:
	CarrotOperator();
	int numberOfOperands;
	virtual Value evaluate();
};
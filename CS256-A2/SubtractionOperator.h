#pragma once
#pragma once
#include "Operator.h"
class SubtractionOperator : public Operator {
public:
	SubtractionOperator();
	int numberOfOperands;
	virtual Value evaluate();
};
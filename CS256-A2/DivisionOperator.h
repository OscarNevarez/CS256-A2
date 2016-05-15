#pragma once
#include "Operator.h"
class DivisionOperator : public Operator {
public:
	DivisionOperator();
	int numberOfOperands; 
	virtual Value evaluate();
};
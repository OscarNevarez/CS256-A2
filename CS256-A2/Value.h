#pragma once
#include <string>
class Value {
public:
	std::string variable;
	double value;
	bool isVariable;
	bool valueSet;
public:
	Value(double operand);
	double getValue();
	void setValue(double value);
	void setVariable(std::string var);
};
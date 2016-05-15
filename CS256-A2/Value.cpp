#include "Value.h"
#include <string>
Value::Value(double operand) {
	value = operand;
	valueSet = true;
	isVariable = false;
}
double Value::getValue() {
	if (valueSet == true) {
		return value;
	}
	else return 0;
}
void Value::setValue(double value) {
	this->value = value;
	valueSet = true;
}
void Value::setVariable(std::string temp) {
	variable = temp;
	isVariable = true;
}

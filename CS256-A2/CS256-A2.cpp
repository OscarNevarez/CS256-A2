// PostfixEvaluator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "Value.h"
#include "AdditionOperator.h"
#include "CarrotOperator.h"
#include "DivisionOperator.h"
#include "EqualsAssingmentOperator.h"
#include "SubtractionOperator.h"
#include "MultiplicationOperator.h"
using namespace std;

//takes in a string and returns that string as a double!
double parseDoubleInput(string operand) {
	return stod(operand, 0);
}

//helper function for expressionEvaluation, loops gathering the operand in a string
string operandIterator(string expression, int posInString) {
	string operand;
	char currentChar = expression.at(posInString);

	//while the current character is not a space and not an operator
	while (currentChar != ' ' && currentChar != '+' && currentChar != '-' && currentChar != '*' && currentChar != '/') {
		operand += currentChar;
		posInString++;
		//go up one char in string.
		currentChar = expression.at(posInString);
	}
	return operand;
}

//operand are read from left to right in terms of order! 45+  = 4+5 
Value eval(Operator &operate) {
	Value result=operate.evaluate();
	return result;

}

//tries to evalute expression, if expression cannot be evaluated returns false else returns true;
bool expressionEvaluation(string expression, stack<Value>& s,vector<Value> &oldVariables) {
	double operand;
	string operandAsString;

	//store prevoius variables!
	if (s.size() > 0) {
		for (int x = 0; x < s.size(); x++) {
			Value temp = s.top();
			s.pop();
		
			oldVariables.push_back(temp);
		}
	}

	for (int x = 0; x < expression.length(); x++) {

		char currentChar = expression.at(x);
		
		//if current char is valid variable
		if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z')) {

			
			//check previous variables and see if this new variable has the same name
			

			//make a variable with no value.
			Value variable(0.0);
			string var(1,currentChar);
			variable.setVariable(var);
			if (oldVariables.size() > 0) {
				for (int z = 0; z < oldVariables.size(); z++) {
					if (variable.variable == oldVariables[z].variable) {
						variable.setValue(oldVariables[z].getValue());
					}
				}
			}
			s.push(variable);
		}
		//check if currentChar is a number
		else if (currentChar >= 48 && currentChar <= 57) {

			//take the the position in the string and the expression string and call operandIterator
			// will return the operand as string
			operandAsString = operandIterator(expression, x);

			//increase the current position in the string by the length of the operand!
			x += operandAsString.length();

			//parse the operand from string to double
			operand = parseDoubleInput(operandAsString);
			//push operand to stack
			Value operandAsValue(operand);
			s.push(operandAsValue);
		}
		/*if current char is '-' and the current position in the string is not the end
		check if there is a decimal or number next to it, if so then its a negative operand and not a operator!*/
		else if (currentChar == '-' && x != expression.length() - 1 &&
			((expression.at(x + 1) >= '0' && expression.at(x + 1) <= '9') || expression.at(x + 1) == '.')) {

			//call operandIterator at the current char+1 where the number begins
			operandAsString = operandIterator(expression, x + 1);

			//increase the position in the string by the length of the    operand!
			x += operandAsString.length();

			//take the number and parse it using parseInput function
			operand = parseDoubleInput(operandAsString);

			//make the number negative and push to stack.
			s.push(Value(operand*-1));
		}
		//if char is an operator call eval with that operator
		else if (currentChar == '+') {

			Value operand2 = s.top();
			s.pop();
			Value operand1 = s.top();
			s.pop();

			AdditionOperator add;
			add.pushOperand(operand2);
			add.pushOperand(operand1);
			//calculate and push onto stack.
			s.push(eval(add));
			Value temp = s.top();
		}
		else if (currentChar == '-') {
			Value operand2 = s.top();
			s.pop();
			Value operand1 = s.top();
			s.pop();

			SubtractionOperator subtract;
			subtract.pushOperand(operand1);
			subtract.pushOperand(operand2);

			s.push(eval(subtract));
			Value temp = s.top();
		}
		else if (currentChar == '*') {
			Value operand2 = s.top();
			s.pop();
			Value operand1 = s.top();
			s.pop();

			MultiplicationOperator multiply;
			multiply.pushOperand(operand2);
			multiply.pushOperand(operand1);

			s.push(eval(multiply));
			Value temp = s.top();
		}
		else if (currentChar == '/') {
			Value operand2 = s.top();
			s.pop();
			Value operand1 = s.top();
			s.pop();

			DivisionOperator divide;
			divide.pushOperand(operand1);
			divide.pushOperand(operand2);

			s.push(eval(divide));
			Value temp = s.top();


		}
		//prints whats at the top of the stack
		else if (currentChar == '^') {
			Value operand1 = s.top();

			CarrotOperator print;
			print.pushOperand(operand1);
			cout << "Result: "<<eval(print).getValue() << endl;
			cout << endl;
		}
		else if (currentChar == '=') {
			Value operand2 = s.top();
			s.pop();
			Value operand1 = s.top();
			s.pop();

			EqualsAssingmentOperator assign;
			assign.pushOperand(operand1); //variable to be assigned
			assign.pushOperand(operand2);

			s.push(eval(assign));
			Value temp = s.top();

		}
	}
	//after the end of the string is reached if no error occured return true
	return true;
}

string inputExpression() {
	string inputExpression;
	string prompt;
	bool loop = true;
	while (loop) {
		cout << "NOTE: ALL operands and operators must be seperated by a space! Ex: '4 5 + 4 *'" << endl;
		cout << "Negative operands must have a '-' attached to them, ex: -5 not - 5" << endl;
		cout << "Only A-Z, a-z are valid variables! Assignment of variables is only left to right!" << endl;
		cout << "Failure to follow these syntax rules will result in an error while evaluating!" << endl;
		cout << "Enter an expression to evaluate!" << endl;

		getline(cin, inputExpression);
		cout << "Your expression is " << inputExpression << " keep y/n?" << endl;
		getline(cin, prompt);
		if (prompt=="Y" || prompt=="y") {
			loop = false;
			cout << endl;
		}
	}
	cout << endl;
	return inputExpression;
}
int main()
{
	bool evaluated = false;
	stack<Value>s;
	vector<Value> oldVariables;
	
	while (true) {
		string expression = inputExpression();
		//modifies stack, return wether the expression was evaluated succesfully or not!
		evaluated = expressionEvaluation(expression, s,oldVariables);

		if (evaluated != true) {
			cout << "Syntax Error, Expression could not be evaluated!" << endl;
			cout << endl;
			//clear the stack
			for (int x = 0; x < s.size(); x++) {
				s.pop();
			}
		}

	}
}






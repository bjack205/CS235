#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdlib.h>
#include "ExpressionManager.h"

using namespace std;

string toString(int number) {
	ostringstream stream;
	stream << number;
	return stream.str();
}

string EncloseExp(string expression) {
	return "(" + expression + ")";
}

int isBracket(string bracket) {
	//"0" not Bracket
	//"1" Opening
	//"2" Closing
	if (bracket == "(")
		return true;
	if (bracket == "{")
		return true;
	if (bracket == "[")
		return true;
	return false;
}

bool isValid(string expression) {
	istringstream strm;
	string input;
	strm.str(expression);
	while (strm>>input) {
		if (input != "(" && input != ")" &&
			input != "{" && input != "}" &&
			input != "[" && input != "]" &&
			input != "+" && input != "-" &&
			input != "*" && input != "/" &&
			input != "%" &&
			(atoi(input.c_str()) == 0))
			return false;
	}
	return true;
}

bool isOperator(string input) {
	if (atoi(input.c_str())== 0)
		if (input == "+" ||
			input == "-" ||
			input == "*" ||
			input == "/" ||
			input == "%")
			return true;
		else
			return false;
	else
		return false;
}

string ClosingBracket(string openbracket) {
	if (openbracket == "(")
		return ")";
	if (openbracket == "{")
		return "}";
	if (openbracket == "[")
		return "]";
	return NULL;
}

int PerformOperation(int num1, int num2, string operatorstring) {
	if (operatorstring == "+")
		return num2 + num1;
	if (operatorstring == "-")
		return num2 - num1;
	if (operatorstring == "*")
		return num2 * num1;
	if (operatorstring == "/")
		return num2 / num1;
	if (operatorstring == "%")
		return num2 % num1;
	return -1;
}

void PrintStack(stack<string> mystack, string name) {
	stack<string> copy;
	while (!mystack.empty()) {
		copy.push(mystack.top());
		mystack.pop();
	}
	cout << name << ": ";
	while (!copy.empty()) {
		mystack.push(copy.top());
		cout << copy.top() << " ";
		copy.pop();
	}
	cout << endl;
}

void ExpressionManager::PrintYard() {
	PrintStack(yard,"Yard");
}

void ExpressionManager::clear() {
	while (!yard.empty())
		yard.pop();
}

bool ExpressionManager::isBalanced(string expression) {
	istringstream strm;
	string input;
	strm.str(expression);

	cout << "Input: " << expression << endl;
	while (strm>>input){
		if (yard.empty()) {
			if (isBracket(input) == 1)
				yard.push(input);
			else
			{
				clear();
				return false;
			}
		}
		else {
			if (input == ClosingBracket(yard.top()))
				yard.pop();
			else {
				if (isBracket(input) == 1)
					yard.push(input);
				else {
					clear();
					return false;
				}
			}
		}
		PrintYard();
	}
	if (yard.empty())
		return true;
	else {
		clear();
		return false;
	}

}
string ExpressionManager::postfixToInfix(string postfixExpression) {
	if (isValid(postfixExpression)) {

		istringstream strm;
		string input;
		strm.str(postfixExpression);

		cout << "Input: " << postfixExpression << endl;
		while (strm>>input) {
			if (isOperator(input)) {
				if (yard.size() < 2)
					return "invalid";
				else {
					string temp1;
					string temp2;
					string tempresult;
					temp1 = yard.top();
					yard.pop();
					temp2 = yard.top();
					yard.pop();
					tempresult = EncloseExp(temp2) + input + EncloseExp(temp1);
					yard.push(tempresult);
				}
			}
			else if (isBracket(input) > 0)
				return "invalid";
			else {
				yard.push(input);
			}
			PrintYard();
		}

		return yard.top();
	}
	else
		return "invalid";
}
string ExpressionManager::infixToPostfix(string infixExpression) {
	if (isValid(infixExpression)) {

		string test = "40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6";
		string result;
		istringstream strm;
		string input;
		strm.str(infixExpression);
		stack<string> operators;
		stack<string> brackets;

		string currentoperator;
		cout << "Input: " << infixExpression << endl;
		while (strm >> input) {

			cout << input << endl;
			/*
			currentoperator = operators.top();
			if (isOperator(currentoperator) && yard.size() > 1)  {
				string temp1;
				string temp2;
				string tempresult;
				temp1 = yard.top();
				yard.pop();
				temp2 = yard.top();
				yard.pop();
				tempresult = temp2 + " " + temp1 + " " + currentoperator;
				yard.push(tempresult);
			}

			if (isOperator(input)){
				operators.push(input);
			}
			else if (isBracket(input) == 1) {
				operators.push(input);
			}
			else {
				yard.push(input);
			}
			PrintYard();
			PrintStack(operators,"Operators");
			return yard.top();
			*/
		}
	}
	else
		return "invalid";
}
string ExpressionManager::postfixEvaluate(string postfixExpression) {
	if (isValid(postfixExpression)) {
		string result;

		istringstream strm;
		string input;
		strm.str(postfixExpression);

		cout << "Input: " << postfixExpression << endl;
		while (strm>>input) {
			if (isOperator(input)) {
				if (yard.size() < 2) {
					return "invalid";
				}
				else {
					int temp1;
					int temp2;
					int intresult;
					temp1 = atoi(yard.top().c_str());
					yard.pop();
					temp2 = atoi(yard.top().c_str());
					yard.pop();
					if (temp1 == 0 && input == "/")
						return "invalid";
					else {
						intresult = PerformOperation(temp1, temp2, input);
						yard.push(toString(intresult));
					}
				}
			}
			else if (isBracket(input) > 0) {
				return "invalid";
			}
			else {
				yard.push(input);
			}
			PrintYard();
		}
		if (yard.size() == 1) {
			result = yard.top();
			yard.pop();
			return result;
		}
		else
			return "invalid";
	}
	else
		return "invalid";
}



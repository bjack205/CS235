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
	istringstream strm;
	strm.str(expression);
	string input1;
	string input2;

	strm >> input1;
	strm >> input2;
	if (strm.fail())
		return expression;
	else
		return "( " + expression + " )";

}

int isBracket(string bracket) {
	//"0" not Bracket
	//"1" Opening
	//"2" Closing
	if (bracket == "(")
		return 1;
	if (bracket == ")")
		return 2;
	if (bracket == "{")
		return 1;
	if (bracket == "}")
		return 2;
	if (bracket == "[")
		return 1;
	if (bracket == "]")
		return 2;
	return 0;
}

bool check_int(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		char letter = input[i];
		if (!isdigit(letter))
		{
			return false;
		}
	}
	return true;
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
			input != "%" && (atoi(input.c_str()) == 0) &&
			input != "0")
			return false;
		if (atoi(input.c_str()) > 0) {
			if (!check_int(input))
				return false;
		}
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

int OperatorPrecedence(string operatorstring) {
	if (operatorstring == "+" || operatorstring == "-")
		return 1;
	if (operatorstring == "*" || operatorstring == "/")
		return 2;
	if (operatorstring == "(" || operatorstring == ")")
		return -1;
	return 0;
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
	clear();
	istringstream strm;
	string input;
	strm.str(expression);

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
	}
	if (yard.empty())
		return true;
	else {
		clear();
		return false;
	}

}
string ExpressionManager::postfixToInfix(string postfixExpression) {
	clear();
	if (isValid(postfixExpression)) {

		istringstream strm;
		string input;
		strm.str(postfixExpression);

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
					tempresult = EncloseExp(temp2) + " " + input + " " + EncloseExp(temp1);
					yard.push(tempresult);
				}
			}
			else if (isBracket(input) > 0)
				return "invalid";
			else {
				yard.push(input);
			}
		}
		if (yard.size() > 1)
			return "invalid";
		else
			return EncloseExp(yard.top());
	}
	else
		return "invalid";
}
string appendPostFix(string expression, string input) {
	if (expression.length() > 0)
		return expression + " " + input;
	else
		return input;
}
string ExpressionManager::infixToPostfix(string infixExpression) {
	clear();
	if (isValid(infixExpression)) {

		string postfix;
		istringstream strm;
		string input;
		strm.str(infixExpression);

		while (strm >> input) {

			if (isOperator(input) || (isBracket(input) > 0))  {
				if (yard.empty() || (isBracket(input) == 1))
					if (isBracket(input) == 2)
						return "invalid"; //missing parenthesis
					else
						yard.push(input);
				else {
					if (OperatorPrecedence(input) > OperatorPrecedence(yard.top()))
						yard.push(input);
					else {
						while (!yard.empty() &&
							  (isBracket(yard.top()) != 1) &&
							  (OperatorPrecedence(input) <= OperatorPrecedence(yard.top()))) {

							postfix = appendPostFix(postfix,yard.top());
							yard.pop();
						}
						if (isBracket(input) == 2) {
							if (!yard.empty() && (isBracket(yard.top()) == 1)) {
								if (ClosingBracket(yard.top()) == input)
									yard.pop();
								else
									return "invalid";
							}
							else {
								cout << isBracket(input) << endl;
								return "invalid"; //missing parenthesis
							}
						}
						else
							yard.push(input);
					}
				}
			}
			else {
				postfix = appendPostFix(postfix,input);
			}
		}
		while (!yard.empty()) {
			if (isBracket(yard.top()) == 0) {
				postfix = appendPostFix(postfix,yard.top());
				yard.pop();
			}
			else
				return "invalid";
		}
		if (postfixEvaluate(postfix) == "invalid")
			return "invalid";
		else
			return postfix;
	}
	else
		return "invalid";
}
string ExpressionManager::postfixEvaluate(string postfixExpression) {
	clear();
	if (isValid(postfixExpression)) {
		string result;

		istringstream strm;
		string input;
		strm.str(postfixExpression);

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



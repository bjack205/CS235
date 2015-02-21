#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "ExpressionManagerInterface.h"

using namespace std;

class ExpressionManager : public ExpressionManagerInterface {
private:
	stack<string> yard;
public:
	ExpressionManager(){};
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);

	void PrintYard();
	void clear();
};

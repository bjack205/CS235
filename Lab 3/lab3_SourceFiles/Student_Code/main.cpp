#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <cctype>
#include "Header.h"

using namespace std;

bool check_int2(string input)
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
bool isValid2(string expression) {
	istringstream strm;
	string input;
	strm.str(expression);
	while (strm>>input) {
		if (input != "(" && input != ")" &&
			input != "{" && input != "}" &&
			input != "[" && input != "]" &&
			input != "+" && input != "-" &&
			input != "*" && input != "/" &&
			input != "%" && (atoi(input.c_str()) == 0))
			return false;

		if (atoi(input.c_str()) > 0) {
			if (!check_int2(input))
				return false;
		}
	}
	return true;
}

int main() {
	string input;
	ExpressionManager yard;

	cout << check_int2("14 +1") << endl;
	string test1 = "{ + 3 4.2";
	cout << isValid2(test1) << endl;
	//Part 1
	if (false) {
		string test11 = "{ { [ ( ) ] } ( ) }";
		string test12 = "{ [ ) }";
		string test13 = "{ ( [ ] } )";
		string test14 = "{";
		cout << yard.isBalanced(test11) << endl;
		cout << yard.isBalanced(test12) << endl;
		cout << yard.isBalanced(test13) << endl;
		cout << yard.isBalanced(test14) << endl;
	}
	//Part 2
	if (false)  {
		string test21 = "40 + 20";
		string test22 = "40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6";
		string test23 = "{ { 2 + 4}";
		cout << yard.infixToPostfix(test22) << endl;
	}
	//Part 3
	if (true) {
		string test31 = "40 2 4 + 1 1 + - * 4 2 / 1 / - 7 %";
		cout << yard.postfixToInfix(test31) << endl;;
	}
	//Part 4
	if (false) {
		string test41 = "40 2 4 + 1 1 + - * 4 2 / 1 / - 7 %";
		string test42 = "+ 3 4 +";
		string test43 = "4 5 2 + * 2 2 - +";
		cout << "Result: " << yard.postfixEvaluate(test41) << endl;
		cout << "Result: " << yard.postfixEvaluate(test42) << endl;
	}

	cout << "Would you like to exit? y/n ";
	cin >> input;
	if (input == "y")
		return 0;
	else
		return 0;
}

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <cctype>
#include "Header.h"

using namespace std;

int main() {
	string input;
	ExpressionManager yard;

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
	if (true)  {
		string test21 = "40 + 20";
		cout << yard.infixToPostfix(test21) << endl;
	}
	//Part 3
	if (false) {
		string test31 = "40 2 4 + 1 1 + - * 4 2 / 1 / - 7 %";
		cout << yard.postfixToInfix(test31);
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

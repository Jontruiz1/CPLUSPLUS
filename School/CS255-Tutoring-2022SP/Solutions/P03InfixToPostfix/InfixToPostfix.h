// SOLUTION: InfixToPost.h
#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include <iostream>
#include <string>
#include "MyStack.h"
#include <ctype.h>

#include "ExpressionSymbol.h"	// expressionSymbol class
#include "CS255Exceptions.h"	// for expressionError exception

using namespace std;

// labels designating the parentheses characters
const char lParen = '(';
const char rParen = ')';

class InfixToPostfix
{
public:
	// default constructor. infix expression is NULL string
	InfixToPostfix();

	// initialize the infix expression
	InfixToPostfix(const string& infixExp);

	// change the infix expression
	void setInfixExp(const string& infixExp);

	// return a string that contains the equivalent postfix expression.
	//   The function throws ExpressionError if an error occurs during conversion
	string postfix();

private:
	// the infix expression to convert
	string infixExpression;

	// built to contain the postfix equivalent of infixExpression
	string postfixExpression;

	// stack of expressionSymbol objects
	myStack<ExpressionSymbol> operatorStack;

	// The expressionSymbol object op holds the current symbol.
	//   Pop the stack and output as long as the symbol
	//   on the top of the stack has a precedence >= that of
	//   the current operator
	void outputHigherOrEqual(const ExpressionSymbol& op);

	// is ch one of '+','-','*','/', '^'
	bool isOperator(char ch) const;
};

void InfixToPostfix::outputHigherOrEqual(const ExpressionSymbol& op) {
	ExpressionSymbol op2;

	while (!operatorStack.isEmpty() && (op2 = operatorStack.top()) >= op) {
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool InfixToPostfix::isOperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

InfixToPostfix::InfixToPostfix() {}

InfixToPostfix::InfixToPostfix(const string& infixExp) : infixExpression{ infixExp } {}

void InfixToPostfix::setInfixExp(const string& infixExp) {
	// assign a new infix expression
	infixExpression = infixExp;
	// make postfixExpression the NULL string
	postfixExpression = "";
}

string InfixToPostfix::postfix() {
	ExpressionSymbol op;
	size_t i;
	char ch;

	// process until end of the expression
	for (i = 0; i < infixExpression.length(); i++) {
		ch = infixExpression[i];

		//  ********  process an operand  ********
		// an operand is a single digit non-negative integer
		if (isdigit(ch)) {
			// just add operand to output expression, followed by a blank
			postfixExpression += ch;
			postfixExpression += ' ';

		}
		//  *********  process an operator or '('  **********
		else if (isOperator(ch) || ch == '(') {
			// output the operators on the stack with higher
			// or equal precedence. push the current operator
			// on the stack
			op = ExpressionSymbol(ch);
			outputHigherOrEqual(op);
			operatorStack.push(op);
		}
		//  *********  process a right parenthesis  **********
		else if (ch == rParen) {
			// build an expressionSymbol object holding ')', which
			// has precedence lower than the stack precedence
			// of any operator except '('. pop the operator stack
			// and output operators from the subexpression until
			// '(' surfaces or the stack is empty. if the stack is
			// empty, a '(' is missing; otherwise, pop off '('.
			op = ExpressionSymbol(ch);
			outputHigherOrEqual(op);
			if (operatorStack.isEmpty())
				throw ExpressionError("InfixToPostfix: Missing '('");
			else
				operatorStack.pop(); // get rid of '('
		}
		//  *********  make sure ch is whitespace  **********
		else if (!isspace(ch))
			throw ExpressionError("InfixToPostfix: Invalid input");
	} //end of for-loop for iterating across infixExpression

	// FINISH PROCESSING

	// Flush operator stack and complete building postfixExpression.
	//  If left parenthesis is found, a right parenthesis is missing.
	while (!operatorStack.isEmpty()) {
		op = operatorStack.top();
		operatorStack.pop();

		if (op.getOp() == lParen)
			throw ExpressionError("InfixToPostfix: Missing ')'");
		else {
			postfixExpression += op.getOp();
			postfixExpression += ' ';
		}
	}

	return postfixExpression;
}
#endif	// INFIX_TO_POSTFIX
// TO BE COMPLETED:
//		compute()
//		evaluate()

// SOLUTION: PostfixEval.h
#ifndef POSTFIX_EVAL
#define POSTFIX_EVAL

#include <iostream>
#include <string>
#include <ctype.h>
#include "MyStack.h"
#include "CS255Exceptions.h"	// for expressionError exception

using namespace std;

class PostfixEval {
public:
	// default constructor. postfix expression is NULL string
	PostfixEval();

	// return the postfix expression
	string getPostfixExp() const;

	// change the postfix expression
	void setPostfixExp(const string& postfixExp);

	// evaluate the postfix expression and return its value.
	//  the function throws expressionError
	//  if an error (e.g. divison by zero) occurs during evaluation
	int evaluate();

private:
	// the postfix expression to evaluate
	string postfixExpression;

	// stack of operands
	myStack<int> operandStack;

	// pop left and right operands from stack.
	// Precondition: the stack must have at least two entries.
	// if the stack is empty prior to a pop() operation, the
	// function throws the exception expressionError
	void getOperands(int& left, int& right);

	// compute "left op right". if right is 0 and op
	// is '/' , the function throws expressionError
	int compute(int left, int right, char op) const;

	// is ch one of '+','-','*','/' ,'^'
	bool isOperator(char ch) const;
};

void PostfixEval::getOperands(int& left, int& right) {
	// can we pop the right operand?
	if (operandStack.isEmpty())
		throw  ExpressionError("postfixEval: Too many operators");

	// pop right operand
	right = operandStack.top();
	operandStack.pop();

	// can we pop the left operand?
	if (operandStack.isEmpty())
		throw  ExpressionError("PostfixEval: Too many operators");

	// pop left operand
	left = operandStack.top();
	operandStack.pop();
}

int PostfixEval::compute(int left, int right, char op) const {
					/**** TO BE COMPLETED *****/
	switch (op) {
	case '+': return left + right; 
	case '-': return left - right;
	case '*': return left * right;
	case '/': 
		if (right == 0) throw ExpressionError("div by 0");
		return left / right;
	case '^': 
		if (left == 0 && right == 0) throw ExpressionError("indeterminate");
		return pow(left, right);
	}
} // end compute()

bool PostfixEval::isOperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// default constructor
PostfixEval::PostfixEval() {}

string PostfixEval::getPostfixExp() const {
	return postfixExpression;
}

void PostfixEval::setPostfixExp(const string& postfixExp) {
	postfixExpression = postfixExp;
}

int PostfixEval::evaluate() {
					/**** TO BE COMPLETED *****/
	int left, right;
	char ch;
	int finalVal;
	
	
	for (int i = 0; i < postfixExpression.size(); ++i) {
		ch = postfixExpression[i];
		ExpressionSymbol op(ch);
		
		if (isdigit(ch)) {
			operandStack.push(ch - '0');
		}
		else if (isOperator(ch)) {
			getOperands(left, right);
			operandStack.push(compute(left, right, ch));
		}
		else if (!isspace(ch)) {
			throw ExpressionError("stop");
		}

	}
	
	finalVal = operandStack.top();
	operandStack.pop();

	if (!operandStack.isEmpty()) {
		throw ExpressionError("something");
	}
	return finalVal;
} // end evaluate();
#endif	// POSTFIX_EVAL

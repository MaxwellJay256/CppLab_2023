#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*/
/// @brief 运算符栈
stack<char> *operators;
/// @brief 操作数栈
stack<double> *operands;
//*/

/// @brief 判断字符是否为运算符
/// @param c 字符
bool isOperator(char c);

/// @brief 判断字符是否为括号
/// @param c 字符
bool isParenthesis(char c);

/// @brief 判断字符是否为左括号
/// @param c 字符
bool isLeftParenthesis(char c);

/// @brief 判断字符是否为右括号
/// @param c 字符
bool isRightParenthesis(char c);

/// @brief 获取操作符的优先级
/// @param op 
/// @return 枚举值：0表示最低优先级，1表示+和-，2表示*和/
int getPrecedence(char op);

/// @brief 计算 2 个操作数的运算结果
/// @param operand1 操作数 1
/// @param operand2 操作数 2
/// @param op 运算符 "+", "-", "*", "/"
/// @return 计算结果
double calculate(double operand1, double operand2, char op);

/// @brief 计算表达式的值
/// @param expression 一个四则运算表达式
void CalculateExpression(const string& expression);

/// @brief 计算操作符栈顶的运算
/// @param topOperator 栈顶的运算符
void calculateTopOperator(char op);

bool MatchParenthesis(char rightParenthesis, char leftParenthesis);

#endif
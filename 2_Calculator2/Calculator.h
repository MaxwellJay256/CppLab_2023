#pragma once
#include <string>
#include <iostream>
#include "Stack.h"

class Calculator
{
    public:
    /// @brief 构造一个计算器对象
    Calculator();
    ~Calculator();
    /// @brief 运行计算器
    void Run();
private:
    /// @brief 操作数栈
    Stack<double> *operands;
    /// @brief 操作符栈
    Stack<char> *operators;
    /// @brief 判断字符是否为运算符
    /// @param c 字符
    bool isOperator(char c);
    /// @brief 判断字符是否为左括号
    /// @param c 字符
    bool isLeftParenthesis(char c);
    /// @brief 判断字符是否为右括号
    /// @param c 字符
    bool isRightParenthesis(char c);
    /// @brief 判断字符是否为括号
    /// @param c 字符
    bool isParenthesis(char c);
    /// @brief 获取操作符的优先级
    /// @param op 
    /// @return 枚举值：0 表示最低优先级，1 表示 + 和 -，2 表示 * 和 /
    int getPrecedence(char op);
    /// @brief 计算 2 个操作数的运算结果
    /// @param operand1 操作数 1
    /// @param operand2 操作数 2
    /// @param op 运算符 "+", "-", "*", "/"
    /// @return 计算结果
    double calculate(double operand1, double operand2, char op);
    /// @brief 核心函数 - 计算表达式的值
    /// @param expression 一个四则运算表达式
    void CalculateExpression(const std::string& expression);
    /// @brief 计算操作符栈顶的运算
    /// @param topOperator 栈顶的运算符
    void CalculateTopOperator(char op);
    /// @brief 判断传入的左右括号是否匹配
    /// @param rightParenthesis 右括号
    /// @param leftParenthesis 左括号
    /// @return true 匹配，false 不匹配
    bool MatchParenthesis(char rightParenthesis, char leftParenthesis);
};


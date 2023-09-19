#include "Calculator.h"

Calculator::Calculator()
{
    operators = new Stack<char>(20);
    operands = new Stack<double>(20);
}

Calculator::~Calculator()
{
    delete operators;
    delete operands;
}

void Calculator::Run()
{
    std::string expression;
    std::cout << "Please input an expression: ";
    getline(std::cin, expression);
    CalculateExpression(expression);
}

bool Calculator::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool Calculator::isLeftParenthesis(char c)
{
    return (c == '(' || c == '[' || c == '{');
}
bool Calculator::isRightParenthesis(char c)
{
    return (c == ')' || c == ']' || c == '}');
}
bool Calculator::isParenthesis(char c)
{
    return (isLeftParenthesis(c) || isRightParenthesis(c));
}

int Calculator::getPrecedence(char op)
{
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

double Calculator::calculate(double operand1, double operand2, char op)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        std::cout << "Error: \'" << op << "\' is not a valid operator." << std::endl;
        return 0;
    }
}

bool Calculator::MatchParenthesis(char rightParenthesis, char leftParenthesis)
{
    bool result = false;
    if (rightParenthesis == ')' && leftParenthesis == '(') {
        result = true;
    } else if (rightParenthesis == ']' && leftParenthesis == '[') {
        result = true;
    } else if (rightParenthesis == '}' && leftParenthesis == '{') {
        result = true;
    }

    return result;
}

void Calculator::CalculateTopOperator(char topOperator)
{
    if (operands->size() < 2) {
        std::cout << "Invalid expression." << std::endl;
        return;
    }
    double operand2 = operands->pop();
    double operand1 = operands->pop();

    double result = calculate(operand1, operand2, topOperator);
    operands->push(result);
}

void Calculator::CalculateExpression(const std::string& expression)
{
    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];

        // 允许表达式中出现空格
        if (currentChar == ' ') {
            continue;
        }

        // 识别到数字
        if (isdigit(currentChar) || currentChar == '.')
        {
            std::string numericString;
            int j = i;
            while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.'))
            {
                numericString += expression[j];
                j++;
            }
            i = j - 1;

            double operand = stod(numericString); //调用标准库将字符串转换为 double
			operands->push(operand);
        // 识别到运算符
        }
        else if (isOperator(currentChar))
        {
            // 如果操作符栈顶的操作符优先级大于等于当前操作符，则先计算栈顶的操作符
            while (!operators->isEmpty() && isOperator(operators->top()) && (getPrecedence(currentChar) <= getPrecedence(operators->top()))) {
                CalculateTopOperator(operators->pop());
            }
            operators->push(currentChar); // 将当前操作符压入栈顶
        }
        else if (isLeftParenthesis(currentChar))// 识别到左括号
        {
            operators->push(currentChar);
        }
        else if (isRightParenthesis(currentChar))// 识别到右括号
        {
            if (operators->isEmpty()) {
                std::cout << "Invalid expression." << std::endl;
                return;
            }
            //char topOperator = operators->top();
            while (!operators->isEmpty() && !isLeftParenthesis(operators->top()))
            {
                CalculateTopOperator(operators->pop());
                if (operators->isEmpty()) {
                    std::cout << "Invalid expression." << std::endl;
                    return;
                }
            }
            if (!MatchParenthesis(currentChar, operators->top()))
            {
                std::cout << "Invalid expression: Left and right parenthesis doesn't match." << std::endl;
                return;
            }
            operators->pop();// 弹出左括号
        // 识别到非法字符
        }
        else {
            std::cout << "Invalid character: " << currentChar << std::endl;
            return;
        }
        /*/ 输出当前两个栈的内容
        std::cout << "Operators: ";
        operators->print();
        std::cout << "Operands: ";
        operands->print();
        //*/
    }

    while (!operators->isEmpty()) {
        if (isParenthesis(operators->top())) {
            std::cout << "Invalid expression." << std::endl;
            return;
        }
        CalculateTopOperator(operators->pop());
    }

    if (operands->size() != 1) {
        std::cout << "Invalid expression." << std::endl;
        return;
    }

    std::cout << "Result: " << operands->top() << std::endl << std::endl;
}
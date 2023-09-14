#include "Calculator.h"

stack<char> *operators;
stack<double> *operands;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isLeftParenthesis(char c) {
    return (c == '(' || c == '[' || c == '{');
}
bool isRightParenthesis(char c) {
    return (c == ')' || c == ']' || c == '}');
}
bool isParenthesis(char c) {
    return (isLeftParenthesis(c) || isRightParenthesis(c));
}

int getPrecedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

double calculate(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            cout << "Error: \'" << op << "\' is not a valid operator." << endl;
            return 0;
    }
}

void CalculateExpression(const string& expression)
{
    operators = new stack<char>();
    operands = new stack<double>();

    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];

        // 允许表达式中出现空格
        if (currentChar == ' ') {
            continue;
        }

        // 识别到数字
        if (isdigit(currentChar) || currentChar == '.')
        {
            string numericString;
            int j = i;
            while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.'))
            {
                numericString += expression[j];
                j++;
            }
            i = j - 1;

            double operand = stod(numericString); //调用标准库将字符串转换为double
			operands->push(operand);
        // 识别到运算符
        }
        else if (isOperator(currentChar))
        {
            // 如果操作符栈顶的操作符优先级大于等于当前操作符，则先计算栈顶的操作符
            while (!operators->empty() && isOperator(operators->top()) &&
                   (getPrecedence(currentChar) <= getPrecedence(operators->top()))) {
                calculateTopOperator(operators->top());
            }
            operators->push(currentChar); // 将当前操作符压入栈顶
        
        // 识别到括号
        }
        else if (isLeftParenthesis(currentChar)) {
            operators->push(currentChar);
        }
        else if (isRightParenthesis(currentChar)) {
            if (operators->empty()) {
                cout << "Invalid expression." << endl;
                return;
            }
            char topOperator = operators->top();
            if (!MatchParenthesis(currentChar, topOperator)) {
                cout << "Invalid expression: Left and right parentthesis doesn't match." << endl;
                return;
            }
            while (!isLeftParenthesis(topOperator))
            {
                calculateTopOperator(topOperator);
                if (operators->empty()) {
                    cout << "Invalid expression." << endl;
                    return;
                }
                topOperator = operators->top();
            }

            operators->pop();
        // 识别到非法字符
        }
        else {
            cout << "Invalid character: " << currentChar << endl;
            return;
        }
    }

    while (!operators->empty()) {
        if (isParenthesis(operators->top())) {
            cout << "Invalid expression." << endl;
            return;
        }
        calculateTopOperator(operators->top());
    }

    if (operands->size() != 1) {
        cout << "Invalid expression." << endl;
        return;
    }

    double finalResult = operands->top();
    cout << "Result: " << finalResult << endl;

    delete operators;
    delete operands;
}

void calculateTopOperator(char topOperator)
{
    //topOperator = operators->top();
    operators->pop();

    if (operands->size() < 2) {
        cout << "Invalid expression." << endl;
        return;
    }
    double operand2 = operands->top();
    operands->pop();
    double operand1 = operands->top();
    operands->pop();

    double result = calculate(operand1, operand2, topOperator);
    operands->push(result);
}

bool MatchParenthesis(char rightParenthesis, char leftParenthesis)
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
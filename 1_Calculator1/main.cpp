#include <iostream>
#include <string>
#include "Calculator.h"

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    CalculateExpression(expression);

    return 0;
}
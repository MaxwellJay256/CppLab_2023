#include <iostream>
#include <string>
#include "Stack.h"
#include "Calculator.h"

int main()
{
    Calculator *calculator;
    while (true)
    {
        calculator = new Calculator();
        calculator->Run();
        delete calculator;
    }

    return 0;
}
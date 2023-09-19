#pragma once
#include <iostream>

template <typename T>
class Stack
{
public:
    /// @brief 栈的构造函数
    /// @param size 栈大小，默认为 100
    Stack(int size = 100);
    ~Stack();
    /// @brief 检查栈是否为空
    /// @return 栈为空返回 true，否则返回 false
    bool isEmpty() const;
    /// @brief 检查栈是否满
    /// @return 栈满返回 true，否则返回 false
    bool isFull() const;
    /// @brief 压栈
    /// @param item 压入的元素 
    void push(T item);
    /// @brief 弹出栈顶元素
    /// @return 栈顶的元素
    T pop();
    /// @brief 获取栈顶元素
    /// @return 栈顶的元素
    T top() const;
    /// @brief 获取栈的大小
    /// @return 栈当前大小
    int size() const;
    /// @brief 打印栈内所有元素
    void print() const;
private:
    /// @brief 栈的数据
    T* m_data;
    /// @brief 栈的大小
    int m_size;
    /// @brief 栈顶，指向栈顶元素的下一个位置
    int m_top;
};

#include "Stack.cpp"
#pragma once
#include "Stack.h"

template <typename T>
Stack<T>::Stack(int size)
{
    m_size = size;
    m_data = new T[m_size];
    m_top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] m_data;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return m_top == -1;
}

template <typename T>
bool Stack<T>::isFull() const
{
    return m_top == m_size - 1;
}

template <typename T>
void Stack<T>::push(T item)
{
    if (isFull())
    {
        std::cout << "Stack is full, cannot push item!" << std::endl;
        return;
    }
    m_data[++m_top] = item;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty, cannot pop item!" << std::endl;
        return T();
    }
    return m_data[m_top--];
}

template <typename T>
T Stack<T>::top() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty!" << std::endl;
        return T();
    }
    return m_data[m_top];
}

template <typename T>
int Stack<T>::size() const
{
    return m_top + 1;
}

template <typename T>
void Stack<T>::print() const
{
    for (int i = 0; i <= m_top; ++i)
    {
        std::cout << m_data[i] << ' ';
    }
    std::cout << '\n';
}
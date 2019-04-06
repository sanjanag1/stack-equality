#include <iostream>
#include <cassert>

#include "stack.h"

using namespace std;

template <class Item>
Stack<Item>::Stack()
{
    topStack = 0;
}

template <class Item>
Stack<Item>::Stack(int stackSize)
{
    maxSize = stackSize;
    list = new Item[maxSize];
}

template <class Item>
bool Stack<Item>::isEmpty()
{
    return(topStack == maxSize);
}

template <class Item>
bool Stack<Item>::isFull()
{
    return(topStack == maxSize);
}

template <class Item>
void Stack<Item>::push(const Item& newItem)
{
    if(!isFull())
    {
        list[topStack] = newItem;
        topStack++;
    }
    else
    { 
        std::cout << "Cannot add to a full stack.\n";
    }
}

template <class Item>
Item Stack<Item>::top()
{
    assert(topStack!=0);
    return list[topStack-1];
}

template<class Item>
void Stack<Item>::pop()
{
    if(!isEmpty())
    {
        topStack--;
    }
    else
    {
       std::cout << "Cannot remove element from an empty stack. \n";
    }
}

template <class Item>
bool compare(Stack<Item> s1, Stack<Item> s2)
{
    if(!s1.isEmpty() && !s2.isEmpty())
    {
        std::cout << "Cannot compare empty stacks.\n" ;
        return false;
    }
    while(!s1.isEmpty() || !s2.isEmpty())
    {
        if(s1.top() == s2.top())
        {
            s1.pop();
            s2.pop();
        }
        else
            break;
    }
}

int main()
{
    bool result;
    Stack<int> s1;
    Stack<int> s2;
    s1.push(10);
    s1.push(10);
    s2.push(20);
    s2.push(20);
    result = compare(s1,s2);
    if(result == true)
       std::cout << "The stacks are equal";
}
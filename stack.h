#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;


template <class Item>
class Stack{
public:
   Stack();
   Stack(int stackSize);
   bool isEmpty();
   bool isFull();
   void push(const Item& newItem);
   Item top();
   void pop();
   bool compare(const Stack<Item>& s1, const Stack<Item>& s2);
private:
    int maxSize;
    int topStack;
    typedef Item value;
    Item *list;
};

#endif

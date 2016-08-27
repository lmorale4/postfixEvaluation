//Stack.h
#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

typedef int ItemType;

class Stack{
  public:
    Stack();
    // create a Stac object with 0 items in it

    ~Stack();
    // returns heap memory space
    
    int size() const;
    // return the number of elemens in the stack
 
    bool empty() const;
    // return the number of elements in the stack

    void push(ItemType x);
    // add x to the stack, increase size()
  
    ItemType pop();
    // remove th element most recently added to he stack, decrease size()

    ItemType top();
    // return element most recently added to the stack
    
  private:
	
    class Node{
      public:
        ItemType data;
        Node * next;
    };
    int stackSize;
    Node * head;
};
#endif

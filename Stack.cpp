// stack.cpp

#include "Stack.h"
using namespace std;

Stack::Stack(){
  head;
  stackSize = 0;
}

Stack::~Stack(){
  cout << "Stack object is being destroyed."<< endl;
  Node * temp;
  for(int i=0; i<stackSize; i++){
    temp = head;
    head = head->next;
    delete temp;
  }
}

int Stack::size() const{
  return stackSize;
}

bool Stack::empty() const{
  return stackSize == 0;
}


void Stack::push(ItemType x){
  if(stackSize == 0){
    head = new Node;
    head->data = x;
  }
  else{
    Node * temp = head;
    head = new Node;
    head->data = x;
    head->next = temp;
  }
  stackSize++;
}

ItemType Stack::pop(){
  Node * temp = head;
  ItemType retVal;
  head = head->next;
  retVal = temp->data;
  delete temp;
  stackSize--;
  return retVal; 
}

ItemType Stack::top(){
  return head->data;
}

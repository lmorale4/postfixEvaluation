//Queue.h

#ifndef QUEUE
#define QUEUE

#include <iostream>
using namespace std;

typedef string ElementType;

class Queue{
  public:
    Queue();
    // initializes data memebers

    ~Queue();
    // deletes memory in the heap

    int size() const;
    // returns size of queue
 
    bool empty() const;
    // returns true if queue has no items in it

    void enqueue(ElementType item);
    // adds an item to top of queue

    void dequeue();
    // deletes the oldest data added to the queue
  
    ElementType front();
    // returns element that has been in the queue the longest

  private:
    class Node{
      public:
        ElementType data;
        Node * next;
    };
    Node * head;
    Node * last;
    int qSize;

};
#endif

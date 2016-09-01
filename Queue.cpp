#include "Queue.h"
using namespace std;

Queue::Queue(){
  head = NULL;
  last = NULL;
  qSize = 0;
}

Queue::~Queue(){
  // cout << "Queue object is being destroyed."<< endl;
	if(!empty()){
		Node * temp = head;
		for(int i=0; i<qSize; i++){
			head = head->next;
			delete temp;
			temp = head;
		}
	}
}

int Queue::size() const{
  return qSize;
}

bool Queue::empty() const{
  return qSize == 0;
}

void Queue::enqueue(ElementType item){
  if(empty()){
    head = new Node;
    head->data = item;
    last = head;
  }
  else{
    last->next = new Node;
    last = last->next;
    last->data = item;
  }
  qSize++;
}
void Queue::dequeue(){
  if(qSize!=0){
    Node* temp = head;
    head = head->next;
    delete temp;
    qSize--;
  }
  else{
    cout<<"Queue is empty. It cannot be dequeued"<<endl;
  }
}

ElementType Queue::front(){
  return head->data;
}

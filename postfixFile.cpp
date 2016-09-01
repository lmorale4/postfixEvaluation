#include "Stack.h"
#include "Queue.h"

#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

void iterateThroughFile(ifstream& uFile);
// input: a file to read, a Queue and a Stack
// output: none
// side effects; iterates through the lines in the file and
//   evaluates the postfix expression

void enqueueTokens(string line, Queue& q);
// input: a string and a Queue
// output: none
// side effects; enqueues tokens in line to the Queue

int evaluatePostfix(Queue& q, Stack& s);
// input: a Queue and a Stack
// output: none
// side effects;

void writeToFile(ofstream& r,string line, int result);
// input: a file to write in, a string and a Stack
// output: none
// side effects; writes items in stack to a file

int main(){
  //string userStr;
  //cout<< "What is the name of your file? "<< endl;
  //cin >> userStr;
  //ifstream userFile(userStr.c_str());

  ifstream userFile("file.txt");

  Stack values;
  iterateThroughFile(userFile);

  userFile.close();
}

void iterateThroughFile(ifstream& uFile){
  string line;
  if(uFile){
    ofstream result;
    result.open("postfixResults.txt");
    while(getline(uFile, line)){
      if(line.length() > 0){
        Queue q;
        Stack s;
        enqueueTokens(line, q);
        int eval = evaluatePostfix(q, s);
        writeToFile(result, line, eval);
      }
    }
  }
  else{
    cout << "The file was not opened properly" << endl;
  }
}

void enqueueTokens(string line, Queue& q){
	string item;
	istringstream s(line);
	
	while(s){
		s >> item;
		if(item != "#"){
			q.enqueue(item);
		}
	}
}

int evaluatePostfix(Queue& q, Stack& s){
  int sz = q.size();
  for(int i=0; i<sz; i++){
    string token = q.front();
    q.dequeue();
    if(isdigit(token[0])){
      int num = stoi(token);
      s.push(num);
    }
    else{
        int num2 = s.pop();
        int num1 = s.pop();
        int result;
        if(token == "+"){
          result = num1 + num2;
        }
        else if(token == "-"){
          result = num1 - num2;
        }
        else if(token == "*"){
          result = num1 * num2;
        }
        else if(token == "/"){
          result = num1 / num2;
        }
        else{
          cout << "We do not recognize this operand" << endl;
        }
        s.push(result);
    }
  }
	return s.pop();
}

void writeToFile(ofstream& r,string line, int result){
	istringstream iss(line);
	string postfix;
	string item;
	
	while(iss){
		iss >> item;
		if(item != "#"){
			postfix += item + " ";
		}
	}
	
	r << "The postfix expression, "<< postfix << " was evaluated to be "<< result<<"\n";
}
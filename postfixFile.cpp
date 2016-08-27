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

void evaluatePostfix(Queue& q, Stack& s);
// input: a Queue and a Stack
// output: none
// side effects;

void writeToFile(ofstream& r,string line, Stack& s);
// input: a file to write in, a string and a Stack
// output: none
// side effects; writes items in stack to a file
 
string charToStr(char c);
// input: a char
// output: a string
// side effects: converts a char into a string

int stringToInt(string str);
// input: a string
// output: an int
// side effects: converts a string to an int


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
        evaluatePostfix(q, s);
        writeToFile(result, line, s);
      }
    }
  }
  else{
    cout << "The file was not opened properly" << endl;
  }
}

void enqueueTokens(string line, Queue& q){
  string str;
  for(int i=0; i<line.length(); i++){
    if(line[i] != ' '){
        str += line[i];
    }
    else{
        q.enqueue(str);
        str = "";
    }
  }
}

void evaluatePostfix(Queue& q, Stack& s){
  int sz = q.size();
  for(int i=0; i<sz; i++){
    string token = q.front();
    q.dequeue();
    if(isdigit(token[0])){
      int num = stringToInt(token);
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
}

void writeToFile(ofstream& r,string line, Stack& s){
  string postfix;
  for(int i=0; i<line.length(); i++){
    if(charToStr(line[i]).compare("#")!= 0){
      postfix += charToStr(line[i]);
    }
  }
  r << "The postfix expression, "<< postfix << " was evaluated to be "<< s.pop()<<"\n";
}

string charToStr(char c){
  stringstream ss;
  string str;
  ss << c;
  ss >> str;
  return str;
}

int stringToInt(string str){
   stringstream ss;
   int num;
   ss << str;
   ss >> num;
   return num;
}


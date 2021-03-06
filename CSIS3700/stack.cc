#include <iostream>
using namespace std;

class node {

private:
  int contents;
  node *next;

public:
  int getval() {
    return contents;
  }

  void setnext(node *newnext) {
    next=newnext;
  }

  node * getnext() {
    return next;
  }

  node(int value) {
    contents=value;
  }
};

class stack {

private:
  node *top;

public:
  void push(int value) {
    node *newnode;
    newnode=new node(value);
    newnode->setnext(top);
    top=newnode;
    return;
  }

  void pop() {
    node *temp;
    if(top==NULL) {
      cout << "Error:  stack is empty.\n";
      return;
    }
    else {
      cout << top->getval() << endl;
      temp=top;
      top=temp->getnext();
      delete temp;
    }
    return;
  }

  stack() {
    top=NULL;
  }
};

int main() {

stack s;
s.push(30);
s.push(40);
s.pop();
s.pop();
s.push(100);
s.push(200);
s.pop();
s.pop();
s.pop();
s.pop();
s.push(1000);
s.push(2000);
s.pop();

return 0;
}

//CSIS 3700 Lab #4 -- James Curnalia


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
    next=NULL;
  }
};

class queue{

private:
  node *end;
  node *front;

public:
  void add(int value) {
    node *newnode;
    newnode=new node(value);
    if(end==NULL)
      end=newnode;
    else {
      end->setnext(newnode);
      end=newnode;
    }
    if(front==NULL)
      front=newnode;
    return;
  }

  void serve() {
    node *temp;
    if(front==NULL) {
      cout << "Error:  Line is empty.\n";
      return;
    }
    else {
      cout << front->getval() << endl;
      temp=front;
      front=temp->getnext();
      delete temp;
    }
    return;
  }

  queue() {
    end=NULL;
    front=NULL;
  }
};

int main() {

queue s;
s.add(100);
s.add(200);
s.add(300);
s.add(400);
s.serve();
s.serve();
s.serve();
s.add(500);
s.serve();
s.serve();
s.serve();


return 0;
}

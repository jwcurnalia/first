//James Curnalia CSIS 3700 lab5


#include <iostream>
using namespace std;

struct {
char contents;
int left, right;
} node [11] =
  {'A',1,2,'B',3,4,'C',-1,5,'D',-1,-1,'E',6,-1,
   'F',7,8,'G',-1,-1,'H',9,-1,'I',-1,-1,'J',-1,
   10,'K',-1,-1 };

void preorder(int n) {
  if(n == -1)
    return;
  else {
    cout << node[n].contents << " ";
    preorder(node[n].left);
    preorder(node[n].right);
    return;
  }
}

void inorder(int n) {
  if(n == -1)
    return;
  else {
    inorder(node[n].left);
    cout << node[n].contents << " ";
    inorder(node[n].right);
    return;
  }
}

void postorder(int n) {
  if(n == -1)
    return;
  else {
    postorder(node[n].left);
    postorder(node[n].right);
    cout << node[n].contents << " ";
    return;
  }
}

int main() {

  cout << "Preorder:  ";
  preorder(0);
  cout << endl;

  cout << "In Order:  ";
  inorder(0);
  cout << endl;

  cout << "Postorder:  ";
  postorder(0);
  cout << endl;

return 0;
}

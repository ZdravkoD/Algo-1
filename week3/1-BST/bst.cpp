#include <iostream>

using namespace std;

class Node {
public:
  Node(int value,Node *left, Node *right) { // constructor
    this->value = value;
    this->left = left;
    this->right = right;
    }

  int value;
  Node* left;
  Node* right;
};

class BST {
public:

  // Checks if a binary tree is a binary search tree.
  bool isBST(Node* root) {
    bool l=true,r=true;
    if(root->left != NULL) {
      if(root->left->value < root->value)
        l = isBST(root->left);
      else
        return false;
      }
    if(root->right != NULL) {
      if(root->right->value >= root->value)
        r = isBST(root->right);
      else
        return false;
      }
    return l && r;
    }
};

int main()
{
  Node N(1,NULL,NULL), N1(5,NULL,NULL), N2(2,NULL,NULL), N3(8,NULL,NULL), N4(4,&N,&N1), N5(7,&N2,&N3), N6(6,&N4,&N5);
  Node M(1,NULL,NULL), M1(5,NULL,NULL), M2(2,NULL,NULL), M3(8,NULL,NULL), M4(4,&M,&M1), M5(7,&M2,&M3), M6(200,&M4,&M5);

  BST B;
  cout << B.isBST(&N6) << endl;
  cout << B.isBST(&M6) << endl;
  return 0;
}

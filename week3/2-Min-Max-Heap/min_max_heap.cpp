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

class MinMaxHeap {
public:

  // Checks if a binary tree is a min/max heap.
  bool isMinMax(Node* root) {
    bool l=true,r=true;
    static int Level = 1;
    bool Odd=Level%2;

    if(root->left != NULL) {
      if((Odd && root->left->value > root->value) || (!Odd && root->left->value < root->value)) {
        Level++;
        l = isMinMax(root->left);
        }
      else {
        Level--;
        return false;
        }
      }
    if(root->right != NULL) {
      if((Odd && root->right->value > root->value) || (!Odd && root->right->value < root->value)) {
        Level++;
        r = isMinMax(root->right);
        }
      else {
        Level--;
        return false;
        }
      }
    Level--;
    return l && r;
    }
};

int main()
{
  Node N(1,NULL,NULL), N1(5,NULL,NULL), N2(2,NULL,NULL), N3(8,NULL,NULL), N4(4,&N,&N1), N5(7,&N2,&N3), N6(6,&N4,&N5);
//  Node N(6,NULL,NULL), N1(5,NULL,NULL), N2(9,NULL,NULL), N3(8,NULL,NULL), N4(4,&N,&N1), N5(7,&N2,&N3), N6(3,&N4,&N5);

  MinMaxHeap MMH;

  cout << MMH.isMinMax(&N6) << endl;

  return 0;
}

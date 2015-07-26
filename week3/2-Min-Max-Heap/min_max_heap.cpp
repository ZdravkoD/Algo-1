#include <cstdio>

using namespace std;
int n;

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
  bool isMinMax(Node *root) {
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
  MinMaxHeap MMH;

  scanf("%d",&n);
  if(n<=0)
    return 0;
  else if(n==1) {
    printf("YES");
    return 0;
  }

  int cur;
  scanf("%d",&cur);
  Node *Root = new Node(cur,NULL,NULL);
  Node **Arr=new Node*[n];
  Arr[0]=Root;
  int curIndex=0;
  Node *CurParent=Arr[curIndex++];

  for(int i=1;i<n;i++) {
    scanf("%d",&cur);
    Arr[i]=new Node(cur,NULL,NULL);
    if(CurParent->left==NULL) {
      CurParent->left=Arr[i];
    }
    else if(CurParent->right==NULL) {
      CurParent->right=Arr[i];
    }
    else {
      CurParent=Arr[curIndex++];
      CurParent->left=Arr[i];
    }
  }

  if(MMH.isMinMax(Root))
    printf("YES");
  else
    printf("NO");

  delete[] Arr;

  return 0;
}

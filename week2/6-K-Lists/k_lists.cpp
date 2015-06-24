#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
  int value;
  Node* next;
};


class KLists {

private:
  static inline bool Comp(const int &A, const int &B)  {
    return A<B;
    }

public:

  // Merge K sorted lists.
  Node merge(vector<Node> &lists)  {
    Node Result;
    vector<int> TooSlow;
    int len = lists.size();
    for(int i=0;i<len;i++)  {
      while(lists[i].next)  {
        TooSlow.push_back(lists[i].value);
        lists[i] = *(lists[i].next);
        }
      TooSlow.push_back(lists[i].value);
      }
    sort(TooSlow.begin(),TooSlow.end());
    }
};

int main()
{
  KLists L;
  //L.merge();

  return 0;
}

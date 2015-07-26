#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <list>

using namespace std;

class Node {
public:
  int value;
  Node* next;
  Node(int val = 0, Node* nxt = NULL):value(val),next(nxt){};
};

class KLists {
public:

static inline bool comp(const int& a, const int& b)
{
    return (a<=b);
}

  // Merge K sorted lists.
    Node merge(vector<Node>& lists) {
    vector<int> too_slow;
    for(int i=0; i<lists.size(); i++)
    {
       while(lists[i].next)
       {
           too_slow.push_back(lists[i].value);
           lists[i] = *(lists[i].next);
       }
       too_slow.push_back(lists[i].value);
    }
    sort(too_slow.begin(), too_slow.end() );

    int input_int;
    input_int = too_slow[0];
    Node result(input_int,NULL);
    Node *Last = &result;
    for(int i=1; i<too_slow.size(); i++) {
      Node *NewNode = new Node(too_slow[i],NULL);
      Last->next = NewNode;
      Last = NewNode;
    }
    return result;
    }
};

int main()
{
  cin.sync_with_stdio(false);
  cin.tie(0);

  vector<int> lists;
  int k;
  cin >> k;
  while(cin >> k) {
    if(k!=-1)
      lists.push_back(k);
  }
  sort(lists.begin(),lists.end());
  for(int i=0;i<lists.size();i++) {
    cout << lists[i] << " ";
  }

  return 0;
}

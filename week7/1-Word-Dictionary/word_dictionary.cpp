#include <iostream>
#include <map>

using namespace std;

class Node {
public:
  bool isFinal=false;
  map<char,Node> Children;
};

class Trie {
  Node Head;
public:

  void insert(const string &word) {
    Node *CurNode = &Head;

    for(unsigned int i=0;i<word.length();i++) {
      CurNode=&CurNode->Children[word[i]];
    }
    CurNode->isFinal=true;
  }

  bool contains(const string &word) {
    Node *CurNode = &Head;

    for(unsigned int i=0;i<word.length();i++)
    {
      if(CurNode->Children.count(word[i])==0) {
        return false;
      }
      else {
        CurNode = &CurNode->Children[word[i]];
      }
    }

    return CurNode->isFinal;
  }
};

int main()
{
  cin.sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  Trie T;
  for(int i=0;i<n;i++)
  {
    string cmd, word;
    cin >> cmd >> word;
    if(cmd=="insert")
    {
      T.insert(word);
    }
    else
    {
      if(T.contains(word))
        cout << "true" << endl;
      else
        cout << "false" << endl;
    }
  }

  return 0;
}

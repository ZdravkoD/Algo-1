#include <iostream>
#include <queue> // for BFS
#include <stack> // for "pouring stack" - first poured last printed
#include <set> // for remembering states
#include <vector> // for vector of "children" - next possible pours.
#include <cmath> // min()

using namespace std;

int C1,C2,C3;
int W1,W2,W3;
int G;

class Node {
public:
  pair<int, pair<int,int> > Triple;
  int first;
  int second;
  int third;
  Node* Parent;
  vector<Node> Children;
  pair<short,short> PourDecision;
  bool isValid;

  Node(int first,int second,int third,Node *Parent)
  {
    Triple.first=first;
    Triple.second.first=second;
    Triple.second.second=third;
    this->first=first;
    this->second=second;
    this->third=third;
    isValid=true;
    this->Parent=Parent;
  }

  /**
  * Setting the six type of pours.
  */
  void setChildren()
  {
    int min1 = min(first,C2-second);
    int min2 = min(first,C3-third);
    int min3 = min(second,C1-first);
    int min4 = min(second,C3-third);
    int min5 = min(third,C1-first);
    int min6 = min(third,C2-second);

    Children.push_back(Node(first-min1, second+min1, third,this));
    Children.push_back(Node(first-min2, second,      third+min2,this));
    Children.push_back(Node(first+min3, second-min3, third,this));
    Children.push_back(Node(first     , second-min4, third+min4,this));
    Children.push_back(Node(first+min5, second     , third-min5,this));
    Children.push_back(Node(first     , second+min6, third-min6,this));

    for(unsigned int i=0;i<Children.size();i++)
    {
      if(Children[i].first==first && Children[i].second==second && Children[i].third==third)
        Children[i].isValid=false;
    }
  }

  /**
  * Each decision means pouring from one glass to another i.e. 
  * decision 3 means pouring water from glass 2 to glass 3 with the specified rules.
  */
  void setPourDecisoin(const short &index)
  {
    switch(index)
    {
      case  0 : PourDecision.first=1; PourDecision.second=2;  break;
      case  1 : PourDecision.first=1; PourDecision.second=3;  break;
      case  2 : PourDecision.first=2; PourDecision.second=1;  break;
      case  3 : PourDecision.first=2; PourDecision.second=3;  break;
      case  4 : PourDecision.first=3; PourDecision.second=1;  break;
      case  5 : PourDecision.first=3; PourDecision.second=2;  break;
    }
  }

  bool checkNode()
  {
    return first==G || second==G || third==G;
  }
};

set<pair<int, pair<int,int> > > States;
queue<Node*> Nodes;
stack<pair<short,short> > PouringStack;

void printParents(Node &node)
{
  if(node.PourDecision.first==0 && node.PourDecision.second==0)
    return;

  PouringStack.push(node.PourDecision);
  printParents((*node.Parent));
}

bool bfs(Node &CurNode)
{
  Nodes.pop();
  for(unsigned int i=0;i<CurNode.Children.size();i++)
  {
    if(States.count(CurNode.Children[i].Triple)==0)
    {
      if(CurNode.Children[i].isValid==false)
        continue;

      CurNode.Children[i].setPourDecisoin(i);
      if(CurNode.Children[i].checkNode())
      {
        printParents(CurNode.Children[i]);
        return true;
      }

      CurNode.Children[i].setChildren();
      States.insert(CurNode.Children[i].Triple);
      Nodes.push(&CurNode.Children[i]);
    }
  }

  if(Nodes.size()>0 && bfs((*Nodes.front()))==true)
  {
    return true;
  }

  return false;
}

int main()
{
  cin >> C1 >> C2 >> C3;
  cin >> W1 >> W2 >> W3;
  cin >> G;

  Node Start(W1,W2,W3,NULL);
  Start.setChildren();
  States.insert(Start.Triple);
  Nodes.push(&Start);
  if(bfs(Start)==true)
  {
    cout << PouringStack.size() << endl;
    while(!PouringStack.empty())
    {
      cout << PouringStack.top().first << " " << PouringStack.top().second << endl;
      PouringStack.pop();
    }
  }
  else
  {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}

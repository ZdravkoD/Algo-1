#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n, startingPoint;

class Node{
public:
  bool Visited;
  bool isCoffeeStore;
  int BFSLevel;
  vector<Node*> Connections;

  Node() {
    Visited=false;
    isCoffeeStore=false;
    BFSLevel=0;
  }
};

void readGraph(vector<Node> &Graph)
{
  int temp;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++)
    {
      cin >> temp;
      if(temp) {
        Graph[i].Connections.push_back(&Graph[j]);
      }
    }
  }

  cin >> startingPoint;

  for(int i=0;i<n;i++)
  {
    cin >> Graph[i].isCoffeeStore;
  }
}

queue<Node*> BFSQueue;

int getClosestCoffeeStore(Node *node)
{
  node->Visited=true;
  if(node->isCoffeeStore)
    return 0;

  BFSQueue.push(node);
  while(!BFSQueue.empty()) {
    for(unsigned int i=0;i<node->Connections.size();i++) {
      if(node->Connections[i]->isCoffeeStore)
        return node->BFSLevel+1;

      if(!node->Connections[i]->Visited) {
        node->Connections[i]->BFSLevel=node->BFSLevel+1;
        node->Connections[i]->Visited=true;
        BFSQueue.push(node->Connections[i]);
      }
    }

    BFSQueue.pop();
    node=BFSQueue.front();
  }

  return -1;
}

int main()
{
  cin.sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  vector<Node> Graph(n);

  readGraph(Graph);

  cout << getClosestCoffeeStore(&Graph[startingPoint]) << endl;

  return 0;
}

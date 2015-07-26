#include <iostream>
#include <vector> // nodes
#include <queue> // answer order
#include <map>
#include <set>

using namespace std;

map<string,int> Mapper; // dependencies
queue<string> CompileOrder;
int n; // number of nodes
string Target; // project we want to build

/**
* Each node in the graph
*/
struct Node {
  string Name;
  vector<Node*> Dependencies;
  bool Compiled=false;
};
set<Node*> Path; // current DFS path

bool dfs(Node *CurNode)
{
  if(Path.find(CurNode)!=Path.end()) // if already in path - we have cycle
    return false;

  Path.insert(CurNode); // add to path

  if(CurNode->Dependencies.size()==0) {
    CompileOrder.push(CurNode->Name);
    CurNode->Compiled=true;
    Path.erase(CurNode); // remove from path
    return true;
  }

  for(unsigned int i=0;i<CurNode->Dependencies.size();i++) {
    if(CurNode->Dependencies[i]->Compiled)
      continue;

    if(!dfs(CurNode->Dependencies[i]))
      return false;
  }

  CompileOrder.push(CurNode->Name);
  CurNode->Compiled=true;
  Path.erase(CurNode); // remove from path
  return true; // remove warning
}

bool read(vector<Node> &Graph)
{
  for(int i=0;i<n;i++) {
    cin >> Graph[i].Name;
    Mapper.insert(make_pair(Graph[i].Name,i));
  }

  cin >> Target;

  int m;
  string cur;
  for(int i=0;i<n;i++) {
    cin >> m;
    for(int j=0;j<m;j++) {
      cin >> cur;
      if(cur==Graph[i].Name)
        return false;

      Graph[i].Dependencies.push_back(&Graph[Mapper[cur]]); // reference to node with name 'cur'
    }
  }

  return true;
}

int main()
{
  cin.sync_with_stdio(false);
  cin >> n;
  vector<Node> Graph(n);
  if(!read(Graph)) {
    cout << "BUILD ERROR" << endl;
    return 0;
  }

  int indexTarget = Mapper[Target];
  for(unsigned int i=0; i<Graph[indexTarget].Dependencies.size(); i++) {
    if(Graph[indexTarget].Dependencies[i]->Compiled)
      continue;

    if(!dfs(Graph[indexTarget].Dependencies[i])) {
      cout << "BUILD ERROR" << endl;
      return 0;
    }
  }


  while(!CompileOrder.empty()) {
    cout << CompileOrder.front() << " ";
    CompileOrder.pop();
  }
  cout << Target << endl;

  return 0;
}

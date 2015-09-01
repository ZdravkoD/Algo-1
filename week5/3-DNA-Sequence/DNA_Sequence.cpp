#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Node { // Nucleotide
public:
string Type;
string First;
string Last;
bool Visited;
bool FirstCon, LastCon;

  Node(const string &Type)
  {
    Visited=false;
    FirstCon=false; // true if connected on left
    LastCon=false; // true if connected on right

    this->Type=Type;
    First = Type.substr(0,3);
    Last = Type.substr(Type.size()-3,3);
  }
};

int N;
map<string,vector<Node*>> NucConnections;
queue<string> Path;
Node *StartNode;

bool read()
{
  cin.sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for(int i=0;i<N;i++)  {
    string cur;
    cin >> cur;
    Node *CurNode = new Node(cur);
    NucConnections[CurNode->First].push_back(CurNode);
    NucConnections[CurNode->Last].push_back(CurNode);
  }


  int SingleConnectionCount=0;
  for(map<string,vector<Node*> >::iterator it = NucConnections.begin();it!=NucConnections.end();++it) {
    if(it->second.size()==1) {
      SingleConnectionCount++;
      StartNode=it->second[0];
    }
  }

  return SingleConnectionCount<=2; // if there are more than two nucleotides with only one connection
}

bool checkConnection(const string &End, const int &NucCount);

bool solve(Node *CurNode,int NucCount)
{
  string CurType = CurNode->Type;
  if(CurNode->Visited)
    return false;

  if(++NucCount==N) {
    Path.push(CurNode->Type);
    return true;
  }

  CurNode->Visited=true;

  if(!CurNode->FirstCon)  { // if not connected on left
    if(checkConnection(CurNode->First,NucCount))  {
      Path.push(CurNode->Type.substr(3,CurNode->Type.size()-3)); // add remaining nucleotide

      return true;
    }
  }

  if(!CurNode->LastCon)  { // if not connected on right
    if(checkConnection(CurNode->Last,NucCount)) {
      Path.push(CurNode->Type.substr(0,CurNode->Type.size()-3)); // add remaining nucleotide

      return true;
    }
  }

  CurNode->FirstCon=false;
  CurNode->LastCon=false;
  CurNode->Visited=false;

  return false;
}

bool checkConnection(const string &End, const int &NucCount)
{
  for(unsigned int i=0;i<NucConnections[End].size();i++)  { // check all nucleotides with this end
    if(NucConnections[End][i]->First == End)
      NucConnections[End][i]->FirstCon=true;
    else
      NucConnections[End][i]->LastCon=true;


    if(solve(NucConnections[End][i], NucCount))  {
      return true;
    }
  }

  return false;
}

void clear()
{
  for(map<string,vector<Node*>>::iterator it = NucConnections.begin(); it!=NucConnections.end();++it) {
    for(unsigned int i=0;i<it->second.size();i++)  {
      delete it->second[i];
    }
  }
}

int main()
{
  if(!read() || !solve(StartNode,0)) {
    cout << "IMPOSSIBLE" << endl;
  }
  else {
    cout << endl;

    while(Path.empty()==false)  {
      cout << Path.front() << " ";
      Path.pop();
    }
  }

  return 0;
}

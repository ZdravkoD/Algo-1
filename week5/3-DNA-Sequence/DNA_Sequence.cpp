#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    this->Type=Type;
    FirstCon=false;
    LastCon=false;

    int len = Type.length();
    First = Type.substr(0,3);
    Last = Type.substr(len-3,3);
  }
};

int N;
map<string,vector<Node*>> NucConnections;
vector<string> Path;
Node *StartNode;

bool read()
{
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

bool solve(Node *CurNode,int NucCount)
{
  string CurType = CurNode->Type;
  if(CurNode->Visited)
    return false;

  if(++NucCount==N) {
    Path.push_back(CurNode->Type);
    return true;
  }

  CurNode->Visited=true;

  if(!CurNode->FirstCon)  {
    for(unsigned int i=0;i<NucConnections[CurNode->First].size();i++)  {
      string f = NucConnections[CurNode->First][i]->First;
      string l =NucConnections[CurNode->First][i]->Last;
      if(NucConnections[CurNode->First][i]->First == CurNode->First)
        NucConnections[CurNode->First][i]->FirstCon=true;
      else
        NucConnections[CurNode->First][i]->LastCon=true;


      if(solve(NucConnections[CurNode->First][i], NucCount))  {
        int len = CurNode->Type.size();
        Path.push_back(CurNode->Type.substr(3,len));

        return true;
      }
    }
  }

  if(!CurNode->LastCon)  {
    for(unsigned int i=0;i<NucConnections[CurNode->Last].size();i++)  {
      string f = NucConnections[CurNode->Last][i]->First;
      string l =NucConnections[CurNode->Last][i]->Last;
      if(NucConnections[CurNode->Last][i]->First == CurNode->Last)
        NucConnections[CurNode->Last][i]->FirstCon=true;
      else
        NucConnections[CurNode->Last][i]->LastCon=true;

      if(solve(NucConnections[CurNode->Last][i], NucCount))  {
        int len = CurNode->Type.size();
        Path.push_back(CurNode->Type.substr(0,len-3));

        return true;
      }
    }
  }

  CurNode->FirstCon=false;
  CurNode->LastCon=false;

  CurNode->Visited=false;

  return false;
}

int main()
{
  cin.sync_with_stdio(false);
  cin.tie(0);

  if(!read()) {
    cout << "IMPOSSIBLE" << endl;
  }
  else {
    if(!solve(StartNode,0)) {
      cout << "IMPOSSIBLE" << endl;
    }
    else {
      cout << endl;
      for(unsigned int i=0;i<Path.size();i++)  {
        cout << Path[i];
      }
    }
  }

  return 0;
}

/**
* For this task we will use Dijkstra's algorithm.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

int N,M;
int sX,sY,eX,eY;

/** Each cell in the map **/
struct Node{
char Type;
int x,y;
int MinDistanceFromStartPoint;
vector<Node*> Connections;
bool Visited=false;

  Node()  {
    MinDistanceFromStartPoint=INT_MAX;
  }
};

/** For Priority queue, compares two nodes based on their distance from the start point **/
class Comp {
public:
  Comp(){}
  bool operator() (const Node *lhs, const Node *rhs) {
    if(lhs->MinDistanceFromStartPoint == rhs->MinDistanceFromStartPoint)  {
      return !(lhs->Type>='a' && lhs->Type<='b'); // if it is harbor, return TRUE
    }
    else {
      return lhs->MinDistanceFromStartPoint > rhs->MinDistanceFromStartPoint;
    }
  }
};

priority_queue<Node*, vector<Node*>, Comp> ClosestNodes;


void read(vector< vector<Node> > &Map)
{
  cin >> sX >> sY >> eX >> eY;

  map<char,Node*> Harbors;


  for(int i=0;i<N;i++)  {
    for(int j=0;j<M;j++)  {
      // read type of cell - water, ground or harbor
      cin >> Map[i][j].Type;
      Map[i][j].x=i;
      Map[i][j].y=j;

      // add to Harbors
      if(Map[i][j].Type>='a' && Map[i][j].Type<='z')  {
        Harbors[Map[i][j].Type] = &Map[i][j];
      }
    }
  }

  // read harbor connections
  int harborCount;
  cin >> harborCount;
  for(int i=0;i<harborCount;i++) {
    char h1,h2;

    cin >> h1 >> h2;

    Node *Harbor1 = Harbors[h1];
    Node *Harbor2 = Harbors[h2];

    Harbor1->Connections.push_back(Harbor2);
    Harbor2->Connections.push_back(Harbor1);
  }
}

void addToPQNeighbors(Node *CurNode,vector< vector<Node> > &Map)
{
  int i = CurNode->x;
  int j = CurNode->y;

  if(i>0   && Map[i-1][j].Type!='.' && Map[i-1][j].Visited==false)  { // up
    Map[i-1][j].MinDistanceFromStartPoint = Map[i][j].MinDistanceFromStartPoint;
    Map[i-1][j].Visited=true;
    ClosestNodes.push(&Map[i-1][j]);
    }
  if(i<N-1 && Map[i+1][j].Type!='.' && Map[i+1][j].Visited==false)  { // down
    Map[i+1][j].MinDistanceFromStartPoint = Map[i][j].MinDistanceFromStartPoint;
    Map[i+1][j].Visited=true;
    ClosestNodes.push(&Map[i+1][j]);
    }
  if(j>0   && Map[i][j-1].Type!='.' && Map[i][j-1].Visited==false)  { // left
    Map[i][j-1].MinDistanceFromStartPoint = Map[i][j].MinDistanceFromStartPoint;
    Map[i][j-1].Visited=true;
    ClosestNodes.push(&Map[i][j-1]);
    }
  if(j<M-1 && Map[i][j+1].Type!='.' && Map[i][j+1].Visited==false)  { // right
    Map[i][j+1].MinDistanceFromStartPoint = Map[i][j].MinDistanceFromStartPoint;
    Map[i][j+1].Visited=true;
    ClosestNodes.push(&Map[i][j+1]);
    }
}

void addToPQHarbors(Node *CurNode)
{
  for(unsigned int i=0;i<CurNode->Connections.size();i++)  {
    if(CurNode->Connections[i]->Visited==false)  {
        CurNode->Connections[i]->MinDistanceFromStartPoint = min(
                                                                 CurNode->MinDistanceFromStartPoint,
                                                                 CurNode->Connections[i]->MinDistanceFromStartPoint);
        ClosestNodes.push(CurNode->Connections[i]);
    }
  }
}

bool isHarbor(Node *CurNode)
{
  return CurNode->Type>='a' && CurNode->Type<='z';
}

int solve(vector< vector<Node> > &Map)
{
  Map[sX][sY].MinDistanceFromStartPoint=0;

  ClosestNodes.push(&Map[sX][sY]);
  while(ClosestNodes.empty()==false)  {
    Node *CurNode = ClosestNodes.top();
    ClosestNodes.pop();
    CurNode->Visited=true;

    if(isHarbor(CurNode))  {
      CurNode->MinDistanceFromStartPoint++;
    }


    if(CurNode==&Map[eX][eY]) {
      return CurNode->MinDistanceFromStartPoint + !isHarbor(CurNode);
    }

    addToPQHarbors(CurNode);
    addToPQNeighbors(CurNode,Map);
  }

  return -1;
}

int main()
{
  cin >> N >> M;
  vector< vector<Node> > Map(N, vector<Node>(M));

  read(Map);

  int answ = solve(Map);

  if(answ==-1 || Map[sX][sY].Type=='.' || Map[eX][eY].Type=='.')  {
    cout << "NNnoooo" << endl;
  }
  else {
    cout << answ << endl;
  }

  return 0;
}

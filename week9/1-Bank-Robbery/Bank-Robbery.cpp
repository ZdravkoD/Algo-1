#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
vector<Node*> Connections;

/** The following distances are used not only to measure distance,
* but for flag if they are visited by Bank\Police, if Distance is 0, it is not visited
**/
int DistanceFromBank;
int DistanceFromPolice;

  Node()  {
    DistanceFromBank=0;
    DistanceFromPolice=0;
  }
};

Node *B, *P, *H; // Bank, Police, Helicopter
map<int,Node*> Graph;

/** Reads the input **/
void read()
{
  int N,M;
  scanf("%d%d",&N,&M);

  for(int i=0;i<M;i++) {
    int first, second;
    scanf("%d%d",&first,&second);

    if(Graph[first]==NULL) {
      Graph[first] = new Node();
    }
    if(Graph[second]==NULL)  {
      Graph[second] = new Node();
    }

    Node *First = Graph[first];
    Node *Second = Graph[second];

    First->Connections.push_back(Second);
    Second->Connections.push_back(First);
  }

  int b,p,h;
  scanf("%d%d%d",&b,&p,&h);
  B = Graph[b];
  P = Graph[p];
  H = Graph[h];
}

/** Finds the shortest path between StartNode and EndNode using BFS.
* Parameter "robber" is used to check different variable for distance to the Helicopter,
*   true - to add distance from Bank to Helicopter.
*   false - to add distance from Police to Helicopter.
*/
int shortestPath(Node *StartNode, Node *EndNode,bool robber)
{
  queue<Node*> BFS;
  BFS.push(StartNode);

  while(BFS.empty()==false) {
    Node *CurNode = BFS.front();
    BFS.pop();

    for(unsigned int i=0;i<CurNode->Connections.size();i++)  {
      if(robber)  {
        if(CurNode->Connections[i]==EndNode)  {
            return CurNode->DistanceFromBank+1;
        }

        if(CurNode->Connections[i]->DistanceFromBank==0)  {
          CurNode->Connections[i]->DistanceFromBank=CurNode->DistanceFromBank+1;
          BFS.push(CurNode->Connections[i]);
        }
      }
      else {
        if(CurNode->Connections[i]==EndNode)  {
            return CurNode->DistanceFromPolice+1;
        }

        if(CurNode->Connections[i]->DistanceFromPolice==0)  {
          CurNode->Connections[i]->DistanceFromPolice=CurNode->DistanceFromPolice+1;
          BFS.push(CurNode->Connections[i]);
        }
      }
    }
  }

  return -1;
}

/** Returns the difference between
* shortest path from police to helicopter and
* shortest path from banker to helicopter
**/
int solve()
{
  int Police = shortestPath(P,H,false);
  int Robber = shortestPath(B,H,true);
  return Police-Robber-1;
}

/** Prints the answer based on parameter "answ" **/
void printSolution(const int &answ)
{
  if(answ<0)  {
    printf("IMPOSSIBLE!\n");
  }
  else {
    printf("%d\n",answ);
  }
}

/** Clears the allocated memory from read() function **/
void clear()
{
  for(map<int,Node*>::iterator it=Graph.begin();it!=Graph.end();++it) {
    delete it->second;
  }
}

int main()
{
  read();

  int answ = solve();

  printSolution(answ);

  clear();

  return 0;
}

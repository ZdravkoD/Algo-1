#include <iostream>
#include <climits>
#include <queue>

using namespace std;

class ClosestCoffeeStore {
public:
  // Finds the closest coffee store to a point.
  int closestCoffeeStore(bool** graph, bool* isCoffeStore, int size, int startingPoint) {
    if(isCoffeStore[startingPoint]) // some nonsense
      return startingPoint;

    bool* Visited = new bool[size];
    for(int i=0;i<size;i++)
      Visited[i]=false;

    queue<int> q;
    q.push(startingPoint);
    int cur = startingPoint;

    while(!q.empty()) {
      Visited[cur]=true;
      for(int i=0;i<size;i++) {
        if(graph[cur][i]) {
          if(isCoffeStore[i])
            return i;
          else if(Visited[i]==false)
            q.push(i);
        }
      }
      q.pop();
      cur = q.front();
    }

    return -1;
  }
};

int main()
{
  int size=6;
  bool** Graph = new bool*[size];
  for(int i=0;i<size;i++) {
    Graph[i] = new bool[size];
  }

  Graph[0][0]=0;Graph[0][1]=1;Graph[0][2]=0;Graph[0][3]=1;Graph[0][4]=0;Graph[0][5]=0;
  Graph[1][0]=1;Graph[1][1]=0;Graph[1][2]=1;Graph[1][3]=0;Graph[1][4]=0;Graph[1][5]=0;
  Graph[2][0]=0;Graph[2][1]=1;Graph[2][2]=0;Graph[2][3]=0;Graph[2][4]=1;Graph[2][5]=0;
  Graph[3][0]=1;Graph[3][1]=0;Graph[3][2]=0;Graph[3][3]=0;Graph[3][4]=0;Graph[3][5]=0;
  Graph[4][0]=0;Graph[4][1]=0;Graph[4][2]=1;Graph[4][3]=0;Graph[4][4]=0;Graph[4][5]=1;
  Graph[5][0]=0;Graph[5][1]=0;Graph[5][2]=0;Graph[5][3]=0;Graph[5][4]=1;Graph[5][5]=0;

  bool* Arr = new bool[size];
  Arr[0]=0;
  Arr[1]=0;
  Arr[2]=1;
  Arr[3]=0;
  Arr[4]=0;
  Arr[5]=1;

  ClosestCoffeeStore CCS;
  cout << CCS.closestCoffeeStore(Graph,Arr,size,0)  << endl;
  return 0;
}

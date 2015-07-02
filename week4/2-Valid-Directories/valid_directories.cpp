#include <iostream>

using namespace std;

class ValidDirectories {
  bool* Visited;
public:
  bool Recur(int** graph, int size, bool* Visited,int Index) {
    Visited[Index]=true;

    for(int i=0;i<size;i++) {
      if(graph[Index][i]==1 && Visited[i]==true) {
        return false;
      }
      else if(graph[Index][i]==1) {
        if(Recur(graph,size,Visited,i)==false)
          return false;
      }
    }

    Visited[Index]=false;
    return true;
  }

  bool isValid(int** graph, int size) {
    Visited = new bool[size];
    for(int i=0;i<size;i++)
      Visited[i]=false;

    return Recur(graph,size,Visited,0);
    }
};

int main()
{

  return 0;
}

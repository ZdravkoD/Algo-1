#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

set<int> ObhodeniDotuk;
map<int, vector<int> > Graph;

int n;

void readStudents()
{
  vector<int> numbers(n);
  for(int i=0;i<n;i++)
  {
    cin >> numbers[i];
  }

  for(int cur : numbers)
  {
    int M, temp;
    cin >> M;
    Graph[cur]=vector<int>();
    for(int i=0;i<M;i++)
    {
      cin >> temp;
      Graph[cur].push_back(temp);
    }
  }
}

void dfs(vector<int> &Vec)
{
  for(unsigned int i=0;i<Vec.size();i++)
  {
    if(!ObhodeniDotuk.count(Vec[i]))
    {
      ObhodeniDotuk.insert(Vec[i]);
      dfs(Graph[Vec[i]]);
    }
  }
}

int main()
{
  cin.sync_with_stdio(false);
  cin.tie();
  cin >> n;

  readStudents();

  int cnt=0;
  for(map<int,vector<int> >::iterator it=Graph.begin();it!=Graph.end();++it)
  {
    if(!ObhodeniDotuk.count(it->first))
    {
      cnt++;
      ObhodeniDotuk.insert(it->first);
      dfs(it->second);
    }
  }

  cout << cnt << endl;

  return 0;
}

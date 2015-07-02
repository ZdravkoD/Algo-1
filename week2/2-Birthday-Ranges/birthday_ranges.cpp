#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int Count[366];

int n,m;

void solve()
{
  scanf("%d%d",&n,&m);
  vector<int> Bd(n);

  for(int i=0;i<n;i++)
    scanf("%d",&Bd[i]);
  sort(Bd.begin(),Bd.end());

  long long cnt=0;
  int index=0;
  for(int i=0;i<366;i++) {
    Count[i]=cnt;

    while(index<n && Bd[index]==i) {
      Count[i]++;
      index++;
      cnt++;
    }
  }

  int range1,range2;
  for(int i=0;i<m;i++) {
    scanf("%d%d",&range1,&range2);
    printf("%d\n", Count[range2] - (range1>0 ? Count[range1-1] : 0));
  }
}

int main()
{
  solve();

  return 0;
}

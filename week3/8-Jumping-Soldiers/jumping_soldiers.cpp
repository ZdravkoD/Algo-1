#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>

using namespace std;

int n; // Soldiers per row
int PowTwoN=1; // smallest power of two greater than or equal to n
int k; // Number of rows
int *Tree=NULL;

int getRowJumps(vector<int> &Soldiers);
int set(int index);

int main()
{
  scanf("%d%d",&n,&k);
  int Max=0; // the maximum number of jumps for all rows
  int MaxIndex=1;
  while(PowTwoN<n)
    PowTwoN*=2;

  Tree = new int[2*PowTwoN];

  for(int i=1;i<=k;i++) { // for each row
    vector<int> Soldiers(n); // make new array of soldiers
    for(int i=0;i<n;i++)
      scanf("%d",&Soldiers[i]);

    int curJumps = getRowJumps(Soldiers);
    if(Max<curJumps) {
      Max = curJumps;
      MaxIndex=i;
    }
  }

  printf("%d\n",MaxIndex);

  delete[] Tree;

  return 0;
}

int getRowJumps(vector<int> &Soldiers)
{
  memset(Tree,0,2*PowTwoN*sizeof(int)); // start from 0

  int answ=0;
  for(int i=0;i<n;i++) {
    answ += set(Soldiers[i]);
  }

  return answ;
}

int set(int index) {
  int jumps=0;
  index += PowTwoN-1;

  while(index>0) {
    Tree[index]+=1;
    if(index%2==0)
      jumps+=Tree[index+1];

    index/=2;
  }

  return jumps;
}

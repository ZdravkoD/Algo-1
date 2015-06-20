#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define LEN 20

class CountSort {
  void FindMinMax(int &Min,int &Max,int *Arr)  {
    Min=INT_MAX;
    Max=INT_MIN;

    for(int i=0;i<LEN;i++)  {
      if(Arr[i]<Min)
          Min=Arr[i];
      if(Arr[i]>Max)
          Max=Arr[i];
      }
    }

public:

  int* Sort(int *Arr) {
    int Min,Max;
    FindMinMax(Min,Max,Arr);

    int Size=Max-Min+1;
    int *Counting=new int[Size];

    for(int i=0;i<Size;i++)
      Counting[i]=0;

    int Add = (Min<0 ? abs(Min) : 0);

    for(int i=0;i<LEN;i++)
      Counting[Arr[i]+Add]++;

    int Index=0; // Arr Index
    for(int i=0;i<Size;i++) {
      while(Counting[i]-->0)  {
        Arr[Index++]=i-Add;
        }
      }

  return Arr;
  }
};


int main()
{
    int Arr[LEN]={1,15,-645,34,65,876,-3,-7,9,10,23,55,-567,7,97,-97,98,75,45,32};
    CountSort S;
    S.Sort(Arr);

    for(int i=0;i<LEN;i++)
        cout << Arr[i] << " ";

    return 0;
}

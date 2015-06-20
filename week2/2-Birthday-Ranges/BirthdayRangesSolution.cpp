#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define BIRTHDAYS 12
#define RANGES 6
int Count_B[366];

class CountSort {
  void FindMinMax(int &Min,int &Max,int *Arr)  {
    Min=INT_MAX;
    Max=INT_MIN;

    for(int i=0;i<BIRTHDAYS;i++)  {
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

    for(int i=0;i<BIRTHDAYS;i++)
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

class BirthdayRanges  {
public:
  int* birthdays_count(int *Birthdays,pair<int,int>* Ranges) {
    int *Result = new int[RANGES];

    CountSort S;
    S.Sort(Birthdays);

    int cnt=0;
    int B_Index=0;
    for(int i=0;i<366;i++)  {
      Count_B[i]=cnt;
      if(B_Index<BIRTHDAYS && i==Birthdays[B_Index]) {
        while(B_Index<BIRTHDAYS && i==Birthdays[B_Index])  {
          B_Index++;
          cnt++;
          }
        Count_B[i]=cnt;
        }
      }

    for(int i=0;i<RANGES;i++) {
      int first = Count_B[Ranges[i].first];
      int second = Count_B[Ranges[i].second];
      if(Ranges[i].first==0)
        first -= (first>0);
      else
        first = Count_B[Ranges[i].first-1];

      Result[i] = second - first;
      }

    return Result;
    }
};

int main()
{
  int Birthdays[BIRTHDAYS] = {0,10,31,53,23,66,78,66,5,4,43,23}; // length = 12

  pair<int, int> Ranges[RANGES];
  Ranges[0]=make_pair( 0,  2);
  Ranges[1]=make_pair( 3, 20);
  Ranges[2]=make_pair( 2, 44);
  Ranges[3]=make_pair(40, 80);
  Ranges[4]=make_pair( 0,365);
  Ranges[5]=make_pair( 0,  0);

  BirthdayRanges BR;
  int *Result = BR.birthdays_count(Birthdays,Ranges);

  for(int i=0;i<RANGES;i++)
    cout << Result[i] << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//#define BIRTHDAYS 12
//#define RANGES 6
int BIRTHDAYS;
int RANGES;
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

      if(i==3) {
      for(int d=Ranges[i].first;d<=Ranges[i].second;d++)
        cout << Count_B[d] << " ";
      cout << endl;
      }
      Result[i] = second - first;
      }

    return Result;
    }
};

int main()
{
  cin >> BIRTHDAYS >> RANGES;
  int *Birthdays = new int[BIRTHDAYS];
  for(int i=0;i<BIRTHDAYS;i++)
    cin >> Birthdays[i];

  pair<int, int> *Ranges = new pair<int, int>[RANGES];
  for(int i=0;i<RANGES;i++) {
    int a,b;
    cin >> a >> b;
    Ranges[i] = make_pair(a,b);
  }

  BirthdayRanges BR;
  int *Result = BR.birthdays_count(Birthdays,Ranges);

  for(int i=0;i<RANGES;i++)
    cout << Result[i] << endl;

  return 0;
}

#include <iostream>

using namespace std;

#define LEN 20

class SelectionSort {

public:
  int* Sort(int *Arr)  {
    for(int i=0;i<LEN;i++)  {
      int Min=Arr[i];
      int Index=i;
      for(int j=i+1;j<LEN;j++)  {
        if(Arr[j]<Min)  {
          Min=Arr[j];
          Index=j;
          }
        }
      int temp=Arr[i];
      Arr[i]=Arr[Index];
      Arr[Index]=temp;
      }
    return Arr;
    }
};

int main()
{
    int Arr[LEN]={1,15,-645,34,65,876,-3,-7,9,10,23,55,-567,7,97,-97,98,75,45,32};
    SelectionSort S;
    S.Sort(Arr);

    for(int i=0;i<LEN;i++)
        cout << Arr[i] << " ";

    return 0;
}



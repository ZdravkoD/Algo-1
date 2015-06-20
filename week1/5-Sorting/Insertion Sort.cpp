#include <iostream>

using namespace std;

#define LEN 20

class InsertionSort {

public:
  int* Sort(int *Arr) {
    for(int i=0;i<LEN-1;i++)  {
      if(Arr[i+1]<Arr[i]) {
        int temp=Arr[i+1];
        Arr[i+1]=Arr[i];
        Arr[i]=temp;
        i-= (i>0 ? 2 : 1);
        }
      }
    return Arr;
    }
};

int main()
{
    int Arr[LEN]={1,15,-645,34,65,876,-3,-7,9,10,23,55,-567,7,97,-97,98,75,45,32};
    InsertionSort S;
    S.Sort(Arr);

    for(int i=0;i<LEN;i++)
        cout << Arr[i] << " ";

    return 0;
}

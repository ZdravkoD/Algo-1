#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class HeapSort {

private:
  // Creates a heap
  void heapify(int* Arr, const int Size, int cur)  {
    if(cur*2+1>=Size)
      return;

    if(cur*2+2 < Size)  {
      if(Arr[cur] > Arr[cur*2+1] && Arr[cur*2+1]<Arr[cur*2+2])  {
        swap(Arr[cur],Arr[cur*2+1]);

        heapify(Arr,Size,cur*2+1);
        }
      else if(Arr[cur] > Arr[cur*2+2] && Arr[cur*2+2]<Arr[cur*2+1]) {
        swap(Arr[cur],Arr[cur*2+2]);

        heapify(Arr,Size,cur*2+2);
        }
      }
    else  {
      if(Arr[cur] > Arr[cur*2+1]) {
        swap(Arr[cur],Arr[cur*2+1]);

        heapify(Arr,Size,cur*2+1);
        }
      }
  }

public:
  // Sorts a sequence of integers.
  void Sort(int* sequence, int Size) {
    int *Temp = new int[Size];
    for(int i=0;i<Size;i++)
      Temp[i] = sequence[i];

    int cur = Size/2 - 1;

    for(;cur>=0;cur--)  {
      heapify(Temp,Size,cur);
      }

    for(int i=0;i<Size;i++)  {
      sequence[i]=Temp[0];
      Temp[0] = Temp[Size-i-1];
      heapify(Temp,Size-i-1,0);
      }

    delete[] Temp;
  }
};

int main()
{
    HeapSort H;
    int Size=7;
    int Arr[7] = {20,16,12,3,8,5,10};
    H.Sort(Arr,Size);

    for(int i=0;i<Size;i++) {
      cout << Arr[i] << endl;
      }

    return 0;
}

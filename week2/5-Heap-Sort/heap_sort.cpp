#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int n;

class HeapSort {

private:
  // Creates a heap
  void heapify(int* Arr, const int n, int cur)  {
    if(cur*2+1>=n)
      return;

    int leftChild=cur*2+1;
    int rightChild=cur*2+2;

    if(rightChild < n)  {
      if(Arr[cur]>Arr[leftChild] && Arr[leftChild]<=Arr[rightChild])  {
        swap(Arr[cur],Arr[cur*2+1]);

        heapify(Arr,n,leftChild);
        }
      else if(Arr[cur]>Arr[rightChild] && Arr[rightChild]<=Arr[leftChild]) {
        swap(Arr[cur],Arr[rightChild]);

        heapify(Arr,n,rightChild);
        }
      }
    else if(leftChild < n) {
      if(Arr[cur] > Arr[leftChild]) {
        swap(Arr[cur],Arr[leftChild]);

        heapify(Arr,n,leftChild);
        }
      }
  }

public:
  // Sorts a sequence of integers.
  void sort(int* sequence, int n) {
    int *Temp = new int[n];
    for(int i=0;i<n;i++)
      Temp[i] = sequence[i];

    int cur = n/2 - 1;

    for(;cur>=0;cur--)  {
      heapify(Temp,n,cur);
      }

    for(int i=0;i<n;i++)  {
      sequence[i]=Temp[0];
      Temp[0] = Temp[n-i-1];
      heapify(Temp,n-i-1,0);
      }

    delete[] Temp;
  }
};

int main()
{
  cin >> n;
  HeapSort H;
  int *Arr = new int[n];
  for(int i=0;i<n;i++)
    cin >> Arr[i];

  H.sort(Arr,n);

  for(int i=0;i<n;i++)
    cout << Arr[i] << " ";

  return 0;
}

#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n,k;

class KMin {
  void BubbleDown(vector<int> &_vector,const int &index)
  {
    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    if(leftChildIndex >= k)
        return; //index is a leaf

    int minIndex=index;

    if(_vector[index]<_vector[leftChildIndex])
      minIndex=leftChildIndex;

    if((rightChildIndex<k) && (_vector[minIndex]<_vector[rightChildIndex]))
      minIndex=rightChildIndex;

    if(minIndex!=index)
    {
      //need to swap
      int temp=_vector[index];
      _vector[index]=_vector[minIndex];
      _vector[minIndex]=temp;
      BubbleDown(_vector,minIndex);
    }
  }

public:
  // Finds the k-th minimum element in an unsorted collection.
  int kthMinimum(vector<int> &numbers)
  {
    make_heap(numbers.begin(),numbers.end());
    for(int i=k;i<n;i++) {
      int temp;
      scanf("%d",&temp);
      if(temp < numbers[0]) {
        numbers[0] = temp;

        BubbleDown(numbers,0);
        }
      }

    return numbers[0];
    }
};

int main()
{
  KMin K;
  scanf("%d%d",&n,&k);
  vector<int> Arr(k);

  for(int i=0;i<k;i++)
    scanf("%d",&Arr[i]);

  printf("%d",K.kthMinimum(Arr));

  return 0;
}

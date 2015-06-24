#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class KMin {
public:

  // Finds the k-th minimum element in an unsorted collection.
  int kthMinimum(vector<int> numbers, int k) {
    int *arr = new int[k];
    for(int i=0;i<k;i++)
      arr[i] = numbers[i];

    make_heap(arr,arr+k);
    for(int i=k;i<numbers.size();i++) {
      if(numbers[i] < arr[0]) {
        arr[0] = numbers[i];
        make_heap(arr,arr+k);
        }
      }
    int res = arr[0];
    delete[] arr;
    return res;
    }
};

int main()
{
  KMin K;
  vector<int> Arr = {5,2,3,6,1,4};
  cout << K.kthMinimum(Arr,3) << endl;


  return 0;
}

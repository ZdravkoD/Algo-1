#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Median {
  bool empty=true;
  int median=0;
  vector<int> Max;
  vector<int> Min;

  static bool Comp(const int &a, const int &b) {
    return a > b;
  }
public:

  //inserts the number and returns the median
  int insert(int number){
    if(empty) {
      median=number;
      empty=false;
    }
    else {
      if(number>median) {
        Min.push_back(number);
        push_heap(Min.begin(),Min.end(),Comp);
        if(Min.size() - Max.size() > 0) {
          Max.push_back(median);
          push_heap(Max.begin(),Max.end());
          median = Min[0];
          pop_heap(Min.begin(),Min.end(),Comp);
          Min.erase(Min.end()-1);
        }
      }
      else {
        Max.push_back(number);
        push_heap(Max.begin(),Max.end());
        if(Max.size() - Min.size() > 1) {
          Min.push_back(median);
          push_heap(Min.begin(),Min.end(),Comp);
          median = Max[0];
          pop_heap(Max.begin(),Max.end());
          Max.erase(Max.end()-1);
        }
      }
    }
    return median;
  }
};

int main()
{
  Median M;
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int tmp;
    cin >> tmp;
    cout << M.insert(tmp) << endl;
  }

  return 0;
}

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
  cout << M.insert(5) << endl;
  cout << M.insert(6) << endl;
  cout << M.insert(7) << endl;
  cout << M.insert(4) << endl;
  cout << M.insert(3) << endl;
  cout << M.insert(10) << endl;
  cout << M.insert(20) << endl;
  cout << M.insert(30) << endl;
  cout << M.insert(40) << endl;
  cout << M.insert(50) << endl;

  return 0;
}

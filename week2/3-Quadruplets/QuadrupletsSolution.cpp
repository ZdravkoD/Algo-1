#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Quadruplets   {
public:

  // Returns the number of quadruplets that sum to zero.
  int zeroQuadrupletsCount(vector<int> a, vector<int> b, vector<int> c, vector<int> d)  {
    vector<int> Sum;

    for(int i=0;i<a.size();i++)
      for(int j=0;j<b.size();j++)
        Sum.push_back(a[i] + b[j]);

    sort(Sum.begin(),Sum.end());

    int Count=0;
    for(int i=0;i<c.size();i++) {
      for(int j=0;j<d.size();j++) {
        int CurSum = -(c[i]+d[j]);
        Count += upper_bound(Sum.begin(), Sum.end(), CurSum) - lower_bound(Sum.begin(), Sum.end(), CurSum);
        }
      }

    return Count;
    }
};

int main()
{
    vector<int> a = { 5, 3,4};
    vector<int> b = {-2,-1,6};
    vector<int> c = {-1,-2,4};
    vector<int> d = {-1,-2,7};

    Quadruplets Q;
    cout << Q.zeroQuadrupletsCount(a,b,c,d) << endl;
    return 0;
}

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
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n),d(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<n;i++) cin >> d[i];

    Quadruplets Q;
    cout << Q.zeroQuadrupletsCount(a,b,c,d) << endl;
    return 0;
}

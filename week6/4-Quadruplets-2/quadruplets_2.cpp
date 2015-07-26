#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Quadruplets   {
public:

  // Returns the number of quadruplets that sum to zero.
  int zeroQuadrupletsCount(vector<int> a, vector<int> b, vector<int> c, vector<int> d)  {
    map<int,int> SumCount;

    for(unsigned int i=0;i<a.size();i++)
    {
      for(unsigned int j=0;j<b.size();j++)
      {
        int CurSum = a[i]+b[j];
        SumCount[CurSum]++;
      }
    }

    int Count=0;
    for(unsigned int i=0;i<c.size();i++) {
      for(unsigned int j=0;j<d.size();j++) {
        Count += SumCount[ -(c[i]+d[j]) ];
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

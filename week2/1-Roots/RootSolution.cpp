#include <stdio.h>

using namespace std;

const double Eps=0.000001;

// function to calculate root
class Root  {

public:
  double Square(const double &number)  {
    if(number<0)
      return -1;

    double L=0, R=number;

    while(L<=R) {
      double Mid = L + (R - L)/2;
      double Answ = Mid * Mid - number;
      if(Answ < 0 && Answ < -Eps)
        L = Mid;
      else if(Answ > 0 && Answ > Eps)
        R = Mid;
      else
        return Mid;
      }
    }
};

int main()
{
  Root R;

  int n;
  scanf("%d",&n);
  printf("%.5f\n", R.Square(n));

  return 0;
}

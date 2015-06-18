#include <stdio.h>

using namespace std;

const double Eps=0.00001;

// function to calculate root
double Square(double number)
{
    if(number<0)
        return -1;

    double L=0, R=number;

    while(L<=R)
    {
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

int main()
{
    for(double i=0;i<100;i++)
        printf("%f - %10.5f\n", i, Square(i));

    return 0;
}

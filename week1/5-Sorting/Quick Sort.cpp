#include <iostream>
#include <vector>

using namespace std;

#define LEN 20

vector<int>* Sort(vector<int> &Arr)
{
    if(Arr.size()==0)
        return NULL;

    int Pivot = Arr[0]; // no need to check if Arr.size is greater than 0. The size is fixed 20

    vector<int> Smaller, Greater;

    for(int i=1;i<Arr.size();i++)
    {
        if(Arr[i]<Pivot)
            Smaller.push_back(Arr[i]);
        else
            Greater.push_back(Arr[i]);
    }

    Sort(Smaller);
    Sort(Greater);

    int Index=0;
    for(int i=0;i<Smaller.size();i++)
        Arr[Index++]=Smaller[i];

    Arr[Index++]=Pivot;

    for(int i=0;i<Greater.size();i++)
        Arr[Index++]=Greater[i];

    return &Arr;
}

int main()
{
    vector<int> Arr={1,15,-645,34,65,876,-3,-7,9,10,23,55,-567,7,97,-97,98,75,45,32};
    Sort(Arr);

    for(int i=0;i<LEN;i++)
        cout << Arr[i] << " ";

    return 0;
}

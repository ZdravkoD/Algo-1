#include <iostream>

using namespace std;

#define LEN 20

void Merge(const int &Begin,const int &Middle,const int &End,int *Arr)
{
    int Beg1=Begin, End1=Middle, Beg2=Middle, End2=End;

    int Size=End-Begin+1;
    int *Merged=new int[Size];
    int Index=0;

    for(int j=Begin;j<End;j++)
    {
        if(Beg1<End1 && (Beg2>=End2 || Arr[Beg1]<=Arr[Beg2]))
        {
            Merged[Index]=Arr[Beg1];
            Index++;
            Beg1++;
        }
        else
        {
            Merged[Index]=Arr[Beg2];
            Index++;
            Beg2++;
        }
    }

    for(int i=Begin,CurIndex=0;i<End;i++,CurIndex++)
        Arr[i]=Merged[CurIndex];

    delete[] Merged;
}

int* Sort(const int &Begin,const int &End,int *Arr)
{
    int Middle = (End+Begin)/2;
    if(End-Begin<2)
        return Arr;

    Sort(Begin,Middle,Arr);
    Sort(Middle,End,Arr);

    if(Begin==0 && End==20)
        int ds=42;
    Merge(Begin,Middle,End,Arr);

    return Arr;
}

int main()
{
    int Arr[LEN]={1,15,-645,34,65,876,-3,-7,9,10,23,55,-567,7,97,-97,98,75,45,32};
    Sort(0,LEN,Arr);

    for(int i=0;i<LEN;i++)
        cout << Arr[i] << " ";

    return 0;
}

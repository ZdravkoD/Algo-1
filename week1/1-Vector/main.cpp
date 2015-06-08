#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
    int Size, Capacity;
    int *Arr, *Arr2;
public:
    Vector(const int &n=0);
    ~Vector();
    void Insert(const int &Index,const int &Val);
    void Add(const int &Val);
    int Get(const int &Index);
    int GetSize();
    int GetCapacity();
};

Vector::Vector(const int &n)
{
    Size = n;
    Capacity = (n>0 ? pow(2, int(log2(n)+1)) : 0);
    cout << "Constuctor Capacity = " << Capacity << endl;
    Arr = new int[Capacity];
    Arr2 = NULL;
}

Vector::~Vector()
{
    delete[] Arr;
}

int Vector::GetSize()
{
    return Size;
}

int Vector::GetCapacity()
{
    return Capacity;
}

void Vector::Add(const int &Val)
{
    if(Size<Capacity)
    {
        Arr[Size++] = Val;
    }
    else
    {
        if(Capacity)
            Capacity *= 2;
        else
        {
            Capacity = 1;
        }
        if(Arr2)
        {
            delete[] Arr2;
            Arr2=NULL;
        }
        Arr2 = new int[Capacity];

        int i;
        for(i=0;i<Size;i++)
        {
            Arr2[i] = Arr[i];
        }
        Arr2[i] = Val;

        delete[] Arr;
        Arr = Arr2;
        Size++;
    }
}

int Vector::Get(const int &Index)
{
    return Arr[Index];
}

void Vector::Insert(const int &Index,const int &Val)
{
    if(Index>Size || Index<0)
    {
        cout << "Прекаляваш!" << endl;
        return;
    }
    if(Size<Capacity)
    {
        for(int i=Size-1;i>Index;i--)
            Arr[i] = Arr[i-1];
        Arr[Index]=Val;
        Size++;
    }
    else
    {
        Capacity *= 2;
        if(Size==32)
            int ds=42;

        if(Arr2)
        {
            delete[] Arr2;
            Arr2=NULL;
        }
        Arr2 = new int[Capacity];

        for(int i=0;i<Index;i++)
            Arr2[i] = Arr[i];

        Arr2[Index] = Val;

        for(int i = Index; i < Size;i++)
            Arr2[i+1] = Arr[i];

        delete[] Arr;

        Arr = Arr2;
        Size++;
    }
}

int main()
{
    Vector V(8);

    cout << "TEST 1 " << endl;
    for(int i=0;i<60;i++)
    {
        V.Insert(i,i+1);
        cout << "Cur Element : " << V.Get(i) << ", Size : " << V.GetSize() << ", Capacity : " << V.GetCapacity() << endl;
    }
    cout << endl;

    Vector V2;

    cout << "TEST 2 " << endl;
    for(int i=0;i<60;i++)
    {
        V2.Add(i);
        cout << "Cur Element : " << V2.Get(i) << ", Size : " << V2.GetSize() << ", Capacity : " << V2.GetCapacity() << endl;
    }

    return 0;
}

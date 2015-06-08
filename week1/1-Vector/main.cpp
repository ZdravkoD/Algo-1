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
    void Pop();
    void Remove(const int &Index);
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

void Vector::Pop()
{
    if(Size>0)
    {
        Arr[Size-1]=0; // delete
        Size--;
        if(Size < Capacity - Capacity/2)
        {
            if(Arr2)
            {
                delete Arr2;
                Arr2 = 0;
            }
            Arr2 = new int[Capacity - Capacity/4];
            for(int i=0;i<Size;i++)
            {
                Arr2[i] = Arr[i];
            }

            delete[] Arr;
            Arr = Arr2;
            Capacity = Capacity - Capacity/4;
        }
    }
}

void Vector::Remove(const int &Index)
{
    if(Index<Size && Index>=0)
    {
        if(Arr2)
        {
            delete[] Arr2;
            Arr2=NULL;
        }
        if(Size < Capacity/2)
        {
            Arr2 = new int[Capacity - Capacity/4];
            Capacity = Capacity - Capacity/4;
        }
        else
            Arr2 = new int[Capacity];

        for(int i=0;i<Index;i++)
            Arr2[i] = Arr[i];

        for(int i=Index+1;i<Size;i++)
            Arr[i-1] = Arr[i];

        Size--;
        delete[] Arr;
        Arr = Arr2;
    }
}

void Vector::Insert(const int &Index,const int &Val)
{
    if(Index<Size && Index>=0)
    {
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
    cout << endl;

    cout << "TEST 3" << endl;
    for(int i=59;i>=0;i--)
    {
        V.Pop();
        cout << "Cur Element : " << V.Get(i) << ", Size : " << V.GetSize() << ", Capacity : " << V.GetCapacity() << endl;
    }
    cout << endl;

    cout << "TEST 4" << endl;
    for(int i=59;i>0;i--)
    {
        V2.Remove(i);
        cout << "Cur Element : " << V2.Get(i-1) << ", Size : " << V2.GetSize() << ", Capacity : " << V2.GetCapacity() << endl;
    }


    return 0;
}

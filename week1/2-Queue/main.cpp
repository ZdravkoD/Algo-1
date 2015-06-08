#include <iostream>
#include <list>

using namespace std;

class Queue
{
    list<int> Arr;
public:
    Queue();
    ~Queue();
    void Push(const int &Val);
    void Pop();
    int Peek();
    int Size();
};

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::Push(const int &Val)
{
    Arr.insert(Arr.end(),Val);
}

void Queue::Pop()
{
    Arr.pop_front();
}

int Queue::Peek()
{
    return Arr.front();
}

int Queue::Size()
{
    return Arr.size();
}

int main()
{
    Queue Q;
    for(int i=0;i<23;i++)
    {
        Q.Push(i);
    }
    cout << Q.Size() << endl;

    for(int i=0;i<23;i++)
    {
        cout << Q.Peek() << endl;
        Q.Pop();
    }

    return 0;
}

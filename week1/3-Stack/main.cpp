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

class Stack
{
    Queue Q;
public:
    Stack();
    ~Stack();
    void Push(const int &Val);
    int Pop();
    int Peek();
    int Size();
};

Stack::Stack()
{
}
Stack::~Stack()
{
}

void Stack::Push(const int &Val)
{
    Q.Push(Val);
}

int Stack::Pop()
{
    Queue Temp;

    while(Q.Size()>1)
    {
        Temp.Push(Q.Peek());
        Q.Pop();
    }

    int result = Q.Peek();
    Q.Pop();

    while(Temp.Size()>0)
    {
        Q.Push(Temp.Peek());
        Temp.Pop();
    }

    return result;
}

int Stack::Peek()
{
    Queue Temp;

    while(Q.Size()>1)
    {
        Temp.Push(Q.Peek());
        Q.Pop();
    }

    int result = Q.Peek();
    Temp.Push(Q.Peek());
    Q.Pop();

    while(Temp.Size()>0)
    {
        Q.Push(Temp.Peek());
        Temp.Pop();
    }

    return result;
}

int Stack::Size()
{
    return Q.Size();
}

int main()
{
    Stack S;
    for(int i=0;i<23;i++)
    {
        S.Push(i);
    }
    cout << S.Size() << endl << endl;

    for(int i=0;i<23;i++)
    {
        cout << S.Peek() << " " << S.Size() << endl;
    }

    cout << endl << endl;
    for(int i=0;i<23;i++)
    {
        cout << S.Pop() << " " << S.Size() << endl;
    }


    return 0;
}

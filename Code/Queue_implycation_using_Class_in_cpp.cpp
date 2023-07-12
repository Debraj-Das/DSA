#include <iostream>

using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front;
    int rare;

public:
    Queue(int n = 10)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rare = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool is_empty()
    {
        if (front == rare)
            return true;
        else
            return false;
    }

    bool is_full()
    {
        if (rare == (size - 1))
            return true;
        else
            return false;
    }

    void enqueue(int a)
    {
        if (is_full())
        {
            cout << "Queue is full.So " << a << " vaule can not enter the queue" << endl;
            return;
        }
        rare++;
        arr[rare] = a;
        return;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty.So Dequeue is not possible" << endl;
            return -1; // -1 vaule to return to show Queue is empty ;
        }
        front++;
        return arr[front];
    }
};

int main()
{
    Queue q;
    for (int i = 0, n; i < 4; ++i)
    {
        cout << (i + 1) << ") ";
        cin >> n;
        q.enqueue(n);
    }
    for (int i = 0; i < 3; ++i)
        cout << (i + 1) << ") vaule is " << q.dequeue() << endl;

    cout << (q.is_empty() ? "Queue is empty" : "Queue is not empty") << endl;

    q.is_full() ? cout << "Queue is full" << endl : cout << "Queue is not full" << endl;

    return 0;
}

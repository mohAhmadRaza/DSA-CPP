#include <iostream>
using namespace std;

class Queue
{
public:
    int ElementsCount;
    int *Array;
    int ArrSize;
    int front;
    int rear;

    Queue(int Size)
    {
        ArrSize = Size;
        Array = new int[ArrSize];
        front = rear = -1;
        ElementsCount = 0;
    }

    void Enqueue(int value)
    {

        if (ElementsCount == ArrSize)
        {
            cout << "Queue Is Full Now !!" << endl;
        }
        else
        {
            rear = (rear + 1) % ArrSize;
            Array[rear] = value;
            ElementsCount++;
        }
    }

    int Dequeue()
    {
        if (ElementsCount == 0)
        {
            cout << "No Elements To Dequeue" << endl;
            return -1;
        }
        else if (front == rear)
        {
            cout << "No Elements To Dequeue Now !!" << endl;
        }
        else
        {
            front = (front + 1) % ArrSize;
            ElementsCount--;
            return Array[front];
        }
        return -1;
    }

    int size()
    {
        return ElementsCount;
    }

    bool IsEmpty()
    {
        if (rear == front)
        {
            return true;
        }
        else if (ElementsCount == 0)
        {
            return true;
        }
        return false;
    }

    bool IsFull()
    {
        return ElementsCount == ArrSize;
    }

    int FrontElement()
    {
        if (ElementsCount != 0)
        {
            return Array[front];
        }
        else
        {
            return -1;
        }
    }

    void Display()
    {
        if (front < rear)
        {
            for (int count = front + 1; count <= rear; count++)
            {
                cout << Array[count] << " -> ";
            }
        }
        else if (front > rear)
        {
            for (int count = front + 1; count >= rear; ((count + 1) % ArrSize))
            {
                cout << Array[count] << " -> ";
            }
        }
    }
};

int main()
{
    Queue queue(10);

    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Enqueue(6);

    queue.Display();
    cout << endl;

    return 0;
}

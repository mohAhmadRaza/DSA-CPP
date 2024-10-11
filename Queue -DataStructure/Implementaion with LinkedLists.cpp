#include <iostream>
using namespace std;

class Node
{

public:
    // current node's value
    int val;

    // Node to store address of next node
    Node *next;

    // Parameterized Constructor
    Node(int data) : val(data), next(nullptr) {};
};

class Solution
{
public:
    // point to node which we dequeued first
    Node *front;

    // point to node where we will enqueue the new nodes
    Node *rear;

    // counting total elements in List
    int ElementsCount;

    Solution() : front(nullptr), rear(nullptr), ElementsCount(0) {}

    void Enqueue(int data)
    {

        Node *newNode = new Node(data);

        if (IsEmpty())
        {
            rear = front = newNode;
        }

        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        ElementsCount++;
    }





    int Dequeue()
    {

        if (IsEmpty())
        {

            cout << "Nothing To dequeue" << endl;
            return -1;
        }

        // if there's only a single element in our list
        else if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
            int val = front->val;
            Node *temp = front;
            delete temp;
            return val;
        }
        
        // if list contains more than 1 elements in it
        Node *toDel = front;
        int Value = front->val;
        front = front->next;
        delete toDel;
        ElementsCount--;
        
        // Here, we are implementing that important point, that if front is null
        // Make the rear to point to null to
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return Value;
    }


    int size()
    {
        return ElementsCount;
    }

    bool IsEmpty()
    {
        return ElementsCount == 0 || (!rear && !front);
    }

    int getFront()
    {
        if (!IsEmpty())
        {
            return front->val;
        }
        else
        {
            return -1;
        }
    }

    int getRear()
    {
        if (!IsEmpty())
        {
            return rear->val;
        }
        else
        {
            return -1;
        }
    }


    void Display()
    {
        Node *temp = front;
        if (front = nullptr)
        {
            cout << "Nothing To Display !!! " << endl;
            return;
        }

        while (temp)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
    }
};

int main()
{
    Solution List;

    List.Enqueue(10);
    List.Enqueue(50);
    List.Enqueue(40);
    List.Enqueue(30);
    List.Enqueue(20);

    List.Dequeue();
    List.Dequeue();
    List.Dequeue();
    List.Dequeue();
    List.Dequeue();
    List.Dequeue();

    List.Display();

    return 0;
}

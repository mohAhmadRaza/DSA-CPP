#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int data) : value(data), next(NULL) {};
};

class Solution
{
public:
    Node *head;

    Solution() : head(NULL) {};

    void InsertAtBegin(int newData)
    {
        Node *newNode = new Node(newData);
        Node *curr = head;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = curr;
            head = newNode;
        }
    }

    void RotateList(int k)
    {
        int count = 1;
        Node *temp = head;

        if (!head)
        {
            cout << "No Data to rotate" << endl;
        }

        else
        {
            while (temp->next)
            {
                temp = temp->next;
                count++;
            }

            temp->next = head;

            k = k % count;
            int StepsFarward = count - k;
            Node * newTail = head;

            for (int i=0 ; i<StepsFarward ; i++){
                newTail = newTail->next;
            }

            head = newTail->next;
            newTail->next = nullptr;

            display();
        }
    }
    void display()
    {
        Node *curr = head;

        if (!head)
        {
            cout << "Print not" << endl;
        }

        while (curr)
        {
            cout << curr->value << " -> ";
            curr = curr->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    Solution List;

    List.InsertAtBegin(10);
    List.InsertAtBegin(9);
    List.InsertAtBegin(8);
    List.InsertAtBegin(4);
    List.InsertAtBegin(5);

    List.RotateList(3);
    return 0;
}

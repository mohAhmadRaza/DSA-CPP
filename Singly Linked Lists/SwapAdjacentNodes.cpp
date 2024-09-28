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

    void insertAtBegin(int newData)
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

    void SwapNodes()
    {
        Node *temp = head;

        if (!head || !head->next)
        {
            cout << "Nothing to swap" << endl;
        }

        else
        {
            while (temp && temp->next)
            {
                int tempVal = temp->value;
                temp->value = temp->next->value;
                temp->next->value = tempVal;
                temp = temp->next->next;
            }
        }

        display();
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

    List.insertAtBegin(10);
    List.insertAtBegin(9);
    List.insertAtBegin(8);
    List.insertAtBegin(4);
    List.insertAtBegin(5);

    List.SwapNodes();
    return 0;
}

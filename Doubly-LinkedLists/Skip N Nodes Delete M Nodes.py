#include <iostream>
#include <math.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

class Solution
{
public:
    Node *head;

    Solution() : head(nullptr) {};

    void insertAtBegin(int data)
    {

        Node *newNode = new Node(data);

        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void SkipAndDelete(int m, int n)
    {
        Node *temp = head;
        int skip = 1;
        int del = 1;

        while (temp)
        {
            for (int i = 1; i < m && temp != nullptr; i++)
            {
                temp = temp->next;
            }

            if (temp == nullptr)
                return;

            Node *toDelete = temp->next;
            for (int i = 1; i <= n && toDelete != nullptr; i++)
            {
                Node *todel = toDelete;
                toDelete = toDelete->next;
                delete todel;
            }

            temp->next = toDelete;
            temp = temp->next;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    Solution List;

    List.insertAtBegin(6);
    List.insertAtBegin(5);
    List.insertAtBegin(4);
    List.insertAtBegin(3);
    List.insertAtBegin(2);
    List.insertAtBegin(1);

    List.SkipAndDelete(2, 3);
    List.display();

    return 0;
}

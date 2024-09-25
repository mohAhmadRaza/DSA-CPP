#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val) : val(val), next(nullptr), prev(nullptr) {};
};

class Solution
{
public:
    Node *head;
    Node *tail;

    Solution() : head(nullptr), tail(nullptr) {};

    void InsertAfterSpecificnode(int key, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;

        if (head == nullptr)
        {
            cout << "Cant Insert Anuthing !!" << endl;
        }

        else
        {
            if (head->val == key and head->next == nullptr)
            {
                head->next = newNode;
                newNode->prev = head;
                tail = newNode;
            }
            else if (tail->val == key)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else
            {

                while (temp)
                {
                    if (temp->val == key)
                    {
                        newNode->next = temp->next;
                        temp->next->prev = newNode;
                        newNode->prev = temp;
                        temp->next = newNode;

                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
};
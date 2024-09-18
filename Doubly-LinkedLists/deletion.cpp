#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {};
};

class Solution
{
public:
    Node *head;
    Node *tail;

    Solution() : head(nullptr), tail(nullptr) {};

    void deletion(int pos)
    {

        if (!head)
        {
            cout << "Nothing to delete here!" << endl;
        }
        else if (head)
        {

            if (pos == 0)
            {
                Node *temp = head;
                if (head->next)
                {
                    head = head->next;
                    head->prev = nullptr;
                }
                else if (!head->next)
                {
                    head = tail = nullptr;
                }
                delete temp;
                return;
            }
            else
            {
                int count = 1;
                Node *curr = head;
                while (curr and count < pos - 1)
                {
                    count++;
                    curr = curr->next;
                }

                if (curr and !curr->next and count == pos - 1)
                {
                    cout << "Index Out of range" << endl;
                }

                else if (curr and curr->next and count == pos - 1)
                {
                    if (!curr->next->next)
                    {
                        tail = tail->prev;
                        tail->next = nullptr;
                    }
                    else
                    {   
                        Node * temp = curr->next;
                        curr->next = curr->next->next;
                        curr->next->next->prev = curr;

                        delete temp;
                        return;
                    }

                }
                else
                {
                    cout << "Index Not Found" << endl;
                }
            }
        }
    }
};

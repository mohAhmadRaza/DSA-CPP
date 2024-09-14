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

    void Insertion(int data, int pos)
    {
       
        Node *newNode = new Node(data);
        Node *curr = head;
        
        if( pos < 0){
            cout << "index Out of range" << endl;
            return;
        }
        
        if (!head)
        {
            if (pos == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                cout << "Index not found" << endl;
            }
        }
        else
        { // Valid if list not empty and want to insert at first index
            if (pos == 0)
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                if (!head->next) // If there's only one element
                    tail = head;
                return;
            }
            else
            {
                int count = 0;
                while (curr and count < pos - 1)
                {
                    count++;
                    curr = curr->next;
                }

                // Insertion at middle of doubly linked list
                if (curr->next and count == pos - 1)
                {
                    newNode->next = curr->next;
                    curr->next->prev = newNode;
                    curr->next = newNode;
                    newNode->prev = curr;
                }

                // Insertion at Last of linked list
                else if (curr and !curr->next and count == pos - 1)
                {
                    curr->next = newNode;
                    newNode->prev = curr;

                    // Storing last element's address to move back
                    tail = newNode;
                }

                // If index is out of bound
                else
                {
                    cout << "Index not Found" << endl;
                }
            }
        }
    }
};
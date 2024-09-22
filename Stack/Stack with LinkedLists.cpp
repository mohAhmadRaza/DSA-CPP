#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data) : val(data) {};
};

class Stack
{
public:
    Node *head;
    Node *tail;

    Stack() : head(nullptr), tail(nullptr) {};

    bool IsEmpty()
    {
        return head == nullptr and tail == nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);

        if (IsEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pop()
    {
        if (IsEmpty())
        {
            cout << "No element to pop" << endl;
            return -1;
        }

        int value = tail->val; // Store value to return
        Node *toDelete = tail; // Node to be deleted

        if (head == tail)
        {
            head = tail = nullptr; // Reset head and tail
        }
        else
        {
            Node *temp = head;
            // Traverse to the second last node
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = nullptr; // Remove the last node
            tail = temp;
        }

        delete toDelete; // Delete the last node
        return value;    // Return the popped value
    }

    int top()
    {
        if (IsEmpty())
        {
            cout << "No Value to return" << endl;
            return true;
        }
        int value = tail->val;
        return value;
    }

    void display()
    {
        Node *curr = head;

        while (curr)
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl; // Print "NULL" at the end to indicate the end of the list
    }
};

int main()
{
    Stack stack;

    stack.push(12);
    stack.push(76);
    stack.push(56);
    
    stack.display();

    return 0;
}

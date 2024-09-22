#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {};
};

class Circular
{
public:
    Node *head;
    Node *tail;

    Circular() : head(nullptr), tail(nullptr) {};

    void insertion(int data, int pos)
    {
        Node *newNode = new Node(data);

        if (pos < 0)
        {
            cout << "Undefined Index" << endl;
            return;
        }
        if (head == nullptr)
        {

            if (pos == 0)
            {
                newNode->next = newNode;
                head = tail = newNode;
            }
            else
            {
                cout << "List is empty, we can't insert at " << pos << endl;
            }
        }
        else
        {
            if (pos == 0)
            {
                newNode->next = head;
                tail->next = newNode;
                head = newNode;
            }
            else
            {
                Node *temp = head;
                int count = 1;

                while (temp->next != head && count < pos - 1)
                {
                    count++;
                    temp = temp->next;
                }

                if (!(temp->next == head) && count == pos - 1)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                }

                else if (temp->next == head && count == pos - 1)
                {
                    newNode->next = head;
                    temp->next = newNode;
                    tail = newNode;
                }

                else
                {
                    cout << "Can't make an insertion" << endl;
                }
            }
        }
    }

    void deletion(int value)
    {

        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {

            Node *temp = head;

            // If there's only one element in List
            if (head->next == head and head->data == value)
            {
                Node *temp = head;
                head = tail = nullptr;
                delete temp;
            }

            else
            {
                bool found = false;
                Node * prev = head;

                while (temp->next != head)
                {
                    if (temp->data == value)
                    {
                        found = true;
                        Node * delNode = temp;

                        if (tail->next == temp){
                            head = head->next;
                            tail->next = head;
                            delete delNode;
                            break;
                        }

                        else{
                            prev->next = temp->next;
                            delete delNode;
                            break;
                        }
                    }
                    prev = temp;
                    temp = temp->next;
                }

                if (!found and temp->data == value){
                    Node * delnode = temp;
                    prev->next = head;
                    tail = prev;
                    delete temp;
                    found = true;
                }
                else if(!found){
                    cout << "Not found" << endl;
                }
            }
        }
    }
};

#include <iostream>
using namespace std;

class Node
{
public:
    int Value;
    int Priority;
    Node *next;

    Node(int data, int pri) : Value(data), Priority(pri), next(nullptr) {};
};

class Solution
{
public:
    Node *head;

    Solution() : head(nullptr) {};

    void Insert(int data, int pri)
    {
        Node *newNode = new Node(data, pri);
        Node *temp = head, *prev = head;
        bool found = false;

        if (!head)
        {
            head = newNode;
        }

        else
        {
            while (temp and temp->Priority <= newNode->Priority )
            {
                if (temp->Priority == newNode->Priority)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    found = true;
                    break;
                }
                else if (temp->Priority > newNode->Priority)
                {
                    found = true;
                    if (temp == head)
                    {
                        newNode->next = head;
                        head = newNode;
                    }
                    else
                    {
                        newNode->next = prev->next;
                        prev->next = newNode;
                    }

                    break;
                }
                prev = temp;
                temp = temp->next;
            }

            if (!found)
            {
                prev->next = newNode;
            }
        }
    }

    void Display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->Value << " -> ";
            temp = temp->next;
        }
    }

    int GetHighestPriority(){
        if (!head){
            cout << "Can't Reterieve Elements !!" << endl;
            return -1;
        }
        else{
            int value = head->Value;
            Node * ToDel = head;
            head = head->next;
            delete ToDel;
            return value;
        }
    }

    bool IsEmpty(){
        return head == nullptr;
    }

    int pop(){

        if(IsEmpty()){
            cout << "Nothing !! " << endl;
            return -1;
        }
        else{
            int value =  head->Value;
            head = head->next;
            return value;
        }
    }
};

int main()
{
    Solution queue;

    queue.Insert(1, 1);
    queue.Insert(6, 6);
    queue.Insert(3, 3);
    queue.Insert(2, 2);
    queue.Insert(5, 1);

    queue.Display();
    cout << endl;
    cout << queue.GetHighestPriority() << endl;
    queue.Display();

    return 0;
}

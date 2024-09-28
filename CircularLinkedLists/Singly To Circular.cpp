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
            return;
        }
        else
        {
            newNode->next = curr;
            head = newNode;
            return;
        }
    }

    void ConvertToCircular(){
        Node * temp = head;

        if (!head){
            cout << "List is Empty" << endl;
        }
        else if (!head->next){
            head->next = head;
        }
        else{
            while (temp->next){
                temp = temp->next;
            }
            temp->next = head;

            cout << "List converted to circular." << endl;
        }
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

    List.ConvertToCircular();
    return 0;
}

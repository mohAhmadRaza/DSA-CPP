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

    pair<Node *, Node *> SplitList()
    {

        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;

        Node *slow = head;
        Node *fast = head;

        while (fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next->next == head)
        {
            fast = fast->next;
        }

        Node *head1 = head;
        Node *head2 = slow->next;
        fast->next = slow->next;
        slow->next = head;
        return {head1, head2};
    }

    void display(Node * h){
        Node * temp = h;

        do{
            cout << temp->value << " -> ";
            temp = temp->next;
        }while( temp != h);

        cout << "NULL" << endl;
    }
};


int main()
{

    Solution List;
    List.insertAtBegin(10);
    List.insertAtBegin(4);
    List.insertAtBegin(9);
    
    pair<Node*, Node*> result = List.SplitList();

    List.display(result.first);
    List.display(result.second);

    return 0;
}

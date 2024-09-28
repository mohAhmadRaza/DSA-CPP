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

    void DeleteDuplicates(){
        
        if (!head || !head->next){
            cout << "No Duplicts Found" << endl;
        }

        else{
            Node * left = head;
            Node * right = head->next;

            while (right){
                if (left->value == right->value){

                    if(!right->next){
                        left->next = nullptr;
                    }
                    else{
                        left->next = right->next;
                        Node * temp = right;
                        right = right->next;
                        delete temp;
                    }
                }
                else{
                    left = right;
                    right = right->next;
                }
            }

            display();
        }
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
    List.insertAtBegin(5);
    List.insertAtBegin(5);
    List.insertAtBegin(4);
    List.insertAtBegin(2);
    List.insertAtBegin(2);

    List.DeleteDuplicates();
    return 0;
}

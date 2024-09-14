#include <iostream>
using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;

    ListNode(int data) : value(data), next(NULL) {};
};

class Solution
{
public:
    ListNode *head;

    Solution() : head(NULL) {};

    void insertAtEnd(int value)
    {
        ListNode *newNode = new ListNode(value);
        ListNode *curr = head;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            while (curr->next)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void insertAtStart(int value)
    {
        ListNode *newNode = new ListNode(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtposition(int pos, int value)
    {
        ListNode *newNode = new ListNode(value);
        ListNode *curr = head;
        int currPos = 1;

        if (head == NULL and pos == 0)
        {
            head = newNode;
        }
        else if ( head == NULL and pos != 0){
            cout<<"Index Out Of Range";
        }
        else if (pos == 0 and head != NULL)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            while (currPos < pos - 1 and curr) //CurrPos = 3 //curr 
            {
                currPos += 1;
                curr = curr->next;
            }

            if (currPos == pos - 1)
            {
                newNode->next = curr->next;
                curr->next = newNode;
            }
            else
            {
                cout << "Index Out Of Range" << endl;
            }
        }
    }

    // Method to print the linked list
    void printList()
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void deleteNode(int pos){
        ListNode* curr = head;

        if ( head == NULL ){
            cout << "Nothing to remove"<<endl;
        }
        else if ( head != NULL){

            if ( pos == 0){
                head = head->next;
            }
            else{
                int currPos = 1;

                while ( currPos < pos - 1 and curr->next){
                    cout<<"COUNT"<<endl;
                    currPos += 1;
                    curr = curr->next;
                }

                if ( currPos == pos - 1){
                    curr->next = curr->next->next;
                }
                else{
                    cout << "Index Out Of Range!"<<endl;
                }

            }
        }
    }

    ~Solution(){
        ListNode* current = head;
        ListNode* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
    }
    
};

int main()
{
    Solution Node;

    // Insertion
    Node.insertAtEnd(2); //currpos = 1 and curr = 2
    Node.insertAtEnd(24); //currpos = 2 and curr = 24
    Node.insertAtEnd(4);
    Node.insertAtEnd(3);
    Node.insertAtposition(3, 23);
    Node.insertAtStart(45);
    Node.insertAtposition(3, 90);

    Node.printList();


    // Deletion                 // 1 45, 2 2, 3 90, 4 24,  5 23, 6 4, 7 3
    Node.deleteNode(0);
    Node.printList();
    Node.deleteNode(8);
    Node.printList();
    Node.deleteNode(3);
    Node.printList();
    

    return 0;
}
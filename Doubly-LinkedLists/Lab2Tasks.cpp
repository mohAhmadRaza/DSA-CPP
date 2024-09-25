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

    void InsertAtStart(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void DeleteNode(int val)
    {

        if (head == nullptr)
        {
            cout << "Value Not Found" << endl;
        }
        else
        {
            int count = 0;
            Node *temp = head;
            bool found = false;

            while (temp)
            {
                if (temp->val == val)
                {
                    if (temp == head)
                    {
                        Node *delNode = temp;
                        head = head->next;
                        head->prev = nullptr;

                        delete delNode;
                    }
                    else if (temp == tail)
                    {
                        temp->prev->next = nullptr;
                        tail = temp->prev;
                        delete temp;
                    }
                    else
                    {
                        Node *todel = temp;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete todel;
                    }
                    found = true;
                    return;
                }
                temp = temp->next;
            }
            if (!found)
            {
                cout << "Value not found !!" << endl;
            }
        }
    }

    void ReverseDisply()
    {
        Node *temp = tail;

        while (temp)
        {
            cout << temp->val << " -> ";
            temp = temp->prev;
        }

        cout << "NUll" << endl;
    }

    void InsertAfterSpecificnode(int key, int data)
    {
        Node *newNode = new Node(data);
        Node * temp = head;

        if ( head == nullptr ){ cout << "Cant Insert Anuthing !!" << endl; }

        else{
            if ( head->val == key and head->next == nullptr) {
                head->next = newNode;
                newNode->prev = head;
                tail = newNode;
            }
            else if (tail->val == key){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else{
                
                while (temp){
                    if ( temp->val == key ){
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

    int CoundNodes(){
        Node * temp = head;
        int count = 0;

        while(temp){
            count++;
            temp = temp->next;
        }

        return count;
    }

    void TraverseList(){
        cout << "Farward Direction !!" << endl;

        Node * temp = head;
        while (temp){
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
      
        cout << "Backward Direction !!" << endl;

        Node * temp1 = tail;
        while (temp1){
            cout << temp1->val << " -> ";
            temp1 = temp1->prev;
        }
        cout << "NULL" << endl;
    }

};

Node* MergeLists(Solution * List1, Solution * List2);

int main() {
    Solution List1;
    List1.InsertAtStart(10);
    List1.InsertAtStart(9);
    List1.InsertAtStart(8);
    List1.InsertAtStart(5);
    List1.InsertAtStart(3);

    Solution List2;
    List2.InsertAtStart(5);
    List2.InsertAtStart(4);
    List2.InsertAtStart(3);
    List2.InsertAtStart(2);
    List2.InsertAtStart(1);

    Node* List3 = MergeLists(&List1, &List2);

    Node *temp = List3;
    while(temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << " NULL " << endl;

    return 0;
}


Node* MergeLists(Solution * List1, Solution * List2){
    Node * temp1 = List1->head;
    Node * temp2 = List2->head;

    Node * newNode = new Node(0);
    Node * temp3 = newNode;
    
    while (temp1 && temp2){
        if (temp1->val <= temp2->val){
            Node * suppose = temp1;
            suppose->prev = temp3;
            temp3->next = suppose;
            temp3 = temp3->next;

            temp1 = temp1->next;
        }
        else{
            Node * suppose = temp2;
            suppose->prev = temp3;
            temp3->next = suppose;
            temp3 = temp3->next;

            temp2 = temp2->next;
        }
    }

    if (temp1){
        temp3->next = temp1;
        temp1->prev = temp3;
    }
    else if (temp2){
        temp3->next = temp2;
        temp2->prev = temp3;
    }

    Node * mergedHead = newNode->next;
    if (mergedHead) mergedHead->prev = nullptr;
    delete newNode;

    return mergedHead;
}

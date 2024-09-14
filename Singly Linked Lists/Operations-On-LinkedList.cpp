#include <iostream>
#include<set>
#include<map>
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

    void insertAtEnd(int newData)
    {
        Node *newNode = new Node(newData);
        Node *curr = head;

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

    void update(int index, int newValue)
    {
        Node *newNode = new Node(newValue);
        Node *curr = head;

        if (head == NULL)
        {
            cout << "No Index to update" << endl;
        }
        else
        {
            if (index == 0)
            {
                curr->value = newValue;
            }
            else
            {
                int count = 0;
                while (curr and count < index)
                {
                    count += 1;
                    curr = curr->next;
                }

                if (curr and count == index)
                {
                    curr->value = newValue;
                }
                else
                {
                    cout << "Index Out of range" << endl;
                }
            }
        }
    }

    void display()
    {
        Node *curr = head;
        if(!head){
            cout<<"Print not" << endl;
        }
        while (curr)
        {
            cout << curr->value << " -> ";
            curr = curr->next;
        }

        cout << "NULL" << endl;
    }

    void search(int targetValue)
    {
        Node *curr = head;
        int count = 0;

        if (!head)
        {
            cout << "Linked List is empty" << endl;
        }
        else
        {
            while (curr)
            {
                if (curr->value == targetValue)
                {
                    cout << "Value Found At " << count << endl;
                    return;
                }
                count++;
                curr = curr->next;
            }

            cout << "Value Not Found" << endl;
        }
    }

    void insertAfter(int index, int newValue)
    {
        Node *newNode = new Node(newValue);
        Node *curr = head;

        if (head == NULL)
        {
            cout << "Can't Insert After " << index << " as List is Empty" << endl;
        }
        else
        {
            if (index == 0)
            {
                newNode->next = curr->next;
                curr->next = newNode;
            }
            else
            {
                int count = 0;
                while (curr->next and count < index)
                {
                    count++;
                    curr = curr->next;
                }

                if (count == index)
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
    }

    void deleteNode(int value)
    {
        Node *curr = head;
        int index = 0;
        Node *prev = head;
        bool found = false;

        if (!head)
        {
            cout << "Value Not Found To Delete" << endl;
        }
        else
        {
            while (curr)
            {
                if (curr->value == value)
                {
                    if (index == 0)
                    {
                        head = head->next;
                    }
                    else
                    {
                        prev->next = curr->next;
                    }
                    found = true;
                    delete curr;
                }
                index++;
                curr = curr->next;
                prev = curr;
            }

            if (!found)
            {
                cout << "Element Not Found" << endl;
            }
        }
    }

    void sorting()
    {
        Node *curr = head;
        int size = 0;

        while (curr)
        {
            size++;
            curr = curr->next;
        }

        curr = head;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j <size - i -1; j++){
                if (curr->value < curr->next->value){
                    int temp  = curr->value;
                    curr->value = curr->next->value;
                    curr->next->value = temp;
                    display();
                }
                curr = curr->next;
            }
        }
    }

    void reverse(){
        Node * curr = head;
        Node * prev = NULL;  // Initialize prev to NULL
        Node * nextNode = NULL;

        while (curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    void removeDuplicates(){
        Node * curr = head;
        set<int> mySet;
        Node * prev = head;

        while (curr){
            if (mySet.count(curr->value) != 1){
                mySet.insert(curr->value);
                prev = curr;
            }
            else{
                prev->next = curr->next;
            }
            curr = curr->next;
        }

    }

    void findMiddle(){
        Node * slow = head;
        Node * fast = head;

        while (fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle Element Is : "<< slow->value << endl;
    }

    void rotateList(int ind){
        Node * curr = head;
        int count = 0;

        if( head == NULL){
            cout << "We can't rotate List" << endl;
        }
        else{
            while( curr and count < ind-1){
                count += 1;
                curr = curr->next;
            }

            if(count == ind-1){
                Node * newNode = curr->next;
                curr->next = NULL;
                Node *temp = newNode;

                while(temp->next){
                    temp = temp->next;
                }
                temp->next = head;
                temp = newNode;
                head = newNode;
            }
        }
    }

    void mergeTwoLinkedLists(Node * secondHead, int position){
        Node * first = head;
        Node * second = secondHead;

        if ( head == NULL ){
            cout << "We can't insert given List, as current lists is empty" << endl;
        }
        else{
            if(position == 0){
                secondHead->next = head;
                head = secondHead;
            }
            else{
                int count = 0;
                while (first and count < position-1){
                    count += 1;
                    first = first->next;
                }
                if(!first->next){
                    first->next = secondHead;
                }
                else{
                    Node * newNode = first->next; 
                    first->next = secondHead;
                    while (first->next){
                        first = first->next;
                    }
                    first->next = newNode;
                }
            }
        }
    }

    void LinkedListFrequecy(){
        Node * curr = head;
        map<int, int> frequency;

        while (curr){
            frequency[curr->value]++;
            curr = curr->next;
        }

        Node * nodesFrequency = nullptr;
        Node * temp = nullptr;
        
        for(const auto& pair : frequency){
            Node * newNode = new Node(pair.second);

            if (!nodesFrequency){
                nodesFrequency = newNode;
                temp = nodesFrequency;
            }
            else{
                temp->next = newNode;
                temp = temp->next;
            }
            
        }

        // Output the new linked list (for demonstration purposes)
        temp = nodesFrequency;
        while (temp) {
            cout << temp->value << " ";  // Print the frequency
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    Solution List;

    List.insertAtBegin(20);
    List.insertAtBegin(30);
    List.insertAtBegin(40);
    List.insertAtBegin(10);

    List.insertAtBegin(70);
    List.insertAtBegin(80);
    List.insertAtEnd(90);
    List.rotateList(4);
    List.display();
    

    return 0;
}
#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node * next;
    Node * prev;

    Node(int data) : val(data), next(nullptr), prev(nullptr) {};
};

class Solution{
public:
    Node * head;

    Solution() : head(nullptr) {};
    
    void insertAtBegin(int data){

        Node * newNode = new Node(data);

        if(!head){
            head = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

    }
    void rotate(int k){
        int count = 1;
        Node * temp = head;
        
        while (temp && count < k){
            count++;
            temp = temp->next;
        }

        if(temp && count == k){
            Node * newNode = temp->next;
            newNode->prev = nullptr;
            temp->next = nullptr;

            temp = newNode;

            while(temp->next){
                temp = temp->next;
            }
            temp->next = head;
            head->prev = temp;

            head = newNode;

        }

        display();
    }

    void display(){
        Node * temp = head;

        while(temp){
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main(){
    Solution List;

    List.insertAtBegin(6);
    List.insertAtBegin(5);
    List.insertAtBegin(4);
    List.insertAtBegin(3);
    List.insertAtBegin(2);
    List.insertAtBegin(1);
    List.display();

    List.rotate(2);

    return 0;
}

#include<iostream>
using namespace std;

class Node{
public:
   int val;
   Node * next;

   Node(data) : val(data), next(nullptr) {};
};

class Solution{
public:
    Node * front;
    Node * rear;
    int ElementsCount;

    Solution() : front(nullptr), rear(nullptr), ElementsCount(0) {};

    void Enqueue(int data){
        Node * newNode = Node(data);

        if (IsEmpty()){
            rear = front = newNode
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        ElementsCount++;
    }

    int Dequeue(){
        Node * toDel = front;
        int Value = front->val;
        front = front->next;
        delete toDel;
        ElementsCount--;
        return Value;
    }

    int size(){
        return ElementsCount;
    }

    void IsEmpty(){
        return ElementsCount == 0 || ( !rear && !front )
    }
};

#include <iostream>
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

    List.LinkedListFrequecy();

    return 0;
}
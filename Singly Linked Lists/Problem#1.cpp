Problem Statement:
Delete from an ordered list L nodes occupying positions indicated in list L itself. 
For instance, if L = (1 3 5 7 8), then after deletion, L = (3 7).


#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

void deletePositions(Node*& head) {
    Node* temp = head;
    Node* ind = head;
    Node* prev = nullptr;

    int count = 1;

    while (temp && ind) {
        if (count == ind->value) {
            // Deleting the head node
            if (temp == head) {
                head = temp->next;
                delete temp;
                temp = head;
            }
            // Deleting the last node
            else if (temp->next == nullptr) {
                prev->next = nullptr;
                delete temp;
                temp = nullptr;
            }
            // Deleting a node in between
            else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            // Move to the next position to delete
            ind = ind->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
        count++;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating an example list: L = (1 3 5 7 8)
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(8);

    cout << "Original List: ";
    printList(head);

    // Delete nodes based on their positions
    deletePositions(head);

    cout << "Modified List after deletion: ";
    printList(head);

    return 0;
}

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int data) : value(data), next(NULL) {};
};

void InsertLastRecursively(Node *&head, Node *prev, int value)
{

    if (head == nullptr)
    {
        Node *newNode = new Node(value);

        if (prev == nullptr)
        {
            head = newNode;
        }

        else
        {
            prev->next = newNode;
        }

        return;
    }

    InsertLastRecursively(head->next, head, value);
}

void DeleteComplete(Node * node){

    if (!node){
        return;
    }

    DeleteComplete(node->next);

    delete node;
}

int main()
{

    Node *first = new Node(1);

    InsertLastRecursively(first, nullptr, 2);
    InsertLastRecursively(first, nullptr, 3);
    InsertLastRecursively(first, nullptr, 4);
    InsertLastRecursively(first, nullptr, 5);
    InsertLastRecursively(first, nullptr, 6);


    cout << "Middle Is : "; DisplayRecursively(first); cout << endl;
    cout << "Middle Is : "; AlternateNodes(first); cout << endl;
    cout << "Middle Is : " << FindMiddle(first, first);

    return 0;
}

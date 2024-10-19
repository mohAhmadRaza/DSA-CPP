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

void DisplayRecursively(Node * head){

    if ( head == nullptr){
        cout << "Null" << endl;
        return;
    }

    cout << head->value << " -> ";
    DisplayRecursively(head->next);
}

int main()
{

    Node *first = new Node(5);

    InsertLastRecursively(first, nullptr, 1);
    InsertLastRecursively(first, nullptr, 2);
    InsertLastRecursively(first, nullptr, 3);
    InsertLastRecursively(first, nullptr, 4);

    DeleteRecursively(first, nullptr, 3);

    DisplayRecursively(first);

    return 0;
}

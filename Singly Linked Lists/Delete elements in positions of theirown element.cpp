Problem Statement:
Delete from an ordered list L nodes occupying positions indicated in list L itself. 
For instance, if L = (1 3 5 7 8), then after deletion, L = (3 7).

Note : I'm using some function of my linkedList class, like display(), so you don;t need to worry about that functions, they are not built in.
you can view them in my 'operations-on-LinkedLists' file.

void DeleteSpecialRule2()
    {
        Node *temp = head;
        Node *prev = head;
        int count = 1;
        int comp = temp->value;
        bool found = false;

        while (temp)
        {   
            found = false;
            if (comp == count)
            {
                found = true;
                // if (temp != head){comp = temp->value;}
                // else {comp = temp->next->value;}
                if (temp == head)
                {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
                else if (temp->next == nullptr)
                {
                    prev->next = nullptr;
                    delete temp;
                    temp = nullptr;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            }
            else{
                prev = temp;
                temp = temp->next;
            }
            ++count;
        }

        display();
    }

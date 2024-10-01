Problem Statment:
Delete from list L1 nodes occupying positions indicated in ordered lists L2 and L3. 
For instance, if 
L1 = (A B C D E), 
L2 = (2 4 8), and 
L3 = (2 5), then after deletion, 

L1= (A C).

void DeleteRuleSpecial(int List1[], int size1, int List2[], int size2)
    {
        Node *temp = head;
        Node *prev = head;

        if (!head)
        {
            return;
        }
        else
        {
            int count = 1;
            int i = 0, j = 0, comp = 0;

            if (List1[i] < List2[j]){
                comp = List1[i++];
            }
            else if(List1[i] > List2[j]){
                comp = List2[j++];
            }
            else{
                comp = List1[i++];
                j++;
            }

            cout << size1 << endl;
            bool found = false;

            while (temp)
            {
                found = false;
                
                if (comp == count)
                {
                    found = true;
                    cout << "Matched : " << comp << endl;
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

                count++;

                if (i < size1 and List1[i] < List2[j] and found)
                {
                    comp = List1[i++];
                }
                else if (j < size2 and List1[i] > List2[j] and found)
                {
                    comp = List2[j++];
                }
                else if (i < size1 and j < size2 and found)
                {
                    comp = List1[i++];
                    j++;
                }
            }
        }

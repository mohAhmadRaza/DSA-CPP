#include <iostream>
using namespace std;

class Node
{
public:
    string CategoryName;
    int CategoryId;
    string CreationDate;
    int ItemsCount;
    int ParentId;

    Node *nextCategory;
    Node *prevCategory;

    Node(string a, int b, string c, int d, int e) : CategoryName(a), CategoryId(b), CreationDate(c), ParentId(d), nextCategory(nullptr), prevCategory(nullptr), ItemsCount(e) {};
};

class Solution
{
public:
    Node *top;
    Node *currentLocation = top;

    Solution() : top(nullptr) {};

    void OpenCategory(int CategoryID, string CategoryName, string CreationDate, int itemCount, int ParentCategoryID)
    {
        Node *newCategory = new Node(CategoryName, CategoryID, CreationDate, ParentCategoryID, itemCount);

        if (top == nullptr)
        {
            top = newCategory;
            currentLocation = top;
        }

        else
        {
            newCategory->nextCategory = top;
            top->prevCategory = newCategory;
            top = newCategory;
            currentLocation = top;
        }
    }

    void GoFarward()
    {

        if (!currentLocation)
        {
            cout << "Nothing To Move Farward !!" << endl;
        }

        else if (currentLocation->nextCategory != nullptr)
        {
            currentLocation = currentLocation->nextCategory;
            cout << "Moved" << endl;
        }

        else
        {
            cout << "Nothing To Move Farward !!" << endl;
        }
    }

    void GoBack()
    {

        if (!currentLocation)
        {
            cout << "Nothing To Move Backward !!" << endl;
        }

        else if (currentLocation->prevCategory == nullptr)
        {
            cout << "Nothing To Move Backward !!" << endl;
        }

        else
        {
            currentLocation = currentLocation->prevCategory;
        }
    }

    void dis(){
        Node * temp = top;
        while(temp){
            cout << "Name : " << temp->CategoryName << endl;
            temp = temp->nextCategory;
        }
    }

    void HistoryNavigation()
    {

        cout << "Current Location Category Attributes " << endl;
        cout << "Category's Name : " << currentLocation->CategoryName << endl;
        cout << "Category's ID : " << currentLocation->CategoryId << endl;
        cout << "Category's ItemCount : " << currentLocation->ItemsCount << endl;
        cout << "Category's Date : " << currentLocation->CreationDate << endl;
        cout << "Category's ParentID : " << currentLocation->ParentId << endl;

        cout << endl;
        cout << endl;
        if (currentLocation->prevCategory == nullptr)
        {
            cout << "Nothing Vsisted Previously" << endl;
        }

        else
        {
            cout << "PreviousLy Visited Categories" << endl;

            Node *temp = currentLocation->prevCategory;
            int count = 1;

            while (temp)
            {
                cout << "Category : " << count << endl;
                cout << endl;
                cout << "Category's Name : " << temp->CategoryName << endl;
                cout << "Category's ID : " << temp->CategoryId << endl;
                cout << "Category's ItemCount : " << temp->ItemsCount << endl;
                cout << "Category's Date : " << temp->CreationDate << endl;
                cout << "Category's ParentID : " << temp->ParentId << endl;

                count++;
                cout << endl;

                temp = temp->prevCategory;
            }

            count = 1;
            temp = currentLocation->nextCategory;

            if (temp == nullptr)
            {
                cout << "No Categories are here for" << endl;
            }
            while (temp)
            {
                cout << "Category : " << count << endl;
                cout << endl;
                cout << "Category's Name : " << temp->CategoryName << endl;
                cout << "Category's ID : " << temp->CategoryId << endl;
                cout << "Category's ItemCount : " << temp->ItemsCount << endl;
                cout << "Category's Date : " << temp->CreationDate << endl;
                cout << "Category's ParentID : " << temp->ParentId << endl;

                count++;
                cout << endl;

                temp = temp->nextCategory;
            }
        }
    }
};

int main(){

    Solution Media;

    Media.OpenCategory(1, "English", "2/3/24", 3 ,4);
    Media.OpenCategory(1, "English", "2/3/24", 3 ,4);
    Media.OpenCategory(1, "English", "2/3/24", 3 ,4);
    Media.OpenCategory(1, "English", "2/3/24", 3 ,4);

    Media.dis();

    Media.GoFarward();

    Media.HistoryNavigation();

    return 0;
}

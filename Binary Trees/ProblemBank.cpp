#include<iostream>
using namespace std;

class Node{
public:
    int patientId;
    string patientName;
    string medicalHistory;
    string admmissionDate;
    int age;
    
    Node * left;
    Node * right;

    Node(int a, string b, string c, string d, int e) : patientId(a), patientName(b), medicalHistory(c), 
                                                                    admmissionDate(d), age(e), left(nullptr), right(nullptr) {};
};

class Solution{
public:
    Node * root;

    Solution() : root(nullptr) {};

    Node * Insert(int a, string b, string c, string d, int e, Node * temp){

        if (temp == nullptr){
            if (root == nullptr) root = new Node(a, b, c, d, e);
            return new Node(a, b, c, d, e);
        }

        else if (a < temp->patientId){
            temp->left = Insert(a, b, c, d, e, temp->left);
        }

        else if (a > temp->patientId){
            temp->right = Insert(a, b, c, d, e, temp->right);
        }
        
        else{
            cout << "Already Found !!!" << endl;
            return temp;
        }

        return temp;
    }

    Node * Search(int id, Node * currNode){
            
        if (!currNode){
            return nullptr;
        }
        else if (id < currNode->patientId){
            return Search(id, currNode->left);
        }
        else if (id > currNode->patientId){
            return Search(id, currNode->right);
        }
        else{
            return currNode;
        }

        return nullptr;

    }

    void Inorder(Node * currNode){

        if (currNode == nullptr){
            return;
        }

        Inorder(currNode->left);
        cout << currNode->patientId << " -> ";
        Inorder(currNode->right);
    }

    void Preorder(Node * currNode){

        if (currNode == nullptr){
            return;
        }

        cout << currNode->patientId << " -> ";
        Preorder(currNode->left);
        Preorder(currNode->right);
    }

    void Postorder(Node * currNode){

        if (currNode == nullptr){
            return;
        }

        Postorder(currNode->left);
        Postorder(currNode->right);
        cout << currNode->patientId << " -> ";
    }

    int FindMaxAge(Node * temp){

        if (temp == nullptr){
            return 0;
        }

        int LeftMaxAge = FindMaxAge(temp->left);
        int RightMaxAge = FindMaxAge(temp->right);

        return max(temp->age, max(LeftMaxAge, RightMaxAge));
    }

    int CountBstNodes(Node * temp, int start, int end){

        if (!temp){
            return 0;
        }
        
        int count = 0;
        if (temp->patientId >= start && temp->patientId <= end){
            count = 1;
        }
        
        if (temp->patientId > start){
            count += CountBstNodes(temp->left, start, end);
        }
        if (temp->patientId < end){
            count += CountBstNodes(temp->right, start, end);
        }

        return count;
    }

    int MinimumValue(Node * temp){

        if (temp->left == nullptr){
            return temp->patientId;
        }

        return MinimumValue(temp->left);
    }
    
    bool CountPairs(Node * BST1, Node * BST2, int complement){
        
        if (!BST2){
            return false;
        }

        else if (BST2->patientId == complement){
            return true;
        }

        else if (BST2->patientId < complement){
            return CountPairs(BST1, BST2->right, complement);
        }

        else if (BST2->patientId > complement){
            return CountPairs(BST1, BST2->left, complement);
        }
    }

    int TotalCount = 0;
    int ActualCountFunction(Node * BST1, Node * BSTHead, int k, int & TotalCount){
        
        if (BST1 == nullptr){
            return 0;
        }
        
        int ans = 0;
        if (CountPairs(BST1, BSTHead, k - BST1->patientId)){
            TotalCount += 1;
        }
        if (BST1 != nullptr){
            if (CountPairs(BST1, BSTHead, k - BST1->patientId)){
                TotalCount += 1;
                ActualCountFunction(BST1->left, BSTHead, k, TotalCount);
                ActualCountFunction(BST1->right, BSTHead, k, TotalCount);
            }
        }
    }

};

int main() {
    Solution BST;

    BST.root = BST.Insert(1, "Ahmad", "Illness A", "2-11-2024", 31, BST.root);
    BST.Insert(2, "Sara", "Injury B", "3-11-2024", 29, BST.root);
    BST.Insert(3, "John", "Illness C", "4-11-2024", 45, BST.root);
    BST.Insert(4, "Alice", "Injury D", "5-11-2024", 50, BST.root);
    BST.Insert(4, "Alice", "Injury D", "5-11-2024", 50, BST.root);


    Node *searchResult = BST.Search(2, BST.root);
    if (searchResult) {
        cout << "Patient found: " << searchResult->patientName << endl;
    } else {
        cout << "Patient not found" << endl;
    }

    cout << "\nInorder Traversal: ";
    BST.Inorder(BST.root);

    cout << "\nPreorder Traversal: ";
    BST.Preorder(BST.root);

    cout << "\nPostorder Traversal: ";
    BST.Postorder(BST.root);

    int maxAge = BST.FindMaxAge(BST.root);
    cout << "\nMaximum Age: " << maxAge << endl;

    return 0;
}

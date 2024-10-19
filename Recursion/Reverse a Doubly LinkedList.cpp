void ReverseRecursively(Node *& currNode, Node *&head){

    if ( currNode->next == nullptr){
        currNode->next = currNode->prev;
        currNode->prev = nullptr;

        head = currNode;
        return;
    }

    Node * temp = currNode->next;
    currNode->next = currNode->prev;
    currNode->prev = temp;

    ReverseRecursively(temp, head);
}

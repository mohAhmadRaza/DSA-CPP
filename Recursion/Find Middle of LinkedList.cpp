int FindMiddle(Node * slow, Node * fast){

    if (fast->next == nullptr){
        return slow->value;
    }else if(fast->next->next == nullptr){
        return slow->next->value;
    }

    return FindMiddle(slow->next, fast->next->next);
}

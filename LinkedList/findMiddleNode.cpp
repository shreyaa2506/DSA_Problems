Node *findMiddle(Node *head) {
    if (head == NULL){
        return head;
    }
    if(head ->next== NULL){
        return NULL;
    }
    Node * slow = head;
    Node* fast = head;
    while(fast!=NULL && (fast ->next)!= NULL){
        slow = slow ->next;
        fast = fast->next->next;
    }
    return slow;
}   
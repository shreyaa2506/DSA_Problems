Node * uniqueSortedList(Node * head) {
    if (head == NULL){
        return NULL;
    }
    Node*curr =head;
    while(curr!=NULL &&curr ->next!=NULL){
        if (curr->data ==curr->next->data){
            Node*temp = curr->next;
            delete(temp);
            curr->next= curr->next->next;
        }
       else{
           curr=curr->next;
       }
            
        
        
    }
    return head;
}
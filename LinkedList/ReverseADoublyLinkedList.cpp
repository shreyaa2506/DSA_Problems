Node* reverseDLL(Node * head)
{
    if (head==NULL || head->next==NULL){
        return head;
    }
    Node*curr = head;
    Node*prev = NULL;
    Node*temp = NULL;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev= curr->next;
        
        curr->next= temp;
        curr= curr->prev;
    }
    return temp->prev;
}

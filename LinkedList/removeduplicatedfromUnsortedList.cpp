Node *removeDuplicates(Node *head)
{
    unordered_map<int,bool>present; 
    if(head== NULL){
        return NULL;
    }
    Node*curr = head;
    Node*prev = NULL;
    while(curr!= NULL){
        if (present[curr->data]==true){
            Node*temp = curr;
            prev ->next = curr->next;
            curr= curr->next;
            delete(temp);
        }
        else{
            present[curr->data]=true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

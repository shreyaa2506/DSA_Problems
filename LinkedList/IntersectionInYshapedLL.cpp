int length(Node*head){
    int len = 0;
    Node*curr = head;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    return len;
}
int intersectPoint(Node* head1, Node* head2)
{
    int len1= length(head1);
    int len2 = length(head2);
   int d = 0;
    Node*ptr1= NULL;
    Node*ptr2= NULL;
    if (len1>len2){
        d=len1-len2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d= len2-len1;
        ptr1= head2;
        ptr2= head1;
    }
    
    while(d--){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
    }
        
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2= ptr2->next;
    }
    return -1;

}


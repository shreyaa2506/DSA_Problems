void insertattail(Node*&tail, Node*curr){
    tail->next = curr;
    tail = curr;
}
// void insertattail(Node*&tail, Node*curr){
//     tail->next=curr;
//     tail=curr;
// }
Node* sortList(Node *head)
{
    Node*zerohead = new Node(-1);
    Node*zerotail = zerohead;
    Node*onehead = new Node(-1);
    Node*onetail = onehead;
    Node*twohead = new Node(-1);
    Node*twotail = twohead;

    Node*temp = head;
    while(temp!=NULL){
        if (temp->data == 0){
            insertattail(zerotail,temp);
        }
        else if(temp->data == 1)
        {
            insertattail(onetail,temp);
        }
        else{
            insertattail(twotail,temp);
        }
        temp = temp->next;
    }
    // if (onehead->next!= NULL){
        zerotail->next = onehead->next;
    
    // else{
    //     zerotail->next = twohead->next;
    // }
    onetail->next = twohead->next;
    twotail->next = NULL;
    head = zerohead->next;

    delete (zerohead);
    delete(onehead);
    delete(twohead);
    return head;
}
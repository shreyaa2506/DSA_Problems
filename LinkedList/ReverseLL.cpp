void reverse(LinkedListNode<int>*&head, LinkedListNode<int>*curr, LinkedListNode<int> *prev){
    if (curr == NULL){
        head = prev;
        return;
    }
    LinkedListNode<int> *forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev;

}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>*curr = head;
    
    LinkedListNode<int>*prev = NULL;
    reverse(head, curr, prev);
    return head;
}
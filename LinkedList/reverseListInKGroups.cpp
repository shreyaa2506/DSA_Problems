Node* kReverse(Node* head, int k) {
   if (head == NULL){
       return NULL;
   } 
   
   int i =0; 
   Node*curr = head;
   Node * prev = NULL;
   Node * next = NULL;
   while (curr != NULL && i < k) {
     next = curr->next;
     curr->next = prev;
     prev = curr;
     curr = next;
     i++; // Write your code here.
   }
   head->next = kReverse(next, k);
   return prev;
}